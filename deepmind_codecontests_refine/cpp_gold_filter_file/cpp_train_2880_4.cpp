#include <bits/stdc++.h>
using namespace std;
double p[110];
void lemon() {
  int n;
  scanf("%d", &n);
  for (int i = (0); i <= (n); i++) scanf("%lf", &p[i]);
  double final = 0;
  for (int i = (0); i <= (n / 2); i++) {
    if (i * 2 == n)
      final = max(final, p[i]);
    else
      for (int j = (i + 1); j <= (n); j++) {
        int x = 2 * j - n, y = n - 2 * i;
        if (x < 0) continue;
        final = max(final, (x * p[i] + y * p[j]) / (x + y));
      }
  }
  printf("%.16lf\n", final);
}
int main() {
  ios::sync_with_stdio(true);
  lemon();
  return 0;
}
