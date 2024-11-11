#include <bits/stdc++.h>
using namespace std;
pair<int, int> ff[1200021];
int l[2002];
int b[1200021];
int t[4800084];
void build(int v, int tl, int tr) {
  if (tl == tr - 1) {
    t[v] = b[tl];
    return;
  }
  int mid = (tr + tl) / 2;
  build(v * 2, tl, mid);
  build(v * 2 + 1, mid, tr);
  t[v] = min(t[v * 2], t[v * 2 + 1]);
}
bool check(int v, int tl, int tr, int l, int r, int x) {
  if (l >= r) return false;
  if (tl == l && tr == r) return (t[v] < x);
  int mid = (tl + tr) / 2;
  return (check(v * 2, tl, mid, l, min(r, mid), x) |
          check(v * 2 + 1, mid, tr, max(l, mid), r, x));
}
vector<int> p[2002];
long long dp[2002][2002];
const long long m = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  if (n == 2) {
    cout << "1 1";
    return 0;
  }
  int nn = n * (n - 1) / 2 + 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int a;
      cin >> a;
      ff[a] = {i, j};
    }
  }
  vector<int> fs;
  for (int i = 1; i < nn; ++i) {
    if (!l[ff[i].first]) {
      l[ff[i].first] = i;
      fs.push_back(i);
    }
    if (!l[ff[i].second]) {
      l[ff[i].second] = i;
      fs.push_back(i);
    }
    b[i] = min(l[ff[i].first], l[ff[i].second]);
  }
  fs.push_back(nn);
  build(1, 1, nn);
  int n2 = fs.size() - 1;
  for (int i = 0; i < n2; ++i) {
    if (i && fs[i] == fs[i - 1]) continue;
    for (int j = i + 2; j <= n2; ++j) {
      int c = j - i;
      int csz = c * (c - 1) / 2;
      if (fs[i] + csz > fs[j]) continue;
      if (!check(1, 1, nn, fs[i], fs[i] + csz, fs[i])) {
        p[i].push_back(c - 1);
      }
    }
  }
  dp[n2][n] = 1;
  for (int i = n2; i > 0; --i) {
    for (int k = 1; k <= n; ++k) {
      dp[i - 1][k] = (dp[i - 1][k] + dp[i][k]) % m;
      for (auto& x : p[i - 1]) {
        if (k + x <= n) dp[i - 1][k] = (dp[i - 1][k] + dp[i + x][k + x]) % m;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << dp[0][i] << ' ';
  }
}
