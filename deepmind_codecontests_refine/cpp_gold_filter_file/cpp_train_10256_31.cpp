#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int m;
int n;
long long zlo;
long long a1[100500], b1[100500], c1[100500], a2[100500], b2[100500],
    c2[100500];
long long a[100500], b[100500];
double check(pair<int, int> o) {
  long long x1, y95874;
  if (o.second == 1) {
    x1 = a1[o.first];
    y95874 = b1[o.first];
  } else {
    x1 = a2[o.first];
    y95874 = b2[o.first];
  }
  double ans = max(zlo / (double)x1, zlo / (double)y95874);
  for (int i = 0; i < (n); i++) {
    long long x2 = a[i];
    long long y2 = b[i];
    ans = min(ans, max(zlo / (double)x2, zlo / (double)y2));
    long long cx1 = x1, cy1 = y95874;
    long long cx2 = x2, cy2 = y2;
    if (cx1 < cy1) {
      swap(cx1, cy1);
      swap(cx2, cy2);
    }
    if (cx2 >= cy2) continue;
    long long d1 = cx1 - cy1;
    long long d2 = cy2 - cx2;
    long long u = (d1 + d2);
    double hx = (double)cx1 * d2 + (double)cx2 * d1;
    double hy = (double)cy1 * d2 + (double)cy2 * d1;
    ans = min(ans, zlo / min(hx, hy) * u);
  }
  return ans;
}
int main() {
  cin >> n;
  long long p, q;
  cin >> p >> q;
  zlo = p * q;
  int i1 = 0, i2 = 0;
  for (int i = 0; i < (n); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[i] = x * q;
    b[i] = y * p;
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
