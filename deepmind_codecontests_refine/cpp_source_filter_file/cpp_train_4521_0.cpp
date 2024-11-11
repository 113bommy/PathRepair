#include <bits/stdc++.h>
using namespace std;
vector<pair<long double, long double> > pols[310];
long double eps = 0.000000000000000001;
long double ans[310];
long double area(vector<pair<long double, long double> > a) {
  long double ret = 0;
  for (long long i = 0; i < a.size() - 1; i++)
    ret += (a[i].second + a[i + 1].second) * (a[i + 1].first - a[i].first) / 2;
  return ret;
}
vector<pair<long double, long double> > merg(
    vector<pair<long double, long double> > a,
    vector<pair<long double, long double> > b) {
  vector<pair<long double, long double> > ret;
  long long j = 0;
  for (long long i = 0; i < a.size() - 1; i++) {
    while (j < b.size() - 1 and b[j].first < a[i + 1].first) {
      long double k1 =
          (a[i + 1].second - a[i].second) / (a[i + 1].first - a[i].first);
      long double k2 =
          (b[j + 1].second - b[j].second) / (b[j + 1].first - b[j].first);
      long double m1 = a[i].second - k1 * a[i].first;
      long double m2 = b[j].second - k2 * b[j].first;
      if (a[i].first == b[j].first) {
        ret.push_back(make_pair(a[i].first, max(a[i].second, b[j].second)));
        long double temp = (m2 - m1) / (k1 - k2);
        if (a[i].second != b[j].second and k1 != k2 and temp > a[i].first and
            temp > b[j].first and temp < a[i + 1].first and
            temp < b[j + 1].first)
          ret.push_back(make_pair(temp, k1 * temp + m1));
      } else {
        if (b[j].second - eps > k1 * b[j].first + m1) {
          ret.push_back(b[j]);
          long double temp = (m2 - m1) / (k1 - k2);
          if (k1 != k2 and temp > a[i].first and temp > b[j].first and
              temp < a[i + 1].first and temp < b[j + 1].first)
            ret.push_back(make_pair(temp, k1 * temp + m1));
        } else if (fabs(b[j].second - k1 * b[j].first - m1) < eps) {
          long double k3 =
              (b[j].second - b[j - 1].second) / (b[j].first - b[j - 1].first);
          ret.push_back(b[j]);
        } else if (b[j].second < k1 * b[j].first + m1 - eps) {
          long double temp = (m2 - m1) / (k1 - k2);
          if (k1 != k2 and temp > a[i].first and temp > b[j].first and
              temp < a[i + 1].first and temp < b[j + 1].first)
            ret.push_back(make_pair(temp, k1 * temp + m1));
        }
      }
      j++;
    }
  }
  ret.push_back(make_pair(a[a.size() - 1].first,
                          max(a[a.size() - 1].second, b[b.size() - 1].second)));
  return ret;
}
int main() {
  long long n, k;
  cin >> n >> k;
  long double t;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < k + 1; j++)
      scanf("%Lf", &t), pols[i].push_back(make_pair((long double)j, t));
  ans[0] = area(pols[0]);
  printf("%.15Lf \n", ans[0]);
  auto cur = pols[0];
  for (long long i = 1; i < n; i++) {
    cur = merg(pols[i], cur);
    ans[i] = area(cur);
    printf("%.15Lf \n", ans[i] - ans[i - 1]);
  }
}
