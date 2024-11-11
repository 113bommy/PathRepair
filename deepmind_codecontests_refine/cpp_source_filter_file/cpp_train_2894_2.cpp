#include<bits/stdc++.h>
using namespace std;
int n,q;
int ver[200005],next[200005],head[200005];
int w[200005],l[200005],c[200005];
int x,y;
void dfs(int s) {
	for(int i=head[s];i;i=next[i]) {
		l[ver[i]]+=l[s];
		dfs(ver[i]);
	}
	//cout<<s<<" "<<l[s]<<endl;
}
int main() {
	cin>>n>>q;
	for(int i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		ver[i]=y;
		next[i]=head[x];
		head[x]=i;
	}
	for(int i=1;i<=q;i++) {
		scanf("%d%d",&w[i],&c[i]);
		l[w[i]]+=c[i];
	}
	dfs(1);
	for(int i=1;i<=n;i++) cout<<l[i]<<" ";
	return 0;
}