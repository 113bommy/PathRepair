#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  if (!b) return a;
  return gcd(b, a % b);
}
template <class T>
T power(T a, T b) {
  T res(1);
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
template <class T>
T powerM(T a, T b, T mod) {
  T res(1);
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
const int infi = 2147483647;
const long long infl = 9223372036854775807;
int n, m;
long long c[101000];
int bel[101000];
struct hh {
  int l, r, i;
  bool operator<(const hh &x) const {
    if (bel[l] == bel[x.l]) return bel[r] < bel[x.r];
    return bel[l] < bel[x.l];
  }
} a[101000];
long long ans[101000];
long long now;
long long pool[101000 * 3];
long long num[101000 * 3];
int up[101000], down[101000], p[101000];
map<long long, long long> f;
int erfen(long long x, int l, int r) {
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (pool[mid] == x)
      return mid;
    else if (pool[mid] > x)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return (l + r) >> 1;
}
int main() {
  scanf("%d", &n), scanf("%d", &m);
  int k = sqrt(n);
  for (int i = 1; i <= (n); ++i) {
    scanf("%d", &c[i]);
    bel[i] = i / k + 1;
  }
  for (int i = 1; i <= (n); ++i) {
    int x;
    scanf("%d", &x);
    if (c[i] != 1)
      c[i] = -x;
    else
      c[i] = x;
    c[i] += c[i - 1];
    pool[i] = c[i];
    pool[i + n] = c[i] + m;
    pool[i + 2 * n] = c[i] - m;
  }
  pool[3 * n + 1] = 0;
  pool[3 * n + 2] = 0 + m;
  pool[3 * n + 3] = 0 - m;
  sort(pool + 1, pool + 1 + 3 * n + 1);
  k = unique(pool + 1, pool + 1 + 3 * n + 1) - pool - 1;
  for (int i = 1; i <= (n); ++i) {
    p[i] = erfen(c[i], 1, k);
    up[i] = erfen(c[i] + m, 1, k);
    down[i] = erfen(c[i] - m, 1, k);
  }
  p[0] = erfen(0, 1, k);
  up[0] = erfen(m, 1, k);
  down[0] = erfen(-m, 1, k);
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= (q); ++i) {
    int l, r;
    scanf("%d", &l), scanf("%d", &r);
    if (l > r) swap(l, r);
    a[i].l = l - 1, a[i].r = r, a[i].i = i;
  }
  sort(a + 1, a + 1 + q);
  int l = 0, r = 0;
  num[1] = 1;
  for (int i = 1; i <= (q); ++i) {
    while (l > a[i].l) {
      l--;
      now += num[up[l]];
      num[p[l]]++;
    }
    while (r < a[i].r) {
      r++;
      now += num[down[r]];
      num[p[r]]++;
    }
    while (l < a[i].l) {
      if (l >= 0) {
        num[p[l]]--;
        now -= num[up[l]];
      }
      l++;
    }
    while (r > a[i].r) {
      if (r <= n) {
        num[p[r]]--;
        now -= num[down[r]];
      }
      r--;
    }
    ans[a[i].i] = now;
  }
  for (int i = 1; i <= (q); ++i) {
    printf("%lld", ans[i]), putchar('\n');
  }
  return 0;
}
