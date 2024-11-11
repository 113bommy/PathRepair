#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char p = getchar();
  while (!isdigit(p)) {
    if (p == '-') f = -1;
    p = getchar();
  }
  while (isdigit(p)) x = (x << 3) + (x << 1) + (p ^ 48), p = getchar();
  return x * f;
}
const long long maxn = 1e5 + 5;
long long n, x, y, z, f[maxn][3], vis[maxn], ll, rr, a[maxn];
map<long long, long long> Map;
inline long long mex(long long a, long long b, long long c) {
  vis[a] = 1;
  vis[b] = 1;
  vis[c] = 1;
  long long ret;
  for (long long i = 0;; i++)
    if (!vis[i]) {
      ret = i;
      break;
    }
  vis[a] = 0;
  vis[b] = 0;
  vis[c] = 0;
  return ret;
}
inline long long get(long long x, long long opt) {
  if (x <= rr) return f[x][opt];
  return f[(x - ll) % (rr - ll) + ll][opt];
}
inline long long max(long long a, long long b) {
  if (a < b) return b;
  return a;
}
inline long long solve() {
  Map.clear();
  for (long long i = 1;; i++) {
    f[i][0] =
        mex(f[max(0, i - x)][0], f[max(0, i - y)][1], f[max(0, i - z)][2]);
    f[i][1] = mex(f[max(0, i - x)][0], f[max(0, i - z)][2], 10);
    f[i][2] = mex(f[max(0, i - x)][0], f[max(0, i - y)][1], 10);
    long long now = 1, ret = 0;
    ret += f[i][0];
    for (long long j = 2; j <= x; j++)
      now *= 4, ret += now * f[max(i - j, 0)][0];
    for (long long j = 1; j <= y; j++)
      now *= 4, ret += now * f[max(i - j, 0)][1];
    for (long long j = 1; j <= z; j++)
      now *= 4, ret += now * f[max(i - j, 0)][2];
    if (Map[ret]) {
      rr = i;
      ll = Map[ret];
      break;
    }
    Map[ret] = i;
  }
  long long sum = 0, num = 0;
  for (long long i = 1; i <= n; i++) a[i] = read(), sum ^= get(a[i], 0);
  if (sum == 0) return 0;
  for (long long i = 1; i <= n; i++) {
    sum ^= get(a[i], 0);
    sum ^= get(max(a[i] - x, 0), 0);
    if (sum == 0) num++;
    sum ^= get(max(a[i] - x, 0), 0);
    sum ^= get(max(a[i] - y, 0), 0);
    if (sum == 0) num++;
    sum ^= get(max(a[i] - y, 0), 0);
    sum ^= get(max(a[i] - z, 0), 0);
    if (sum == 0) num++;
    sum ^= get(max(a[i] - z, 0), 0);
    sum ^= get(a[i], 0);
  }
  return num;
}
signed main() {
  long long t = read();
  while (t--)
    n = read(), x = read(), y = read(), z = read(), cout << solve() << endl;
  return 0;
}
