#include <bits/stdc++.h>
using namespace std;
int const MAX = 500 * 1000 + 41;
long long const INF = (long long)1000 * 1000 * 1000 * 1000 * 1000;
int n;
int a[MAX];
int r;
long long k;
long long e1[MAX];
long long e2[MAX];
int can(long long m) {
  long long rem = k;
  memset(e2, 0, sizeof(e2));
  long long cur = 0;
  for (int i = 1; i <= n; i++) {
    cur += e1[i];
    cur += e2[i];
    if (cur < m) {
      long long x = m - cur;
      if (x > rem) return false;
      cur += x;
      rem -= x;
      int r = min(n + 1, i + ::r * 2 + 1);
      e2[r] -= x;
      if (m == 4) {
        while (false) {
        };
      }
    }
    if (m == 4 && i == 5) {
      while (false) {
      };
    }
  }
  return true;
}
void solve() {
  for (int i = 1; i <= n; i++) {
    int l = max(1, i - ::r);
    e1[l] += a[i];
    int r = min(n + 1, i + ::r + 1);
    e1[r] -= a[i];
  }
  long long l = -1;
  long long r = INF;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (can(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  printf("%lld\n", l);
}
int main() {
  scanf("%d %d %lld", &n, &r, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  solve();
  return 0;
}
