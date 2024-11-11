nclude<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,now,vi[N],fa[N],vis[N],v[N<<1],deep[N],nex[N<<1],head[N];
void addedges(int x,int y){
	nex[++now]=head[x];
	head[x]=now,v[now]=y;
}
vector<int>b[N];
void dfs(int x){
	deep[x]=deep[fa[x]]+1;
	for(int i=head[x];i;i=nex[i])
		if(v[i]!=fa[x])	fa[v[i]]=x,dfs(v[i]);
	b[deep[x]].push_back(x);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		addedges(x,y),addedges(y,x);
	}
	dfs(1);
	for(int i=n;i;i--){
		int si=b[i].size();
		for(int j=0;j<si;j++){
			int k=b[i][j];
			if(!vis[k]){
				if(vis[fa[k]]||k==1){
					puts("First");
					return 0;
				}
				vis[fa[k]]=1;
			}
		}
	}
	puts("Second");
	return 0;
}