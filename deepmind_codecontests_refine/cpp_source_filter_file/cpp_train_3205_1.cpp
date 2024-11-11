#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin>>n>>m;
	vector<int> h(n+1);
	for (int i = 1; i <= n; ++i){
		cin>>h[i];
	}
	vector<int> ma(n+1);
	for (int i = 0; i < m; ++i){
		int a, b;
		cin>>a>>b;
		ma[a] = max(ma[a],h[b])
		ma[b] = max(ma[b],h[a]);
	}
	int res = 0;
	for (int i = 1; i <= N; ++i){
		res += h[i] > ma[i];
	}
	cout<<res<<endl;
	return 0; 
}