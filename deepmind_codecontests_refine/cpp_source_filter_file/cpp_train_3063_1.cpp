#include <bits/stdc++.h>
using namespace std;
inline void R(int &v) {
  v = 0;
  char c = 0;
  int p = 1;
  while (c < '0' || c > '9') {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    v = (v << 3) + (v << 1) + c - '0';
    c = getchar();
  }
  v *= p;
}
int n, q, a[101];
char b[101];
int c[101];
int dp[2000001], val[2000001];
bool comp(const int &a, const int &b) { return a > b; }
int check(int x, int y) {
  if (b[y] == 'b') return 0;
  if (c[y] == 1)
    return x;
  else
    return -x;
}
int dfs(int x, int dep) {
  int minn = 1000000000, maxx = -1000000000;
  for (int i = 0; i < q; ++i) {
    int j = 1 << i;
    if (j & x != 0) {
      if (val[x - j] == 0) dfs(x - j, dep + 1);
      int p = check(a[i + 1], dep);
      minn = min(minn, dp[x - j] + p);
      maxx = max(maxx, dp[x - j] + p);
    }
  }
  if (c[dep] == 1)
    dp[x] = maxx;
  else
    dp[x] = minn;
  val[x] = 1;
  return dp[x];
}
int main() {
  R(n);
  for (int i = 1; i <= n; i++) {
    R(a[i]);
  }
  sort(a + 1, a + n + 1, comp);
  R(q);
  val[0] = 1;
  for (int i = 1; i <= q; i++) {
    cin >> b[i] >> c[i];
  }
  cout << dfs((1 << q) - 1, 1);
  return 0;
}
