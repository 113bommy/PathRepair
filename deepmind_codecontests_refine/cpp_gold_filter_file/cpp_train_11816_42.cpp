#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long pri[200005], ni[200005], dp[2005];
void extgcd(long long a, long long b, long long& d, long long& x,
            long long& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    extgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
long long inverse(long long a, long long n) {
  long long d, x, y;
  extgcd(a, n, d, x, y);
  return d == 1 ? (x + n) % n : -1;
}
void init() {
  pri[0] = 1;
  for (int i = 1; i <= 2e5; i++) {
    pri[i] = pri[i - 1] * i % mod;
    ni[i] = inverse(pri[i], mod);
  }
  for (int i = 2e5 - 1; i >= 1; i--) {
    ni[i] = (ni[i + 1] * (i + 1)) % mod;
  }
  ni[0] = 1;
}
long long c(int i, int j) { return ((pri[i] * ni[j]) % mod * ni[i - j]) % mod; }
struct node {
  int x;
  int y;
} a[2005];
bool cmp(node l, node r) {
  if (l.x == r.x) return l.y < r.y;
  return l.x < r.x;
}
int main() {
  int h, w, n;
  scanf("%d%d%d", &h, &w, &n);
  init();
  for (int i = 0; i < n; i++) scanf("%d%d", &a[i].x, &a[i].y);
  a[n].x = h;
  a[n].y = w;
  sort(a, a + n + 1, cmp);
  for (int i = 0; i <= n; i++) {
    int l = a[i].x - 1;
    int r = a[i].y - 1;
    dp[i] = c(l + r, l);
    for (int j = 0; j < i; j++) {
      if (a[i].x >= a[j].x && a[i].y >= a[j].y) {
        l = a[i].x - a[j].x;
        r = a[i].y - a[j].y;
        dp[i] = (dp[i] - (dp[j] * c(l + r, l)) % mod + mod) % mod;
      }
    }
  }
  printf("%lld\n", dp[n]);
  return 0;
}
