#include <bits/stdc++.h>
using namespace std;
int _;
const int MAXN = 111 * 1000;
const long long INF = 100LL * 1000 * 1000 * 1000;
int n;
pair<long long, long long> p[MAXN];
long long mxr[MAXN], mxl[MAXN];
long long mnr[MAXN], mnl[MAXN];
long long z[2 * MAXN];
bool Intersect(pair<long long, long long> a, pair<long long, long long> b) {
  return ((b.first <= a.first && a.first <= b.second) ||
          (a.first <= b.first && b.first <= a.second));
}
pair<long long, long long> FindL(long long x, long long d) {
  if (x - p[0].first <= d) return pair<long long, long long>(-INF, INF);
  int l = 0, r = lower_bound(p, p + n, pair<long long, long long>(x, -INF)) - p;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (d < x - p[m].first)
      l = m;
    else
      r = m - 1;
  }
  return pair<long long, long long>(mxl[l] - d, mnl[l] + d);
}
pair<long long, long long> FindR(long long x, long long d) {
  if (p[n - 1].first - x <= d) return pair<long long, long long>(-INF, INF);
  int l = lower_bound(p, p + n, pair<long long, long long>(x, INF)) - p,
      r = n - 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (d < p[m].first - x)
      r = m;
    else
      l = m + 1;
  }
  return pair<long long, long long>(mxr[l] - d, mnr[l] + d);
}
bool Can(long long m) {
  for (int i = 0; i < n; ++i)
    z[2 * i] = p[i].first, z[2 * i + 1] = p[i].first - m;
  int N = 2 * n;
  for (int i = 0; i < N; ++i) {
    pair<long long, long long> l = FindL(z[i], m);
    pair<long long, long long> r = FindR(z[i], m);
    if (l.first <= l.second && r.first <= r.second && Intersect(l, r)) {
      return true;
    }
  }
  return false;
}
int main() {
  _ = scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    _ = scanf("%d %d", &x, &y);
    p[i].first = x * 4, p[i].second = y * 4;
    pair<long long, long long> d = pair<long long, long long>(
        (p[i].first + p[i].second) / 2, (p[i].first - p[i].second) / 2);
    p[i] = d;
  }
  sort(p, p + n);
  for (int i = 0; i < n; ++i) {
    mxl[i] = mnl[i] = p[i].second;
    if (i) {
      mxl[i] = max(mxl[i], mxl[i - 1]);
      mnl[i] = min(mnl[i], mnl[i - 1]);
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    mxr[i] = mnr[i] = p[i].second;
    if (i != n - 1) {
      mxr[i] = max(mxr[i], mxr[i + 1]);
      mnr[i] = min(mnr[i], mnr[i + 1]);
    }
  }
  long long l = 0, r = 100LL * 1000 * 1000 * 1000;
  while (l < r) {
    long long m = (l + r) / 2;
    if (Can(m))
      r = m;
    else
      l = m + 1;
  }
  cout << fixed << l / 2.0 << endl;
  return 0;
}
