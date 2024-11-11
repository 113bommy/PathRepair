#include <bits/stdc++.h>
using namespace std;
const long double epsilon = 1e-11;
int main() {
  int n;
  cin >> n;
  vector<double> v(n);
  for (int i = 0; i < n; i++) scanf("%lf", &v[i]);
  sort(v.begin(), v.end());
  double step = 2 * 1e9;
  double cur = 0;
  int idx;
  int cnt = 0;
  while (step > epsilon) {
    cur += step;
    double beg = v[0];
    idx = 0;
    cnt = 1;
    while (cnt < 4 && idx < n) {
      if (v[idx] - beg - epsilon < 2.0 * cur)
        idx++;
      else {
        beg = v[idx];
        cnt++;
        idx++;
      }
    }
    if (cnt < 4 && idx == n) cur -= step;
    step /= 2.0;
  }
  cur += 1e-8;
  vector<double> ans;
  double beg = v[0];
  ans.push_back(beg + cur);
  idx = 0;
  cnt = 1;
  while (cnt < 4 && idx < n) {
    if (idx < n && v[idx] - beg - epsilon < 2.0 * cur)
      idx++;
    else {
      beg = v[idx];
      ans.push_back(beg + cur);
      cnt++;
      idx++;
    }
  }
  while (ans.size() < 3) ans.push_back(0.0);
  printf("%.10lf\n%.10lf %.10lf %.10lf\n", cur, ans[0], ans[1], ans[2]);
  return 0;
}
