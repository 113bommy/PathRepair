#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535897932384626433832795;
int n;
const int N = 1000 * 100 + 7;
long long r[N], h[N];
pair<long long, long long> v[N];
long long dp[N];
long long t[4 * N];
void update(int pos, long long val, int v, int l, int r) {
  if (l == r) {
    t[v] = max(t[v], val);
    return;
  }
  int tm = (l + r) / 2;
  if (pos <= tm)
    update(pos, val, v * 2, l, tm);
  else
    update(pos, val, v * 2 + 1, tm + 1, r);
  t[v] = max(t[v * 2], t[v * 2 + 1]);
}
long long mx(long long v, long long tl, long long tr, long long l,
             long long r) {
  if (l > r) return 0;
  if (tl == l && tr == r) return t[v];
  long long m = (tl + tr) / 2;
  return max(mx(2 * v, tl, m, l, min(r, m)),
             mx(2 * v + 1, m + 1, tr, max(m + 1, l), r));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &r[i], &h[i]);
    long long a = r[i];
    long long b = h[i];
    a = a * a * b;
    v[i] = {a, -i};
  }
  sort(v + 1, v + n + 1);
  long long mxx = 0;
  for (int i = 1; i <= n; i++) {
    long long val = v[i].first;
    long long ind = -v[i].second;
    long long x = mx(1, 0, n, 0, ind);
    x += val;
    mxx = max(mxx, x);
    update(ind, x, 1, 0, n);
  }
  printf("%llf", mxx * PI);
  return 0;
}
