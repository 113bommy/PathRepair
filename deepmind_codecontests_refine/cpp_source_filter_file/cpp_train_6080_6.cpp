#include <bits/stdc++.h>
using namespace std;
const int maxn = 30005;
char ch[10];
int n, h;
double pw2[maxn], ipw2[maxn];
int main() {
  scanf("%s%d%d", ch, &n, &h);
  if (ch[0] == 'B')
    printf("%d\n", n);
  else {
    pw2[0] = ipw2[0] = 1.0;
    for (int i = 1; i <= n; i++)
      pw2[i] = 2.0 * pw2[i - 1], ipw2[i] = 0.5 * ipw2[i - 1];
    double ans = n;
    for (int i = 1; i <= h; i++) {
      double pw = 1.0;
      for (int j = 1; j <= n - 1; j++) {
        double prob = ipw2[i] * ipw2[i] * pw;
        double dlt = pw2[i] - pw2[i - 1] * (double(j - 1) / (pw2[i] - 1.0) + 1);
        ans += (n - j) * prob * dlt;
        pw *= 1.0 - ipw2[i];
      }
    }
    printf("%.10lf\n", ans);
  }
  return 0;
}
