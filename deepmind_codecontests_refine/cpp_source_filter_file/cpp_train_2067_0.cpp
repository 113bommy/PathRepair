#include<bits/stdc++.h>
using namespace std;
const int N=2005;
struct edge{
	int to,next;
}e[N*N/2]; 
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int head[N],tot;
int deg[N],a[N],n;
bool vis[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot; deg[y]++;
}
void dfs(int x){
	vis[x]=1;
	for (int i=1;i<=n;i++)
		if (!vis[i]&&gcd(a[x],a[i])>1)
			add(x,i),dfs(i);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		if (!vis[i]) dfs(i);
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
		for (int j=n;j;j--)
			if (!vis[j]&&!deg[j]){
				vis[j]=1;
				printf("%d ",a[j]);
				for (int k=head[j];k;k=e[k].ext)
					deg[e[k].to]--;
				break;
			}
} 
