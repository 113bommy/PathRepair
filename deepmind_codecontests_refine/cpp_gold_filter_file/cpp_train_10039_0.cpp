#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 10;
const long long INF = 1e8;
const long long C = 1e9;
long long n, k, d, arr[MAXN];
long long prv[MAXN];
long long weed[4 * MAXN], nut[4 * MAXN];
map<long long, long long> mp;
pair<long long, long long> f[MAXN], g[MAXN];
void plant(long long v, long long b, long long e) {
  weed[v] = INF;
  if (e - b == 1) return;
  long long mid = b + e >> 1;
  plant(v << 1, b, mid);
  plant(v << 1 ^ 1, mid, e);
}
void absorb(long long v) {
  if (!nut[v]) return;
  nut[v << 1] += nut[v];
  nut[v << 1 ^ 1] += nut[v];
  weed[v << 1] += nut[v];
  weed[v << 1 ^ 1] += nut[v];
  nut[v] = 0;
}
void modify(long long v, long long b, long long e, long long pos,
            long long val) {
  if (e - b == 1) {
    weed[v] = val;
    return;
  }
  long long mid = b + e >> 1;
  absorb(v);
  if (pos < mid)
    modify(v << 1, b, mid, pos, val);
  else
    modify(v << 1 ^ 1, mid, e, pos, val);
  weed[v] = min(weed[v << 1], weed[v << 1 ^ 1]);
}
void water(long long v, long long b, long long e, long long l, long long r,
           long long val) {
  if (l <= b && e <= r) {
    weed[v] += val;
    nut[v] += val;
    return;
  }
  if (r <= b || e <= l) return;
  long long mid = b + e >> 1;
  absorb(v);
  water(v << 1, b, mid, l, r, val);
  water(v << 1 ^ 1, mid, e, l, r, val);
  weed[v] = min(weed[v << 1], weed[v << 1 ^ 1]);
}
long long smoke(long long v, long long b, long long e) {
  if (e - b == 1) return b;
  long long mid = b + e >> 1;
  absorb(v);
  if (weed[v << 1] <= k) return smoke(v << 1, b, mid);
  return smoke(v << 1 ^ 1, mid, e);
}
int main() {
  scanf("%I64d %I64d %I64d", &n, &k, &d);
  for (long long i = 0; i < n; i++) scanf("%I64d", &arr[i]), arr[i] += C;
  if (!d) {
    long long l = 0, r = 0;
    long long tl = 0, tr = 0;
    for (long long i = 0; i < n; i++) {
      if (i && arr[i] ^ arr[i - 1]) tl = tr = i;
      tr++;
      if (r - l < tr - tl) l = tl, r = tr;
    }
    printf("%I64d %I64d\n", l + 1, r);
  } else {
    for (long long i = 0; i < n; i++) {
      if (mp.count(arr[i]))
        prv[i] = mp[arr[i]] + 1;
      else
        prv[i] = 0;
      mp[arr[i]] = i;
    }
    mp.clear();
    long long l = 0, r = 0;
    long long tl = 0, hmin = 0, tmin = 0, hmax = 0, tmax = 0;
    plant(1, 0, n);
    for (long long i = 0; i < n; i++) {
      if (tl < prv[i]) {
        for (; tl < prv[i]; tl++) modify(1, 0, n, tl, INF);
        while (hmin < tmin && f[hmin].second <= tl) hmin++;
        while (hmax < tmax && g[hmax].second <= tl) hmax++;
      }
      if (i && arr[i - 1] % d ^ arr[i] % d) {
        water(1, 0, n, tl, i, INF);
        tl = i, hmin = tmin, hmax = tmax;
      }
      long long v = arr[i] / d;
      while (hmin < tmin && f[tmin - 1].first > v)
        tmin--, water(1, 0, n, hmin == tmin ? tl : f[tmin - 1].second,
                      f[tmin].second, f[tmin].first - v);
      while (hmax < tmax && g[tmax - 1].first < v)
        tmax--, water(1, 0, n, hmax == tmax ? tl : g[tmax - 1].second,
                      g[tmax].second, v - g[tmax].first);
      f[tmin++] = {v, i + 1};
      g[tmax++] = {v, i + 1};
      modify(1, 0, n, i, 1);
      water(1, 0, n, tl, i + 1, -1);
      long long x = smoke(1, 0, n);
      if (i + 1 - x > r - l) l = x, r = i + 1;
    }
    printf("%I64d %I64d\n", l + 1, r);
  }
  return 0;
}
