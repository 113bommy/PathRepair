#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
template <typename T>
inline void cmax(T &x, T y) {
  if (x < y) x = y;
}
int n, pre[3][MAXN], dp[MAXN];
long long a[3][MAXN];
map<long long, int> lst;
map<int, int> mp[MAXN];
int DP(int i, int j) {
  if (i < 0 || j < 0) return -1;
  if (i == j) return dp[i];
  if (mp[i].count(j)) return mp[i][j];
  int ret = dp[min(i, j)];
  if (i > j) {
    cmax(ret, DP(pre[0][i] - 1, j) + 1);
  } else {
    cmax(ret, DP(i, pre[1][j] - 1) + 1);
  }
  return mp[i][j] = ret;
}
void init() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(a[0][i]);
  }
  for (int i = 1; i <= n; ++i) {
    read(a[1][i]);
  }
}
void solve() {
  for (int i = 1; i <= n; ++i) {
    a[0][i] += a[0][i - 1];
    a[1][i] += a[1][i - 1];
    a[2][i] = a[0][i] + a[1][i];
  }
  for (int t = 0; t <= 2; ++t) {
    lst.clear();
    lst[0] = 0;
    for (int i = 1; i <= n; ++i) {
      pre[t][i] = pre[t][i - 1];
      if (lst.count(a[t][i])) {
        pre[t][i] = lst[a[t][i]] + 1;
      }
      lst[a[t][i]] = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1];
    if (pre[2][i]) {
      cmax(dp[i], dp[pre[2][i] - 1] + 1);
    }
    cmax(dp[i], DP(pre[0][i] - 1, i) + 1);
    cmax(dp[i], DP(i, pre[1][i] - 1) + 1);
  }
  printf("%d\n", dp[n]);
}
int main() {
  init();
  solve();
  return 0;
}
