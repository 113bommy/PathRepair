#include <bits/stdc++.h>
using namespace std;
long double ang[1000000];
long long s[1000000], g[1000000];
int main() {
  const long double pi = atan2((long double)(0.0), (long double)(-1.0));
  const long double eps = 1e-18;
  long long c, d, x, y;
  long long i, j, k, n, m, ans = 0;
  cin >> n >> c >> d;
  for (i = 1; i <= n; i++) {
    scanf("%I64d%I64d", &x, &y);
    ang[i] = (long double)atan2((long double)(y - d), (long double)(x - c));
    if (ang[i] < 0) ang[i] += (long double)(2.0) * pi;
  }
  sort(ang + 1, ang + 1 + n);
  for (i = 1; i <= n; i++) ang[n + i] = ang[i] + (long double)(2.0) * pi;
  j = 0;
  for (i = 1; i <= n; i++) {
    while (ang[j + 1] - ang[i] < pi - eps) j++;
    s[i] = j;
  }
  for (i = 1; i <= n; i++) s[i + n] = s[i] + n;
  for (i = 2; i <= n * 2; i++) s[i] += s[i - 1];
  j = 0;
  for (i = 1; i <= n; i++) {
    while (ang[j + 1] - ang[i] < pi + eps) j++;
    g[i] = j;
  }
  long long l = 1, r = 0;
  for (i = 1; i <= n; i++) {
    while (ang[l] - ang[i] < eps) l++;
    while (ang[r + 1] - ang[i] < pi - eps) r++;
    if (ang[l] - ang[i] > eps) ans += (s[r] - s[l - 1]) - g[i] * (r - l + 1);
  }
  cout << ans / 3;
}
