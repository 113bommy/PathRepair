#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 10;
long long n, q, le, ri, weed[4 * MAXN];
bool dir;
void plant(long long v, long long b, long long e) {
  if (e - b == 1) {
    weed[v] = 1;
    return;
  }
  long long mid = (b + e) / 2;
  plant(v << 1, b, mid);
  plant(v << 1 ^ 1, mid, e);
  weed[v] = weed[v << 1] + weed[v << 1 ^ 1];
}
void water(long long v, long long b, long long e, long long x, long long val) {
  if (e - b == 1) {
    weed[v] += val;
    return;
  }
  long long mid = (b + e) / 2;
  if (x < mid)
    water(v << 1, b, mid, x, val);
  else
    water(v << 1 ^ 1, mid, e, x, val);
  weed[v] = weed[v << 1] + weed[v << 1 ^ 1];
}
long long smoke(long long v, long long b, long long e, long long l,
                long long r) {
  if (l <= b && e <= r) return weed[v];
  if (r <= b || e <= l) return 0;
  long long mid = (b + e) / 2;
  return smoke(v << 1, b, mid, l, r) + smoke(v << 1 ^ 1, mid, e, l, r);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  le = 0, ri = n;
  plant(1, 0, n);
  while (q--) {
    long long type;
    cin >> type;
    if (type == 1) {
      long long x;
      cin >> x;
      if (dir) x = (ri - le) - x;
      if (!dir && 2 * x > ri - le)
        dir = !dir;
      else if (dir && 2 * x < ri - le)
        dir = !dir;
      x += le;
      if (!dir) {
        for (long long i = x; i < x + (x - le); i++)
          water(1, 0, n, i, smoke(1, 0, n, i - (i - x + 1), i - (i - x)));
        le = x;
      } else {
        for (long long i = x - 1; i >= x - (ri - x); i--)
          water(1, 0, n, i, smoke(1, 0, n, x + (x - 1 - i), x + (x - i)));
        ri = x;
      }
    } else {
      long long l, r;
      cin >> l >> r;
      l += le;
      r += le;
      if (dir == 0)
        cout << smoke(1, 0, n, l, r) << "\n";
      else
        cout << smoke(1, 0, n, le + (ri - r), le + (ri - l)) << "\n";
    }
  }
  return 0;
}
