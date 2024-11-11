#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool read(T &ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
inline void out(int x) {
  if (x > 9) out(x / 10);
  putchar(x % 10 + '0');
}
const int maxn = 5555;
int dp[maxn][maxn];
int g[maxn][maxn];
int w[maxn];
int n;
int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(w[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j * 2 <= n + 1; j++) {
      dp[i][j] = g[i][j] = 0x3f3f3f3f;
    }
  }
  dp[1][1] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j * 2 <= i + 1; j++) {
      dp[i][j] =
          min(dp[i - 2][j - 1] + max(0, w[i - 1] - min(w[i - 2], w[i]) + 1),
              g[i - 2][j - 1] + max(0, w[i - 1] - w[i] + 1));
      g[i][j] = min(g[i - 1][j - 1] + max(0, w[i] - w[i - 1] + 1), g[i - 1][j]);
    }
  }
  for (int i = 1; i * 2 <= n + 1; i++) {
    cout << min(dp[n][i], g[n][i]) << ' ';
  }
  return 0;
}
