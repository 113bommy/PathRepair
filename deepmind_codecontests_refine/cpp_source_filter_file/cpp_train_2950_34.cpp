#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
int m, h;
pair<pair<int, int>, int> w[100000];
int res[100000];
int can(double t) {
  int cur = 0;
  for (int i = 0; cur < m && i < n; i++)
    if ((cur + 1) * h / w[i].first.second < t + 1e-6) {
      res[cur] = w[i].second;
      cur++;
    }
  if (cur == m) return 1;
  return 0;
}
int main() {
  scanf("%d%d%d", &n, &m, &h);
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i].first.first);
    w[i].second = i + 1;
  }
  for (int i = 0; i < n; i++) scanf("%d", &w[i].first.second);
  sort(w, w + n);
  double l = 0, r = 2e9;
  for (int it = 0; it < 100; it++) {
    double s = (l + r) / 2;
    if (can(s))
      r = s;
    else
      l = s;
  }
  can(r);
  for (int i = 0; i < m; i++) printf("%d ", res[i]);
  printf("\n");
  return 0;
}
