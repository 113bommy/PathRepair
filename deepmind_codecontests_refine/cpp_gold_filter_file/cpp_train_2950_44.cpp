#include <bits/stdc++.h>
using namespace std;
double const EPS = 1e-20;
long long b[100010], d[100010], c[100010], e[100010];
pair<pair<long long, long long>, long long> a[100010];
int main() {
  long long n, k, m, h, v, i, j, l, p;
  double t, max1, min1, t2, t1 = 10000000000000, t3 = 10000000000000000;
  cin >> n >> k >> h;
  for (i = 1; i <= n; i++) {
    cin >> b[i];
    d[i] = -1;
  }
  for (i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (i = 1; i <= n; i++) {
    a[i] = make_pair(make_pair(b[i], c[i]), i);
  }
  sort(a + 1, a + n + 1);
  max1 = 1000000000000000000;
  min1 = 0;
  while (1) {
    t = (max1 + min1) / 2;
    l = 1;
    m = 0;
    double tt;
    tt = t1 > t ? t1 - t : t - t1;
    if (tt < EPS) break;
    for (i = 1; i <= n; i++) {
      p = a[i].first.second;
      if (EPS <= t - ((double)(l * h) / p)) {
        e[m] = a[i].second;
        m++;
        l++;
      }
    }
    if (m == k) {
      if (t < t3) {
        for (j = 0; j < k; j++) d[j] = e[j];
        t3 = t;
      }
      max1 = t;
    } else if (m < k) {
      min1 = t;
    } else {
      max1 = t;
    }
    t1 = t;
  }
  for (i = 0; i < k; i++) cout << d[i] << " ";
  return 0;
}
