#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n;
double m;
double eps = 1e-6;
double a[maxn], b[maxn];
int main() {
  scanf("%d", &n);
  scanf("%lf", &m);
  int flag = 0;
  double t = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &a[i]);
    if (a[i] == t) {
      flag = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &b[i - 1]);
    if (b[i] == t) {
      flag = 1;
    }
  }
  b[n] = b[0];
  if (flag == 1) {
    cout << "-1" << endl;
    return 0;
  }
  double k = m;
  for (int i = n; i >= 1; i--) {
    m = m * (b[i] / (b[i] - 1));
    m = m * (a[i] / (a[i] - 1));
  }
  if (m > 1e9 + eps) {
    cout << -1 << endl;
  } else {
    printf("%.6f\n", m - k);
  }
  return 0;
}
