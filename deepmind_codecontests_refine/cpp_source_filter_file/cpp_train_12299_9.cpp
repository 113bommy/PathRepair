#include <bits/stdc++.h>
using namespace std;
int n, c, d, t[100005];
char op[100005];
int main() {
  scanf("%d%d%d", &n, &c, &d);
  for (int i = 0; i < n; i++) scanf("%d%c", &t[i], &op[i]);
  scanf("%d", &t[n]), op[n] = '?';
  long long ans = 1ll * n * d, s = 0;
  int last = t[n];
  for (int i = n - 1; i >= 0; i--) {
    if (op[i] == op[i + 1])
      s += min(1ll * d, 1ll * (last - t[i + 1]) * c);
    else
      last = t[i + 1];
    ans = min(ans, 1ll * d * i + s + 1ll * (t[n] - t[i]) * c);
  }
  printf("%I64d\n", ans);
}
