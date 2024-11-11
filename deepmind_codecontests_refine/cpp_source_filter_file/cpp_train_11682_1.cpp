#include <bits/stdc++.h>
using namespace std;
int n, k, l;
double d1[1000010];
int d2[1000010], v[1000010];
char s[1000010];
int solve() {
  double st = 0, dr = n + 1;
  for (int step = 1; step <= 50; step++) {
    double mid = (st + dr) / 2.0;
    for (int i = 1; i <= n; i++) {
      int pos = max(0, i - l);
      if (d1[i - 1] + v[i] <= d1[pos] + mid) {
        d1[i] = d1[i - 1] + v[i];
        d2[i] = d2[i - 1];
      } else {
        d1[i] = d1[pos] + mid;
        d2[i] = d2[pos] + 1;
      }
    }
    if (d2[n] == k) break;
    if (d2[n] > k)
      st = mid;
    else
      dr = mid;
  }
  double mid = (st + dr) / 2.0;
  double c = d1[n] - mid * k;
  return (int)c;
}
int main() {
  scanf("%d%d%d", &n, &k, &l);
  scanf("\n%s", s + 1);
  if (n % l == 0)
    k = min(k, n / l);
  else
    k = min(k, (n / l) + 1);
  for (int i = 1; i <= n; i++)
    if (s[i] >= 'A' && s[i] <= 'Z') v[i] = 1;
  int ans = solve();
  for (int i = 1; i <= n; i++) v[i] = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] >= 'a' && s[i] <= 'z') v[i] = 1;
  ans = min(ans, solve());
  printf("%d", ans);
  return 0;
}
