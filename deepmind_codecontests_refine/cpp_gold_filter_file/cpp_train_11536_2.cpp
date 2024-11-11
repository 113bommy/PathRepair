#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define   ull unsigned long long 
#define mp make_pair
#define pb push_back
const int MAX=2e5+9;
const long long mod=1e9+7;
using namespace std;
vector<int>adj[MAX];
int d[MAX];
int deg[MAX];
void dfs(int x, int y){
	d[x]=y;
	for(int i=0;i<adj[x].size();i++){
		if(d[adj[x][i]]==0){
			dfs(adj[x][i] , y+1);
			if(deg[adj[x][i]]%2==0){
				deg[x]++;
				cout<<x+1<<" "<<adj[x][i]+1<<"\n";
			}
			else{
				deg[adj[x][i]]++;
				cout<<adj[x][i]+1<<" "<<x+1<<"\n";
			}
		}
		else if(d[adj[x][i]]>d[x]){
			deg[x]++;
			cout<<x+1<<" "<<adj[x][i]+1<<"\n";
		}

	}
}

int main(){
	int n , m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x, y;
		cin>>x>>y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	if(m%2){
		cout<<-1;
	}
	else
	{
		dfs(0, 1);
	}
}