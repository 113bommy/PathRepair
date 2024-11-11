#include <bits/stdc++.h>
using namespace std;
const long double pai = acos(-1.0L);
int read() {
  int x = 0, f = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  return x * f;
}
int n;
long double x[3000], y[3000];
vector<long double> v;
signed main() {
  n = read();
  for (int i = 0; i < n; i++) scanf("%Lf%Lf", &x[i], &y[i]);
  long long ans = 1ll * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
  for (int i = 0; i < n; i++) {
    v.clear();
    for (int j = 0; j < n; j++)
      if (i != j) v.push_back(atan2(x[j] - x[i], y[j] - y[i]));
    sort(v.begin(), v.end());
    register int now = 0;
    long long cnt;
    for (int j = 0; j < n - 1; j++) {
      while (now < j + n - 1) {
        long double tmp = v[now % (n - 1)] - v[j];
        if (tmp < 0) tmp += 2 * pai;
        if (tmp < pai)
          now++;
        else
          break;
      }
      cnt = (now - j - 1);
      ans -= cnt * (cnt - 1) * (cnt - 2) / 6;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
