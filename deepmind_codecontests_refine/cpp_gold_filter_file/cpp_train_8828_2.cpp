#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,fix[100005],length[100005],ans;
vector<int>V[100005];
int go(int u){
	
	if(fix[u]) return length[u];
	fix[u]=1;
	for(int i=0;i<V[u].size();i++){
		length[u]=max(length[u],go(V[u][i])+1);
	}
	return length[u];
}
int main(){
	cin>>n>>m;
	for(k=1;k<=m;k++){
		cin>>u>>v;
		V[v].push_back(u);
	}
	
	for(k=1;k<=n;k++){
		if(fix[k]==0){
			go(k);
		}
		ans=max(ans,length[k]);
	}
	cout<<ans;
	
}