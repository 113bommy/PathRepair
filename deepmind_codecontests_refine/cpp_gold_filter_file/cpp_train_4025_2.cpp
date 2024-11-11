#include <bits/stdc++.h>
using namespace std;
int hh, mm, h, d, c, n;
int main() {
  scanf("%d %d %d %d %d %d", &hh, &mm, &h, &d, &c, &n);
  int ti = hh * 60 + mm;
  double ans;
  if (ti >= 20 * 60) {
    int n1 = h / n + (h % n == 0 ? 0 : 1);
    ans = 0.8 * n1 * c;
  } else {
    int h2 = h + (20 * 60 - ti) * d;
    int n1 = h / n + (h % n == 0 ? 0 : 1);
    int n2 = h2 / n + (h2 % n == 0 ? 0 : 1);
    ans = min(0.8 * n2 * c, 1.0 * n1 * c);
  }
  printf("%.6f\n", ans);
}
