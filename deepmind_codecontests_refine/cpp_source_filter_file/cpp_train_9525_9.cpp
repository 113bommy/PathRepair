#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c ^ 48);
    c = getchar();
  }
  return f * x;
}
bitset<2000> vis[2000], s[2000], noleft, sum;
long long f[2000], n, cnt;
inline long long find(long long x) {
  return f[x] == x ? f[x] : f[x] = find(f[x]);
}
signed main() {
  n = read();
  for (long long i = 1; i < +n; i++) f[i] = i;
  for (long long i = 1; i <= n; i++) {
    long long k = read();
    for (long long j = 1; j <= k; j++) {
      long long v = read();
      vis[i][v] = 1;
    }
  }
  long long u = 0, v = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      sum = vis[i] & vis[j];
      if (sum.count() == 2) {
        u = 0, v = 0;
        for (long long k = 1; k <= n; k++)
          if (sum[k]) {
            if (u == 0)
              u = k;
            else
              v = k;
          }
        long long fu = find(u), fv = find(v);
        if (fu != fv) {
          f[fu] = fv;
          cnt++;
          cout << u << ' ' << v;
          puts("");
          s[u][v] = s[v][u] = s[u][u] = s[v][v] = 1;
          noleft[u] = noleft[v] = 1;
        }
      }
    }
  }
  if (cnt == 0) {
    for (long long i = 2; i <= n; i++) {
      cout << 1 << ' ' << i;
      puts("");
    }
    return 0;
  }
  if (cnt == 1) {
    for (long long i = 1; i <= n; i++)
      if (vis[i].count() < n) {
        for (long long j = 1; j <= n; j++) {
          if (!noleft[j]) {
            if (vis[i][j] == 1)
              cout << u << ' ' << j;
            else
              cout << v << ' ' << j;
            puts("");
          }
        }
        break;
      }
    return 0;
  }
  for (long long i = 1; i <= n; i++) {
    if (!noleft[i]) {
      long long MIN = (1e9 + 7);
      for (long long j = 1; j <= n; j++) {
        if (vis[j][i] && (vis[j] & noleft).count() < MIN) {
          sum = (vis[j] & noleft);
          MIN = sum.count();
        }
      }
      for (long long j = 1; j <= n; j++) {
        if (sum[i] && s[j] == sum) {
          cout << i << ' ' << j;
          puts("");
          break;
        }
      }
    }
  }
  return 0;
}
