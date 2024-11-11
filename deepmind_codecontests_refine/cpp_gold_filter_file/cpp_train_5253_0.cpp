#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100005], t, b, g, d1[5][5][25], v[1000005], ans;
char c, ch[100005];
struct node {
  long long p[1000005][5], q;
  void ins(long long x) {
    long long y = 0;
    for (long long i = x; i <= min(x + b - 1, m); i++) {
      y = (p[y][a[i]] ? p[y][a[i]] : (p[y][a[i]] = ++q));
      if (v[y] == 0) {
        v[y] = 1;
        d1[a[x]][a[i]][i - x + 1]++;
      }
    }
    return;
  }
} d;
struct nd2 {
  long long p[5][5];
} sd;
nd2 mul(nd2 x, nd2 y, nd2 &z) {
  memset(z.p, 63, sizeof(z.p));
  for (long long i = 1; i <= 4; i++) {
    for (long long j = 1; j <= 4; j++) {
      for (long long k = 1; k <= 4; k++) {
        z.p[i][j] = min(z.p[i][j], x.p[i][k] + y.p[k][j]);
      }
    }
  }
  return z;
}
nd2 npw(nd2 x, long long y, nd2 &z) {
  memset(z.p, 0, sizeof(z.p));
  long long k = 1;
  y--;
  while (y) {
    if (y & k) {
      mul(x, z, z);
      y ^= k;
    }
    mul(x, x, x);
    k <<= 1;
  }
  return z;
}
long long pow(long long x, long long y) {
  long long r = 1, k = 1;
  while (y) {
    if (y & k) {
      r *= x;
      y ^= k;
    }
    x *= x;
    k <<= 1;
  }
  return r;
}
inline long long chk(long long x) {
  nd2 y;
  npw(sd, x, y);
  for (long long i = 1; i <= 4; i++)
    for (long long i = 1; i <= 4; i++) {
      for (long long j = 1; j <= 4; j++) {
        if (y.p[i][j] < n) {
          return 1;
        }
      }
    }
  return 0;
}
signed main() {
  scanf("%lld\n", &n);
  gets(ch + 1);
  m = strlen(ch + 1);
  for (long long i = 1; i <= m; i++) {
    a[i] = ch[i] - 'A' + 1;
  }
  b = min(11ll, m + 1);
  d.q = 0;
  memset(d.p, 0, sizeof(d.p));
  memset(v, 0, sizeof(v));
  for (long long i = 1; i <= m; i++) {
    d.ins(i);
  }
  for (long long i = 1; i <= 4; i++) {
    for (long long j = 1; j <= 4; j++) {
      for (long long k = b; k >= 2; k--) {
        if (d1[i][j][k] != pow(4, k - 2)) {
          sd.p[i][j] = k - 1;
        }
      }
    }
  }
  long long l = 1, r = n, mid;
  while (l <= r) {
    mid = ((l + r) >> 1);
    if (chk(mid)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  printf("%lld", (l + r) >> 1);
  return 0;
}
