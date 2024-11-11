#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 100005;
long long n;
struct qq {
  long long x, y, z, last;
} e[N];
long long num, last[N];
long long k[N], b[N], f[N];
int d[N];
void init(long long x, long long y, long long z) {
  num++;
  e[num].x = x;
  e[num].y = y;
  e[num].z = z;
  e[num].last = last[x];
  last[x] = num;
}
long long pow(long long x, long long y) {
  if (y == 1) return x;
  long long lalal = pow(x, y >> 1);
  lalal = lalal * lalal % MOD;
  if (y & 1) lalal = lalal * x % MOD;
  return lalal;
}
long long Q[N];
void dfs(long long x) {
  Q[++Q[0]] = x;
  for (long long u = last[x]; u != -1; u = e[u].last) {
    long long y = e[u].y;
    if (y == f[x]) continue;
    f[y] = x;
    dfs(y);
  }
}
int main() {
  num = 0;
  memset(last, -1, sizeof(last));
  scanf("%I64d", &n);
  for (long long u = 1; u < n; u++) {
    long long x, y, z;
    scanf("%I64d%I64d%I64d", &x, &y, &z);
    x++;
    y++;
    init(x, y, z);
    init(y, x, z);
    k[x]++;
    k[y]++;
    d[x]++;
    d[y]++;
    b[x] += z;
    b[y] += z;
  }
  dfs(1);
  for (long long u = Q[0]; u >= 2; u--) {
    long long x = Q[u];
    if (d[x] == 1) continue;
    long long tmp = pow(k[x], MOD - 2);
    k[f[x]] = (k[f[x]] - tmp) % MOD;
    b[f[x]] = (b[f[x]] + b[x] * tmp % MOD) % MOD;
  }
  long long ans;
  ans = (b[1] * pow(k[1], MOD - 2) % MOD + MOD) % MOD;
  printf("%I64d\n", ans);
  return 0;
}
