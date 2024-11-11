#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int a[maxn], b[maxn];
int n, p, q;
void init() {
  cin >> n >> p >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
}
double get_result(double x) {
  double y = 1.0;
  for (int i = 0; i < n; i++) {
    y = min(y, (1.0 - a[i] * x) / b[i]);
  }
  return x * p + y * q;
}
int main() {
  init();
  double l = 0;
  double r = 1.0 / (*max_element(b, b + n));
  double ml, mr;
  for (int i = 0; i < 200; i++) {
    ml = (l + l + r) / 3;
    mr = (l + r + r) / 3;
    if (get_result(ml) > get_result(mr)) {
      r = mr;
    } else {
      l = ml;
    }
  }
  printf("%.10f\n", get_result((r + l) * 0.5));
  return 0;
}
