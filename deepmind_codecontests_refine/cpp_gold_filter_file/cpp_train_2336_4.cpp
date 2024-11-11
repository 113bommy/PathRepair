#include <bits/stdc++.h>
using namespace std;
ifstream fin("D.in");
const long long INF = 2e18;
struct Friend {
  int x, k, m, bitmask;
} f[105];
long long dp[1 << 21];
int n, m, b;
struct cmp {
  bool operator()(const Friend &A, const Friend &B) const { return A.k > B.k; }
};
void Read() {
  cin >> n >> m >> b;
  for (int i = 0; i < n; ++i) {
    cin >> f[i].x >> f[i].k >> f[i].m;
    int a;
    f[i].bitmask = 0;
    for (int j = 0; j < f[i].m; ++j) {
      cin >> a;
      f[i].bitmask |= (1 << (a - 1));
    }
  }
}
void Solve() {
  sort(f, f + n, cmp());
  for (int i = 0; i < (1 << m); ++i) dp[i] = INF;
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (1 << m); ++j) {
      if (j == 0)
        dp[j | f[i].bitmask] =
            min(dp[j | f[i].bitmask], 1LL * f[i].k * b + f[i].x);
      else
        dp[j | f[i].bitmask] = min(dp[j | f[i].bitmask], dp[j] + f[i].x);
    }
  }
}
void Write() {
  if (dp[(1 << m) - 1] == INF)
    cout << -1;
  else
    cout << dp[(1 << m) - 1];
  cout << '\n';
}
int main() {
  Read();
  Solve();
  Write();
  fin.close();
  return 0;
}
