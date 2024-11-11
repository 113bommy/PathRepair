#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char p[N];
int n, c, d, t[N];
int main() {
  scanf("%d%d%d", &n, &c, &d);
  for (int i = 0; i < n; i++) scanf("%d%s", &t[i], &p[i]);
  scanf("%d", &t[n]);
  p[n] = 'X';
  long long ans = d * n, s = 0;
  int last = t[n];
  for (int i = n - 1; i >= 0; i--) {
    if (p[i + 1] == p[i])
      s += min(d, (last - t[i + 1]) * c);
    else
      last = t[i + 1];
    ans = min(ans, s + 1ll * c * (t[n] - t[i]) + 1ll * d * i);
  }
  printf("%lld\n", ans);
  return 0;
}
