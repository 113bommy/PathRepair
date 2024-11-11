#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
template <typename T, typename T2>
inline void _max(T &a, T2 b) {
  a = max((T)a, (T)b);
}
template <typename T, typename T2>
inline void _min(T &a, T2 b) {
  a = min((T)a, (T)b);
}
int n;
const int MAX = 707;
int a[MAX];
int dp[MAX][MAX][2];
int mx[MAX][MAX];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void clear() {
  memset(dp, -1, sizeof(dp));
  memset(mx, 0, sizeof(mx));
}
void read() {
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}
int getDp(int l, int r, int dir) {
  if (l == r) return 1;
  if (dp[l][r][dir] == -1) {
    int res = 0;
    int root = dir ? l : r;
    for (int i = l; i <= r; i++) {
      if (root == i) continue;
      if (mx[root][i] == 0) continue;
      int tres = getDp(l + (root == l), i, 0) && getDp(i, r - (root == r), 1);
      res |= tres;
      if (res) break;
    }
    dp[l][r][dir] = res;
  }
  return dp[l][r][dir];
}
void solve() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) mx[i][j] = mx[j][i] = gcd(a[i], a[j]) != 1;
  int res = 0;
  for (int i = 0; i < n; i++) res |= getDp(0, i, 0) && getDp(i, n - 1, 1);
  printf(res ? "Yes\n" : "No\n");
}
int main() {
  while (scanf("%d", &n) == 1) {
    clear();
    read();
    solve();
    return 0;
  }
  return 0;
}
