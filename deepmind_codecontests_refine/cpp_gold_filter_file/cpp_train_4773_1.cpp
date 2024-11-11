#include<bits/stdc++.h>
using namespace std;
#define N 200005
vector<int> v[N];
int fa[N],du[N],sg[N];
int n;
void calc(int u){
	sort(v[u].begin(),v[u].end());
	sg[u]=0;
	for(int i:v[u]) i==sg[u]? sg[u]++:0;
}
void tp(int u){
	calc(u);
	du[fa[u]]--;du[u]=-1;
	v[fa[u]].push_back(sg[u]);
	if(du[fa[u]]==0) tp(fa[u]);
}
vector<int> temp;
void DFS(int u,int top){
	temp.push_back(sg[u]);du[u]=-1; 
	if(fa[u]!=top) DFS(fa[u],top);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&fa[i]),du[fa[i]]++;
	for(int i=1;i<=n;i++)
		if(du[i]==0) tp(i);
	for(int i=1;i<=n;i++)
		if(du[i]==1) calc(i);
	for(int i=1;i<=n;i++)
		if(du[i]==1){
			DFS(i,i);
			sort(temp.begin(),temp.end());
			if(temp[0]==temp[temp.size()-1]&&temp.size()%2==1)
				return puts("IMPOSSIBLE"),0;
			temp.clear();
		}
	return puts("POSSIBLE"),0;
}