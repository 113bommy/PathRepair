#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> d;
vector<bool> visited;
vector<int> r;
int res;
int inf=1e18;
int N,M,R;



void dfs(int i,int pre,int dis){
	
	if(i==R){
		res=min(res,dis);
		return;}	

	for(auto&& w:r){
	if(visited[w])continue;
	visited[w]=true;
		if(pre==-1)dfs(i+1,w,0);
		else dfs(i+1,w,dis+d[w][pre]);
	visited[w]=false;
	}
	return;	
}


signed main(){
	cin>>N>>M>>R;
	r.resize(R);
	for(auto&& w:r){cin>>w;w--;}
	d.resize(N,vector<int>(N,inf));
	visited.resize(N,false);
	for(int i=0;i<N;i++){
		d[i][i]=0;
	}
	for(int i=0;i<M;i++){
		int a,b,c;cin>>a>>b>>c;a--;b--;
		d[a][b]=d[b][a]=c;


	}
	for(int i=0;i<N;i++){
	for(int j=0;j<N;j++){
	for(int k=0;k<N;k++){
		d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
}
}	
}
	res=inf;
	dfs(0,-1,0);
	cout<<res<<endl;

}
