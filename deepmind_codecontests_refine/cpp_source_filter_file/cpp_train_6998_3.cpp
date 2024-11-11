#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline long long squ(T x) {
  return (long long)x * x;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline T read() {
  T sum = 0, fg = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') fg = -1;
  for (; isdigit(c); c = getchar()) sum = (sum << 3) + (sum << 1) + (c ^ 0x30);
  return fg * sum;
}
const int maxn = 1e5 + 10;
int n, m, K, ALL, dp[2][1 << 8], p[8];
int main() {
  n = read<int>(), m = read<int>(), K = read<int>(), ALL = (1 << K) - 1;
  vector<pair<int, int> > G;
  for (int i = 1; i <= n; i++) {
    int l = read<int>(), r = read<int>();
    G.push_back(make_pair(l, -i)), G.push_back(make_pair(r + 1, i));
  }
  sort(G.begin(), G.end());
  int x = 0, lst = 0, et = 0;
  memset(dp[x], -0x3f, sizeof dp[x]), dp[x][0] = 0;
  for (auto it : G) {
    x ^= 1, memset(dp[x], -0x3f, sizeof dp[x]);
    int pp = 0;
    if (it.second < 0) {
      for (int j = 0; j < K; j++)
        if (!p[j]) {
          pp = j;
          break;
        }
    } else {
      for (int j = 0; j < K; j++)
        if (p[j] == it.second) {
          p[j] = 0, et ^= 1 << j, pp = j;
          break;
        }
    }
    for (int j = 0; j <= ALL; j++) {
      if (j & (ALL ^ et)) continue;
      int par = __builtin_parity(j);
      if (it.second < 0) {
        chkmax(dp[x][j], dp[x ^ 1][j] + (par ? it.first - lst : 0));
        chkmax(dp[x][j ^ (1 << pp)], dp[x ^ 1][j] + (par ? it.first - lst : 0));
      } else {
        chkmax(dp[x][j], dp[x ^ 1][j] + (par ? it.first - lst : 0));
        chkmax(dp[x][j],
               dp[x ^ 1][j ^ (1 << pp)] + ((par ^ 1) ? it.first - lst : 0));
      }
    }
    if (it.second < 0) p[pp] = -it.second, et ^= 1 << pp;
    lst = it.first;
  }
  cout << dp[x][0] << endl;
  return 0;
}
