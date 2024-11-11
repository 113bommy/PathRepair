#include <bits/stdc++.h>
using namespace std;
int s[1005];
int a1[200005], a2[200005];
int p1, p2;
double eps = 1e-8;
double fx(double x) {
  if (x < eps) return 0;
  return x;
}
int main() {
  int n, m, h;
  scanf("%d%d%d", &n, &m, &h);
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &s[i]);
    sum += s[i];
  }
  if (sum < n)
    printf("-1.0\n");
  else if (sum == 1)
    printf("0.0\n");
  else if (sum - 1 - s[h] <= 0)
    printf("1.0\n");
  else {
    sum = sum - 1, n = n - 1;
    s[h] = s[h] - 1;
    int ta = sum - n, tb = sum;
    int i;
    for (i = 0; i < s[h]; i++) {
      a1[i] = ta;
      ta--;
    }
    for (i = 0; i < s[h]; i++) {
      a2[i] = tb;
      tb--;
    }
    double r = 1.0;
    for (i = 0; i < s[h]; i++) r = r / ((double)a2[i]) * ((double)a1[i]);
    r = 1.0 - r;
    printf("%.7lf\n", fx(r));
  }
}
