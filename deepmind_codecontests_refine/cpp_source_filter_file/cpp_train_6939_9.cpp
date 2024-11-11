#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return !a ? b : gcd(b % a, a); }
const int maxn = 210000;
const long double eps = 1e-7;
int n;
int wn, hn;
map<int, long long> mp[maxn];
long long wi[maxn], hi[maxn], ci[maxn];
struct node {
  long long x;
  long long *i;
  friend inline bool operator<(const node a, const node b) { return a.x < b.x; }
} a[maxn];
void Trans() {
  for (int i = 1; i <= n; i++) a[i].x = wi[i], a[i].i = &wi[i];
  sort(a + 1, a + n + 1);
  a[0].x = a[1].x - 1;
  wn = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i - 1].x != a[i].x) ++wn;
    (*a[i].i) = wn;
  }
  for (int i = 1; i <= n; i++) a[i].x = hi[i], a[i].i = &hi[i];
  sort(a + 1, a + n + 1);
  a[0].x = a[1].x - 1;
  hn = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].x != a[i - 1].x) ++hn;
    (*a[i].i) = hn;
  }
}
int main() {
  scanf("%d", &n);
  long long g = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%l64d%l64d%l64d", &wi[i], &hi[i], &ci[i]);
    g = gcd(g, ci[i]);
  }
  Trans();
  if ((long long)wn * hn != n) return puts("0"), 0;
  for (int i = 1; i <= n; i++) ci[i] /= g;
  for (int i = 1; i <= n; i++) mp[wi[i]][hi[i]] = ci[i];
  for (int i = 1; i < wn; i++) {
    for (int j = 2; j <= hn; j++) {
      long double t1 = (long double)mp[i][j] / (long double)mp[i][j - 1];
      long double t2 =
          (long double)mp[i + 1][j] / (long double)mp[i + 1][j - 1];
      if (abs(t1 - t2) > eps) return puts("0"), 0;
    }
  }
  long long ans = 0;
  for (int i = 1; (long long)i * i <= g; i++)
    if (g % i == 0) {
      ans++;
      if ((long long)i * i != g) ans++;
    }
  printf("%lld\n", ans);
  return 0;
}
