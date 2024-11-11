#include <bits/stdc++.h>
using namespace std;
long long f[25], ny[40], ff[40];
int vis[2100000];
int n;
long long s;
long long ans = 0;
void pre() {
  ny[0] = ny[1] = ff[0] = ff[1] = 1;
  for (int i = 2; i < 39; i++) {
    long long t = 1000000007 / i, k = 1000000007 % i;
    ff[i] = i * t % 1000000007 * t % 1000000007 * ff[k] % 1000000007 * ff[k] %
            1000000007;
    ny[i] = ny[i - 1] * ff[i] % 1000000007;
  }
}
long long C(long long a, long long b) {
  if (a < b) return 0;
  long long cur = 1;
  for (int i = 0; i < b; i++) cur = cur * ((a - i) % 1000000007) % 1000000007;
  cur = cur * ny[b] % 1000000007;
  return cur;
}
void dfs(int st, int sum, int zf) {
  if (vis[st]) return;
  vis[st] = 1;
  long long cur =
      (zf * C(s - sum + n - 1, n - 1) % 1000000007 + 1000000007) % 1000000007;
  ans = (ans + cur) % 1000000007;
  if (st == ((1 << n) - 1)) return;
  for (int i = 0; i < n; i++)
    if ((st & (1 << i)) == 0) {
      dfs(st | (1 << i), sum + f[i] + 1, -zf);
    }
}
int main() {
  pre();
  scanf("%d%I64d", &n, &s);
  for (int i = 0; i < n; i++) scanf("%I64d", &f[i]);
  dfs(0, 0, 1);
  printf("%I64d\n", ans);
}
