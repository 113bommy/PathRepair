// 1:10 -> 1:17
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
vector<int>v[100005];
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m; 
	int x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		v[x].pb(y);
	}
	priority_queue<int> pq;
	ll ans = 0;
	for(int i=m-1;i>=0;i--){
		for(auto x:v[m-i])pq.push(x);
		if(!pq.empty()){
			ans+=pq.top();
			pq.pop();
		}
	}
	cout<<ans<<endl;
	return 0;
}
