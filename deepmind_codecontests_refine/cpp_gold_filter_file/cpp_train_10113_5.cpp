#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 39;
int poss[MAXN][MAXN], dp[MAXN];
vector<int> get_z(string &s) {
  int n = s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}
bool ok(string &s, int st, int m) {
  string res = s.substr(st, m + 1) + "#" + s.substr(0, st);
  vector<int> z = get_z(res);
  bool f = 0;
  for (int i : z) f |= i == m + 1;
  return f;
}
void dfs(int l, int r) {
  if (l > r) return;
  poss[l][r] = 1;
  if (!poss[l + 1][r]) dfs(l + 1, r);
  if (!poss[l + 1][r - 1]) dfs(l + 1, r - 1);
  if (!poss[l][r - 1]) dfs(l, r - 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  vector<pair<int, int>> q;
  for (int st = 1; st < n; ++st) {
    int l = -1, r = st;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (ok(s, st, m))
        l = m;
      else
        r = m;
    }
    q.push_back({st, st + l});
  }
  for (auto i : q) dfs(i.first, i.second);
  dp[0] = a;
  for (int r = 1; r < n; ++r) {
    dp[r] = dp[r - 1] + a;
    for (int t = 1; t <= r; ++t)
      if (poss[t][r]) dp[r] = min(dp[r], dp[t - 1] + b);
  }
  cout << dp[n - 1] << "\n";
  return 0;
}
