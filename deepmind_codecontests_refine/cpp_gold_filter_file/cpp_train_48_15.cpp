#include <bits/stdc++.h>
using namespace std;
map<int, int> id;
int dy[505];
int idc;
struct fuck {
  long long ori[550];
  long long delta[550];
} seq[105];
const int mod = 1000000007;
int qpow(long long base, long long tms) {
  long long tmp = 1;
  while (tms) {
    if (tms & 1) tmp = tmp * base % mod;
    base = base * base % mod;
    tms >>= 1;
  }
  return tmp;
}
long long x, y;
long long exgcd(long long a, long long b) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long gc = exgcd(b, a % b);
  long long t = x;
  x = y;
  y = t - a / b * x;
  return gc;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int j = 2; j * j <= a; ++j) {
      if (a % j == 0) {
        if (!id[j]) id[j] = ++idc, dy[idc] = j;
        while (a % j == 0) seq[i].ori[id[j]]++, a /= j;
      }
    }
    if (a > 1) {
      if (!id[a]) id[a] = ++idc, dy[idc] = a;
      seq[i].ori[id[a]]++;
    }
    for (int j = 2; j * j <= b; ++j) {
      if (b % j == 0) {
        if (!id[j]) id[j] = ++idc, dy[idc] = j;
        while (b % j == 0) seq[i].delta[id[j]]++, b /= j;
      }
    }
    if (b > 1) {
      if (!id[b]) id[b] = ++idc, dy[idc] = b;
      seq[i].delta[id[b]]++;
    }
  }
  for (int i = 2; i <= n; ++i) {
    int ps = 0;
    for (int j = 1; j <= idc; ++j)
      if (seq[1].delta[j] || seq[i].delta[j]) {
        ps = j;
        break;
      }
    if (!ps) {
      for (int j = 1; j <= idc; ++j)
        if (seq[1].ori[j] != seq[i].ori[j]) {
          printf("-1\n");
          return 0;
        }
      continue;
    }
    int nxt = 0;
    for (int j = ps + 1; j <= idc; ++j)
      if (seq[i].delta[ps] * seq[1].delta[j] ==
              seq[i].delta[j] * seq[1].delta[ps] &&
          (seq[1].ori[ps] - seq[i].ori[ps]) * seq[i].delta[j] ==
              (seq[1].ori[j] - seq[i].ori[j]) * seq[i].delta[ps])
        ;
      else {
        nxt = j;
        break;
      }
    if (!nxt) {
      long long a = seq[1].delta[ps], b = -seq[i].delta[ps],
                c = seq[i].ori[ps] - seq[1].ori[ps];
      long long gc1 = abs(exgcd(exgcd(a, b), c));
      a /= gc1, b /= gc1, c /= gc1;
      long long gc = exgcd(a, b);
      if (c % gc) {
        printf("-1\n");
        return 0;
      }
      x *= c / gc;
      y *= c / gc;
      b = -b;
      long long pl, tm;
      if ((a == 0 && y < 0) || (b == 0 && x < 0)) {
        printf("-1\n");
        return 0;
      } else if (a == 0)
        pl = tm = 0;
      else if (b == 0)
        pl = x, tm = 0;
      else {
        long long t = max(-(y / a), -(x / b));
        x += t * b;
        y += t * a;
        while (x < 0 || y < 0) x += b, y += a;
        while (x >= b && y >= a) x -= b, y -= a;
        pl = x, tm = b;
      }
      for (int j = 1; j <= idc; ++j)
        seq[1].ori[j] += seq[1].delta[j] * pl, seq[1].delta[j] *= tm;
    } else {
      long long a = seq[1].delta[ps], b = seq[i].delta[ps],
                c = seq[i].ori[ps] - seq[1].ori[ps];
      long long d = seq[1].delta[nxt], e = seq[i].delta[nxt],
                f = seq[i].ori[nxt] - seq[1].ori[nxt];
      x = b * f - e * c;
      y = a * f - d * c;
      long long m = b * d - a * e;
      if (!m || x % m || y % m) {
        printf("-1\n");
        return 0;
      }
      x /= m;
      y /= m;
      if (x < 0 || y < 0) {
        printf("-1\n");
        return 0;
      }
      for (int j = 1; j <= idc; ++j)
        if (seq[1].ori[j] + seq[1].delta[j] * x !=
            seq[i].ori[j] + seq[i].delta[j] * y) {
          printf("-1\n");
          return 0;
        } else
          seq[1].ori[j] = seq[1].ori[j] + seq[1].delta[j] * x,
          seq[1].delta[j] = 0;
    }
  }
  long long ans = 1;
  for (int i = 1; i <= idc; ++i) ans = ans * qpow(dy[i], seq[1].ori[i]) % mod;
  printf("%lld\n", ans);
}
