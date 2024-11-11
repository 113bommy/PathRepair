#include <bits/stdc++.h>
using namespace std;
bool debug = 1;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
long long gcd1(long long x, long long y) {
  long long z = y;
  while (x % y != 0) {
    z = x % y;
    x = y;
    y = z;
  }
  return z;
}
int f[205], be[205], cnt, sz[205], col, rsz[205];
void find(int x) {
  int i = 0, j = f[x];
  for (; j != x && i < n; j = f[j], i++)
    ;
  if (i == n) return;
  cnt++;
  j = x;
  int S = 0;
  while (1) {
    be[j] = cnt;
    j = f[j];
    S++;
    if (j == x) break;
  }
  sz[cnt] = S;
  rsz[cnt] = S;
}
int dfs(int x) {
  if (be[x] != 0) {
    col = be[x];
    return 0;
  }
  return 1 + dfs(f[x]);
}
int main() {
  scanf("%d", &n);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    scanf("%d", f + i);
  }
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    if (be[i] == 0) {
      find(i);
    }
  long long ans = rsz[1];
  for (int i = 2; i <= cnt; i++) {
    ans = ans * rsz[i] / (gcd1(ans, rsz[i]));
  }
  long long ret = ans;
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    if (be[i] == 0) {
      int len = dfs(i);
      while (ret < len) ret += ans;
      ;
    }
  printf("%lld\n", ret);
  return 0;
}
