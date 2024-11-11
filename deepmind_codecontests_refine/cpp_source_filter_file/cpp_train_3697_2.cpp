#include <bits/stdc++.h>
using namespace std;
inline int nxt() {
  int first;
  scanf("%d", &first);
  return first;
}
const long double eps = 1e-10;
inline long double vec(const pair<long double, long double>& p,
                       const pair<long double, long double>& q) {
  return p.first * q.second - p.second * q.first;
}
void qwq(pair<long double, long double>& p) {
  if (p.first < -eps || (p.first < eps && p.second < -eps)) {
    p.first = -p.first;
    p.second = -p.second;
  }
}
bool cmp(pair<long double, long double> p, pair<long double, long double> q) {
  qwq(p);
  qwq(q);
  return p.first * q.second - p.second * q.first < -eps;
}
int main() {
  int n = nxt();
  vector<pair<long double, long double>> a;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int first = nxt(), second = nxt(), z = nxt();
    if (z == 0)
      cnt++;
    else {
      long double X = 1.0 * first / z;
      long double Y = 1.0 * second / z;
      long double d = X * X + Y * Y;
      X /= d;
      Y /= d;
      a.push_back({X, Y});
    }
  }
  long long ans = 0;
  n = a.size();
  if (cnt == 2) ans = n;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      a[j].first -= a[i].first;
      a[j].second -= a[i].second;
    }
    sort(a.begin() + i + 1, a.end(), &cmp);
    int cur = 1;
    for (int j = i + 2; j < n; j++) {
      if (fabs(vec(a[j], a[j - 1])) < eps)
        cur += 1;
      else {
        ans += cur * (cur - 1) / 2;
        cur = 1;
      }
    }
    ans += cur * (cur - 1) / 2;
  }
  cout << ans << "\n";
  return 0;
}
