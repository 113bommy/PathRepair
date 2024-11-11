#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-10;
long double a[10001];
int n;
long double L;
bool EQ(long double a, long double b) { return fabs(a - b) <= eps; }
struct El {
  long double t;
  int type;
  El(long double t = 0, int type = 1) : t(t), type(type) {}
};
inline bool compare(El a, El b) {
  if (EQ(a.t, b.t)) return a.type == 1 && b.type == -1;
  return a.t < b.t + eps;
}
long double func(long double m) {
  vector<El> v;
  for (int i = 0; i < n; i++) {
    long double x = a[i] - m, y = a[i] + m;
    if (x < eps) x = 0;
    if (y > L - eps) y = L;
    v.push_back(El(x, 1));
    v.push_back(El(y, -1));
  }
  sort(v.begin(), v.end(), compare);
  int bal = 0;
  long double pr = 0;
  long double ans = 0;
  for (int i = 0; i < int(v.size()); i++) {
    if (bal == 0) pr = v[i].t;
    if (pr <= eps) pr = 0;
    bal += v[i].type;
    if (bal == 0) {
      if (v[i].t < L - eps)
        ans += v[i].t - pr;
      else
        ans += L - pr;
    }
  }
  return ans;
}
int main() {
  cout.precision(20);
  cin >> n >> L;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long double l = 0, r = L;
  while (r - l > eps) {
    long double m = (l + r) / 2;
    if (!EQ(func(m), L))
      l = m;
    else
      r = m;
  }
  cout << l << endl;
  return 0;
}
