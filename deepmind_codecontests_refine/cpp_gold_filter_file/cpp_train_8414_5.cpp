#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2005];
ll adj[2005][2005];
ll radj[2005][2005];
ll parent[2005];
ll n;
bool bfs(){
	bool visited[2005];
	memset(visited,0,sizeof(visited));
	queue <ll> q;
	q.push(0); visited[0]=1;
	parent[0]=-1;
	
	while(!q.empty()){
		ll u=q.front(); q.pop();
		for(ll v=0; v<=n+1;v++){
			if(!visited[v] && radj[u][v]>0){
				q.push(v);
				parent[v]=u;
				visited[v]=1;
			}
		}
	}
	return (visited[n+1]==true);
}

ll maxflow(){
	for(ll u=0;u<=n+1;u++)
		for(ll v=0;v<=n+1;v++)
			radj[u][v]=adj[u][v];
			
	ll max_flow=0;
	ll u,v;
	while(bfs()){
		ll path_flow= INT_MAX;
		for(v=n+1;v!=0; v=parent[v]){
			u=parent[v];
			path_flow=min(path_flow,radj[u][v]);
		}
		for(v=n+1; v!=0; v=parent[v]){
			u=parent[v];
			radj[u][v]-= path_flow;
			radj[v][u]+= path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}
int main(){
	cin >> n;
	ll x=0;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]>0) x+=a[i];
	}
	for(ll i=1;i<=n;i++){
		if(a[i]>0) adj[i][n+1]=a[i];
		else if(a[i]<=0) adj[0][i]=-a[i];
		for(ll j=i*2;j<=n;j+=i){
			adj[i][j]=INT_MAX;
			//adj[j][i]=INT_MAX;
		}
	}
	cout << x-maxflow() << endl;
}