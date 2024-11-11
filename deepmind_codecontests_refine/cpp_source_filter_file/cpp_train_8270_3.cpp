#include <bits/stdc++.h>
using namespace std;
void print();
template <typename T, typename... Args>
void print(T x, Args... args);
void solve() {
  int r, g;
  cin >> r >> g;
  const int M = 1e9 + 7;
  int h = 0;
  for (int add = 1 << 10; add; add >>= 1)
    if ((h + add) * (h + add + 1) <= (r + g) * 2) h += add;
  if (r > g) swap(r, g);
  vector<vector<int>> dp(2, vector<int>(r + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= h; ++i) {
    auto &cur = dp[i & 1];
    auto &prv = dp[(i & 1) ^ 1];
    fill(cur.begin(), cur.end(), 0);
    for (int j = 0; j <= r; ++j) {
      cur[j] = (cur[j] + prv[j]) % M;
      if (j + i <= r) cur[j + i] = (cur[j + i] + prv[j]) % M;
    }
  }
  long long res = 0;
  h = h * (h + 1) / 2;
  for (int i = 0; i <= r; ++i)
    if (i <= h && i + g >= h) {
      res = (res + dp[h & 1][i]) % M;
    }
  cout << res << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  while (t--) solve();
  return 0;
}
void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
  if (sizeof...(args)) {
    cout << x << ' ';
    print(args...);
  } else {
    cout << x << '\n';
  }
}
