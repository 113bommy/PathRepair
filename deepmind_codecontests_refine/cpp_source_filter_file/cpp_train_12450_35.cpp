#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int maxn = 1e5 + 10;
int n, p, a[maxn], b[maxn];
int getp(double t) {
  bool flag = false;
  double v = 0;
  for (int i = 0; i < n; i++) {
    double k = a[i] * t - b[i];
    if (k <= 0) continue;
    v += k / t;
    flag = true;
  }
  if (p >= v) return 1;
  return 0;
}
int main() {
  while (~scanf("%d%d", &n, &p)) {
    long long sum = 0;
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]), sum += a[i];
    double right = 1e9, left = 0.0, mid;
    bool flag = false;
    if (sum <= p)
      flag = true;
    else {
      while (right - left >= eps) {
        mid = (right + left) / 2;
        int k = getp(mid);
        if (k == 1)
          left = mid;
        else if (!k)
          right = mid;
      }
    }
    if (flag)
      puts("-1");
    else
      cout << mid << endl;
  }
}
