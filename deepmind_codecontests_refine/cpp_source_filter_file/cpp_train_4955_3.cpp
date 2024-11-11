#include <bits/stdc++.h>
using namespace std;
int const N = 1e6 + 4, NN = 2e5 + 3, inf = 1e9 + 7;
long long const md = 998244353;
long long a[N], b[N], n, l, r, k, m, x1, bbp, kk, sz, ans;
long long dp[105][60005], q, qq;
char ch;
bool us[N];
map<string, long long> mp;
string second, ss, t;
vector<pair<long long, long long> > ot;
vector<long long> v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> second >> t;
  for (int i = 0; i < second.size(); i++) {
    if (t[i] > second[i]) return cout << -1, 0;
    ss += second[i];
  }
  cout << ss;
  return 0;
}
