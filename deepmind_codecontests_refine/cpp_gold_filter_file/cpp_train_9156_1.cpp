// BEGIN CUT HERE
#ifdef _MSC_VER
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <array>
#include <climits>
#include <bitset>
#include <cassert>
#include <unordered_map>
#include <agents.h>
#else
// END CUT HERE
#include <bits/stdc++.h>
// BEGIN CUT HERE
#endif
// END CUT HERE

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define UNIQUE(v) (v).erase(unique(ALL(v)), (v).end())
#define MP make_pair
#define MT make_tuple

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;

const int N = 55;
ll dp[2][55][55][55];

map<string, vector<int>> dpm;
map<string, vector<string>> mp;

vector<int> func(string s){
	int x = 0;
	for (auto c : s){
		rep(i, 4) if (c == "ATGC"[i]) x |= 1 << i;
	}
	return vector<int>(1, x);
}

vector<int> operator+(const vector<int> &lhs, const vector<int> &rhs) {
	vector<int> res = lhs;
	for (auto e : rhs) res.push_back(e);
	return res;
}

vector<int> parse(string s){
	if (s[0] == '[') return func(s);
	auto &res = dpm[s];
	if (!res.empty()) return res;

	auto &vs = mp[s];
	for (auto &s : vs){
		res = res + parse(s);
		if (res.size() > 200) return res;
	}
	return res;
}

int main(){
	int A, T, G, C;
	cin >> A >> T >> G >> C;
	int m;
	cin >> m;
	cin.ignore();

	string str;
	rep(i, m){
		string s;
		getline(cin, s);
		stringstream ss(s);
		string t;
		ss >> t;
		t = t.substr(0, t.size() - 1);
		if (str.empty()) str = t;
		while (ss >> s){
			mp[t].push_back(s);
		}
	}

	auto x = parse(str);

	int n = A + T + G + C;
	if (x.size() != n){
		cout << 0 << endl;
		return 0;
	}
	
	const ll mod = 1e9 + 7;
	dp[0][0][0][0] = 1;

	auto upd = [&](ll &a, ll &b){
		a = (a + b) % mod;
	};

	rep(i, n){
		int cur = i & 1, nxt = !cur;
		rep(j, A + 1) rep(k, T + 1) rep(l, G + 1) dp[nxt][j][k][l] = 0;
		rep(j, A + 1) rep(k, T + 1) rep(l, G + 1){
			if (x[i] & 1) upd(dp[nxt][j + 1][k][l], dp[cur][j][k][l]);
			if (x[i] & 2) upd(dp[nxt][j][k + 1][l], dp[cur][j][k][l]);
			if (x[i] & 4) upd(dp[nxt][j][k][l + 1], dp[cur][j][k][l]);
			if (x[i] & 8) upd(dp[nxt][j][k][l], dp[cur][j][k][l]);
		}
	}
	cout << dp[n & 1][A][T][G] << endl;

}