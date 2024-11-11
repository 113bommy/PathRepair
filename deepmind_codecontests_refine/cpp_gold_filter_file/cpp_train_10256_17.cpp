#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int m;
int n;
double a1[100500], b1[100500], c1[100500], a2[100500], b2[100500], c2[100500];
double a[100500], b[100500];
double check(pair<int, int> o) {
  double x1, y95874;
  if (o.second == 1) {
    x1 = a1[o.first];
    y95874 = b1[o.first];
  } else {
    x1 = a2[o.first];
    y95874 = b2[o.first];
  }
  double ans = max(1 / x1, 1 / y95874);
  double eps = 1e-8;
  for (int i = 0; i < (n); i++) {
    double x2 = a[i];
    double y2 = b[i];
    ans = min(ans, max(1 / x2, 1 / y2));
    double cx1 = x1, cy1 = y95874;
    double cx2 = x2, cy2 = y2;
    if (cx1 < cy1) {
      swap(cx1, cy1);
      swap(cx2, cy2);
    }
    if (cx2 >= cy2) continue;
    double d1 = cx1 - cy1;
    double d2 = cy2 - cx2;
    double u = (d1 + d2);
    if (u < eps) continue;
    double hx = cx1 * d2 + cx2 * d1;
    double hy = cy1 * d2 + cy2 * d1;
    ans = min(ans, 1 / min(hx, hy) * u);
  }
  return ans;
}
int main() {
  cin >> n;
  double p, q;
  cin >> p >> q;
  int i1 = 0, i2 = 0;
  for (int i = 0; i < (n); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[i] = x / p;
    b[i] = y / q;
    if (a[i] >= b[i]) {
      a1[i1] = a[i];
      b1[i1] = b[i];
      c1[i1] = a1[i1] + b1[i1];
      i1++;
    } else {
      a2[i2] = a[i];
      b2[i2] = b[i];
      c2[i2] = a2[i2] + b2[i2];
      i2++;
    }
  }
  vector<pair<int, int> > v;
  v.push_back(make_pair(max_element(a1, a1 + i1) - a1, 1));
  v.push_back(make_pair(max_element(b1, b1 + i1) - b1, 1));
  v.push_back(make_pair(max_element(c1, c1 + i1) - c1, 1));
  v.push_back(make_pair(max_element(a2, a2 + i2) - a2, 2));
  v.push_back(make_pair(max_element(b2, b2 + i2) - b2, 2));
  v.push_back(make_pair(max_element(c2, c2 + i2) - c2, 2));
  double ans = 3000000;
  for (int i = 0; i < (((int)(v).size())); i++) ans = min(ans, check(v[i]));
  printf("%.10lf", ans);
  return 0;
}
