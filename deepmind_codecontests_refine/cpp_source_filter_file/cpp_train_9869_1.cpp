#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	ll a, b;
	cin >> a >> b;
	ll g = gcd(a, b);
	int cnt = 1;
	for (ll i = 2; i * i <= g; i++) {
		if (g % i == 0) {
			ans++; 
			while (g % i == 0) g /= i;
		}
	}
	if (g > 1) ans++;
	cout << cnt << endl;
	return 0;
}
