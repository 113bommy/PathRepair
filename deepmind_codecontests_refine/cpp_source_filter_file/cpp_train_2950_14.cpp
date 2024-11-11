#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
int n, k, h;
pair<int, pair<int, int> > p[100002];
int res[100002], a[100002];
bool check(double t) {
  int l = 1;
  for (int i = 0; i < n; ++i) {
    if (t / l > h * 1.0 / p[i].second.first) {
      a[l - 1] = p[i].second.second;
      ++l;
    }
    if (l == k + 1) {
      for (int i = 0; i < k; ++i) res[i] = a[i];
      return true;
    }
  }
  return false;
}
int main() {
  scanf("%d%d%d", &n, &k, &h);
  double l = 0, r = h * 1.0 * n, m;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i].first);
    p[i].second.second = i + 1;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i].second.first);
  }
  sort(p, p + n);
  int t = 100;
  while (t--) {
    m = (r + l) / 2;
    if (check(m))
      r = m;
    else
      l = m;
  }
  for (int i = 0; i < k; ++i) printf("%d ", res[i]);
  return 0;
}
