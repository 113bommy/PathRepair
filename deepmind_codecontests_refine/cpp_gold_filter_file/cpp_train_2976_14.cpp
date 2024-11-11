#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30) - 1;
const long long linf = (1ll << 62) - 1;
const int N = 1e6 + 100;
int n;
double p;
double a[N], b[N];
bool check(double x) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    double balance = b[i] - a[i] * x;
    sum += max(0.0, -balance);
  }
  return sum <= p * x;
}
int main() {
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    ::a[i] = a;
    ::b[i] = b;
  }
  double l = 0, r = 1e12;
  for (int it = 0; it < 100; it++) {
    double m = (l + r) / 2;
    if (check(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  if ((l + r) / 2 >= 0.9e12) {
    printf("-1\n");
  } else {
    printf("%.20lf\n", (l + r) / 2);
  }
  return 0;
}
