#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

#define rep(i,n) for(int i = 0;i < n;i++)
#define ull unsigned long long
#define int ull
#define ll int


ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1)res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

const int B = 1e9 + 7;
const int mod = 0xffffffffffffffffui64;

signed main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int> hash(n + 1, 0);
	hash[1] = s[0];
	for (int i = 2; i <= s.size(); i++) {
		hash[i] = (hash[i - 1] * B + s[i - 1]) % mod;
	}

	int l = 0, r = 1;
	set<int> se;
	rep(i, m) {
		string t;
		cin >> t;
		if (t == "R++") {
			r++;
		}
		if (t == "L++") {
			l++;
		}
		if (t == "R--") {
			r--;
		}
		if (t == "L--") {
			l--;
		}
		int val = (hash[r] - hash[l] * mod_pow(B, r - l, mod) + mod) % mod;
		se.insert(val);
	}
	cout << se.size() << endl;

	return 0;
}