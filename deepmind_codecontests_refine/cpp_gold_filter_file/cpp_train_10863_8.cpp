#include <bits/stdc++.h>
double sum1[300], sum2[300];
char str1[300000], str2[300000];
int main() {
  double n;
  while (scanf("%lf", &n) != EOF) {
    scanf("%s%s", str1 + 1, str2 + 1);
    double tot = 0.0, tmp = 0.0;
    for (double i = 1; i <= n; i++) tot += i * i;
    memset(sum1, 0, sizeof(sum1));
    memset(sum2, 0, sizeof(sum2));
    for (int i = 1; i <= n; i++) {
      int a = str1[i], b = str2[i];
      tmp += 1.0 * sum1[b] * (n - i + 1);
      tmp += 1.0 * sum2[a] * (n - i + 1);
      sum1[a] += i;
      sum2[b] += i;
      if (a == b) tmp += 1.0 * i * (n - i + 1);
    }
    printf("%.10lf\n", tmp / tot);
  }
  return 0;
}
