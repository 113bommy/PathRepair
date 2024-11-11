#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n;
  	cin >> n;
  	vector<ll> a(n), b;
  	for(auto& i : a) cin >> i;
  	b = a;
  	sort(b.rbegin(), b.rend());
    for(auto& i : a) cout << (i != b[0] ? b[0] : b[1]) << endl;
}