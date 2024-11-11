#include <bits/stdc++.h>
using namespace std;
double jilu[105];
double dp[105];
int main() {
  int n;
  double bef = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &jilu[i]);
    jilu[i] /= 100;
    dp[i] = jilu[i];
    bef *= jilu[i];
  }
  double nmax;
  double ans = n * bef;
  int next;
  for (int i = n + 1; i <= 4000000; i++) {
    nmax = 0;
    for (int j = 1; j <= n; j++) {
      if (nmax < (dp[j] + (1 - dp[j]) * jilu[j]) / dp[j]) {
        nmax = (dp[j] + (1 - dp[j]) * jilu[j]) / dp[j];
        next = j;
      }
    }
    dp[next] = (dp[next] + (1 - dp[next]) * jilu[next]);
    double tmpans = bef * nmax;
    ans += (tmpans - bef) * i;
    bef = tmpans;
  }
  printf("%.12lf\n", ans);
}
