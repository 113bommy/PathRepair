#include <bits/stdc++.h>
long long P[121212];
long long PH[121212];
long long Q[121212];
long long QH[121212];
long long a[121212];
long long max(long long a, long long b) {
  if (a < b) return b;
  return a;
}
long long min(long long a, long long b) {
  if (a > b) return b;
  return a;
}
int main() {
  long long n;
  long long i;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  P[1] = 0;
  PH[1] = a[1];
  for (i = 2; i <= n; i++) {
    P[i] = P[i - 1];
    PH[i] = a[i];
    if (PH[i - 1] + 1 > a[i]) {
      P[i] += PH[i - 1] + 1 - a[i];
      PH[i] = PH[i - 1] + 1;
    }
  }
  Q[n] = 0;
  QH[n] = a[n];
  for (i = n - 1; i >= 1; i--) {
    Q[i] = Q[i + 1];
    QH[i] = a[i];
    if (QH[i + 1] + 1 > a[i]) {
      Q[i] += QH[i + 1] + 1 - a[i];
      QH[i] = QH[i + 1] + 1;
    }
  }
  long long ans = -1;
  for (i = 1; i <= n; i++) {
    long long now = max(QH[i], PH[i]) - a[i] + P[i - 1] + Q[i + 1];
    if (ans == -1 || ans > now) ans = now;
  }
  printf("%lld", ans);
  return 0;
}
