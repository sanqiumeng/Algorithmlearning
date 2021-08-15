#include<stdio.h> 
int a[101],f[101][101];
int max(int x,int y){
	return x>y?x:y ;
}
int min(int x,int y)
{
	return x<y?x:y ;
}
int dfs(int l,int r,int op)
{
	if(l>r) return;
	if(op==1){
		f[l][r]=max(dfs(l+1,r,0)+a[l],dfs(l,r-1,0)+a[r]);
	}
	else{
		f[l][r]=-min(dfs(l+1,r,1)+a[l],dfs(l,r-1,1)+a[r]); 
	}
	return f[l][r];
}
int main()
{
	int i,n;
	scanf("%d ",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	dfs(0,n-1,1);
	printf("%d",f[0][n-1]);
	return 0;
}
