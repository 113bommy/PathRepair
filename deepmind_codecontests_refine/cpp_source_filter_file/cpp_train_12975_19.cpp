#include <bits/stdc++.h>
using namespace std;
int a[1500];
double s[1005];
int main() {
  int n, r;
  double c = (double)1.7320508075;
  scanf("%d%d", &n, &r);
  int i, j;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 1; i <= n; i++) {
    s[i] = (double)a[i];
  }
  s[1] = (double)r;
  for (i = 2; i <= n; i++) {
    for (j = 1; j < i; j++) {
      int x = a[j];
      if (a[i] == a[j]) {
        double d = s[j] + (double)2 * r;
        s[i] = max(s[i], d);
        continue;
      }
      if ((a[i] >= (x - 2 * r)) && (a[i] <= (x + 2 * r))) {
        double k = a[i] - a[j];
        double f = (double)sqrt((double)4 * r * r - (double)(k * k));
        f = f + (double)s[j];
        s[i] = max(s[i], f);
      }
    }
  }
  for (i = 1; i <= n; i++) printf("%.10lf ", s[i]);
}
