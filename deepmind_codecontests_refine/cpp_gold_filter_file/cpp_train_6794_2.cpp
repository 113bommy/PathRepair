#include <bits/stdc++.h>
using namespace std;
const int maxp = 22;
const long double EPS = 1e-18;
const long long INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5 + 1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> distribution;
long long rnd(long long l, long long r) {
  return distribution(rng) % (r - l + 1) + l;
}
const int HS = 3;
int mod[HS];
struct custom_hash {
  int val[HS];
  custom_hash() { fill(val, val + HS, 0); }
  custom_hash(long long x) {
    for (int i = 0; i < HS; i++) val[i] = (x % mod[i] + mod[i]) % mod[i];
  }
  custom_hash operator+(custom_hash x) {
    custom_hash res;
    res.val[0] = (val[0] + x.val[0]) % mod[0];
    res.val[1] = (val[1] + x.val[1]) % mod[1];
    res.val[2] = (1LL * val[2] * x.val[2]) % mod[2];
    return res;
  }
  bool operator==(const custom_hash &x) const {
    for (int i = 0; i < HS; i++)
      if (val[i] != x.val[i]) return false;
    return true;
  }
};
custom_hash s, val[N], sets[10][10];
int ans = 0;
int k;
vector<int> curr;
void solve(int st) {
  if (st == k) {
    custom_hash tot;
    for (int i = 1; i <= k; i++) tot = tot + sets[i][curr[i - 1]];
    if (tot == s) ans++;
    return;
  }
  for (int i = 1; i <= st + 1; i++) {
    curr.push_back(i);
    solve(st + 1);
    curr.pop_back();
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m >> k;
  mod[0] = MOD;
  mod[1] = 998244353;
  mod[2] = rnd(1e8, 1e9);
  int i, j;
  vector<vector<pair<int, int> > > a(n + 1, vector<pair<int, int> >());
  for (i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    a[x].push_back({z, y});
  }
  for (i = 1; i <= n; i++) val[i] = custom_hash(rnd(1, MOD));
  for (i = 1; i <= n; i++) {
    s = s + val[i];
    sort((a[i]).begin(), (a[i]).end());
    for (j = 0; j < a[i].size(); j++)
      sets[(int)a[i].size()][j + 1] =
          sets[(int)a[i].size()][j + 1] + val[a[i][j].second];
  }
  solve(0);
  cout << ans;
}
