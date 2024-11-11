#include <bits/stdc++.h>
const int N = 20;
const int M = 2e5 + 10;
const int INF = 1e9 + 8;
using namespace std;
int n, l;
int f[M];
int dp[N + 1][1 << N];
void init() {
  char s[N + 1];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    f[i] = 0;
    for (int j = 0; s[j]; j++) f[i] = (f[i] << 1) + s[j] - '0';
  }
  l = strlen(s);
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
}
void update(int &x, int y) { x = x < y ? x : y; }
inline int suf(int x, int k) { return x & ((1 << k) - 1); }
inline int pre(int x, int k) { return x >> (l - k); }
void work() {
  int tot = n * l;
  for (int i = 2; i <= n; i++) {
    for (int j = l; j >= 0; j--)
      if (suf(f[i - 1], j) == pre(f[i], j)) {
        tot -= j;
        int minx = INF;
        for (int k = 0; k <= l; k++) {
          update(minx, dp[k][pre(f[i], k)] + (l - k));
        }
        for (int k = 0; k <= l; k++) {
          update(dp[k][suf(f[i - 1], k)], minx - (l - j));
        }
        break;
      }
  }
  int ans = tot;
  for (int i = 0; i <= l; i++) {
    for (int j = (1 << i) - 1; j >= 0; j--) {
      ans = min(ans, tot + dp[i][j]);
    }
  }
  printf("%d\n", ans);
}
int main() {
  init();
  work();
  return 0;
}
