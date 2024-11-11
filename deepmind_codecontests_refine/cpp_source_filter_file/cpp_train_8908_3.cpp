#include <bits/stdc++.h>
using namespace std;
const int OO = 2e9;
const int N = 60005;
int n;
int pos[N], v[N];
bool valid(double tm) {
  pair<double, double> intersect = {-OO, OO};
  for (int i = 0; i < n; i++) {
    intersect.first = max(intersect.first, pos[i] - v[i] * tm);
    intersect.second = min(intersect.second, pos[i] + v[i] * tm);
  }
  return intersect.first <= intersect.second;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", pos + i);
  for (int i = 0; i < n; i++) scanf("%d", v + i);
  double st = 0, sz = OO;
  for (sz /= 2; sz > 1e-9; sz /= 2) {
    double md = st + sz;
    auto p = valid(md);
    if (valid(md)) {
      st = md;
    }
  }
  printf("%.6lf", st + sz / 2);
}
