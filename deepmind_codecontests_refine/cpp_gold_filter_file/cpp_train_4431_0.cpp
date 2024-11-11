#include <bits/stdc++.h>
using namespace std;
int n, m, la = -1;
long long c[100005], ans, sum, o;
bool b[100005];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", c + i);
    sum += c[i];
  }
  c[0] = c[n];
  c[n + 1] = c[1];
  for (int i = 1; i <= n; i++) ans += c[i] * c[i - 1];
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    b[x] = 1;
    ans -= c[x] * (c[x - 1] + c[x] + c[x + 1]);
    ans += c[x] * sum;
    ans -= o * c[x];
    if (la == x - 1) ans += c[x] * c[x - 1];
    o += c[x];
    la = x;
  }
  if (b[1] && b[n]) ans += c[1] * c[n];
  printf("%I64d\n", ans);
  return 0;
}
