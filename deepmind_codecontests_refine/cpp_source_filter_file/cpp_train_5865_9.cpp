#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
A cvt(B x) {
  stringstream ss;
  ss << x;
  A y;
  ss >> y;
  return y;
}
int n, l, v1, v2;
long long a[200001];
double f[100001];
vector<double> e;
int main() {
  cin >> n >> l >> v1 >> v2;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n; i < 2 * n; i++) a[i] = a[i - n] + 2 * l;
  a[2 * n] = a[0] + 4 * l;
  double d = 1.0 * v2 * l / (v1 + v2);
  for (int i = 0; i < n; i++) {
    e.push_back(a[i]);
    double x = a[i] - d;
    if (x < 0) x += 2 * l;
    e.push_back(x);
  }
  sort(e.begin(), e.end());
  int j1 = 0, j2 = 0;
  for (int i = 0; i < e.size(); i++) {
    double e1 = e[i], e2;
    if (i + 1 < e.size())
      e2 = e[i + 1];
    else
      e2 = e[0] + 2 * l;
    while (a[j1] < e1 + 1e-9) j1++;
    while (a[j2 + 1] - e1 < d + 1e-9) j2++;
    f[j2 - j1 + 1] += e2 - e1;
  }
  double s = 0;
  for (int i = 1; i <= n; i++) {
    f[i] /= (2.0 * l);
    s += f[i];
  }
  printf("%.11lf\n", 1.0 - s);
  for (int i = 1; i <= n; i++) {
    printf("%.11lf\n", f[i]);
  }
  return 0;
}
