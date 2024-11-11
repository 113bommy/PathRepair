#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;
	vector<ll> v(n);
	for(ll i=0; i<n; i++){
		cin >> v[i];
		v[i] -= (i+1);
	}
	sort(v.begin(), v.end());
	ll minima = v[n/2]; ll ans = 0;
	for(auto x:v){
		ans += abs(x-minima);
	}
	cout << ans;
	return 0;
}