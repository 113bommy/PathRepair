#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+5;
int n,a[maxn],head[maxn],cnt,dp[maxn],ans[maxn];
struct node{
	int to,next;
}e[maxn<<1]; 
void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int son,int fa){
	int pos=lower_bound(dp+1,dp+1+n,a[son])-dp;
	int temp=dp[pos];
	dp[pos]=a[son];
	ans[son]=max(ans[fa],pos);
	for(int i=head[son];i;i=e[i].next){
		if(e[i].to!=fa){
			dfs(a[i].to,son);
		}
	}
	dp[pos]=temp;
}
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++){
   	  scanf("%d",&a[i]);
   }
   for(int i=1,u,v;i<=n-1;i++)
   {
   	  scanf("%d %d",&u,&v);
   	  add(u,v);add(v,u);
   }
   memset(dp,0x3f,sizeof(dp));
   dfs(1,0);
   for(int i=1;i<=n;i++)
      printf("%d\n",ans[i]);

return 0;
}
