#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
int comparar(double i, double j) {
  if (j - i > 1e-07) return -1;
  if (i - j > 1e-07) return 1;
  return 0;
}
int main() {
  int n, V;
  scanf("%d %d", &n, &V);
  v.clear();
  v.resize(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i].first);
  for (int i = 0; i < n; i++) scanf("%d", &v[i].second);
  double a, b, min;
  a = v[0].second;
  b = a / v[0].first;
  min = b;
  for (int i = 1; i < n; i++) {
    a = v[i].second;
    b = a / v[i].first;
    if (comparar(b, min) < 0) min = b;
  }
  double vRes = 0;
  double vMax = V;
  for (int i = 0; i < n; i++) vRes += (min * v[i].first);
  if (comparar(vRes, vMax) < 0)
    printf("%.1lf\n", vRes);
  else
    printf("%.1lf\n", vMax);
}
