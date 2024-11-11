#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
const int oo = 1e9;
const int mod = 1e9 + 7;
pair<long long, long long> a[2 * N];
int n;
long long t;
int main() {
  cin >> n >> t;
  long long sum = 0, tmp = 0;
  for (int i = 0; i < n; i++) cin >> a[i].second;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    tmp += a[i].first * a[i].second;
    sum += a[i].second;
  }
  sort(a, a + n);
  if (tmp < t * sum) {
    t *= -1ll;
    for (int i = 0; i < n; i++) a[i].first *= -1LL;
    reverse(a, a + n);
    tmp *= -1;
  }
  int p = n - 1;
  while (p >= 0 && tmp > t * sum) {
    tmp -= a[p].first * a[p].second;
    sum -= a[p].second;
    p--;
  }
  p++;
  long double lo = 0.0, hi = a[p].second;
  for (int it = 0; it < 101; it++) {
    long double md = (lo + hi) / 2.0L;
    long double x = tmp + md * a[p].first;
    long double y = sum + md;
    if (x <= t * y)
      lo = md;
    else
      hi = md;
  }
  printf("%.12lf\n", sum + lo);
}
