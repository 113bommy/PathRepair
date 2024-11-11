#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

vector<ll> get_div(ll n){
	vector<ll> div;
	for(ll i(1);i*i<=n;++i){
		if(s%i == 0){
			div.push_back(i);
			if(i * i != n) div.push_back(n / i);
		}
	}
	sort(div.begin(),div.end());
	return div;
}

int main(){
	int n,k;
	cin >> n >> k;
	vector<ll> a(n);
	ll s(0);
	rep(i,n){
		cin >> a[i];
		s+=a[i];
	}
	vector<ll> div = get_div(s);
	ll ans(0);
	rep(i,div.size()){
		ll d = div[i];
		auto b = a;
		ll s1(0),s2(0);
		rep(j,n){
			b[j] %= d;
			s1 += d-b[j];
		}
		sort(b.begin(),b.end());
		rep(j,n){
			s2 += b[j];
			s1 -= d-b[j];
			if(s1 == s2) break;
		}
		if(s2 <= k && ans < d) ans = d;
	}
	cout << ans << endl;
	return 0;
}