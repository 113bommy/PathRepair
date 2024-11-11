#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int a[maxn];
vector<int> g[maxn];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    g[a[i]].push_back(i);
  }
  int k = 0;
  for (int i = 1; i <= n; i++)
    if ((g[i].size() & 1) && ++k > 1) return 0 * puts("0");
  for (k = 1; k <= n / 2; k++)
    if (a[k] != a[n - k + 1]) break;
  if (k == n / 2) return 0 * printf("%I64d\n", (long long)n * (n - 1) / 2);
  long long x = 0, y = n + 1, L, R;
  for (int i = 1; i <= n; i++)
    if (g[i].size()) {
      if (g[i].size() & 1)
        L = R = g[i].size() / 2;
      else
        L = g[i].size() / 2 - 1, R = L + 1;
      while (L >= 0 && g[i][L] + g[i][R] == n + 1) L--, R++;
      if (L < 0) continue;
      x = max(x, (long long)g[i][L]);
      y = min(y, (long long)g[i][R]);
    }
  L = k;
  R = n - k + 1;
  return 0 *
         printf("%I64d\n", L * (n - x + 1) + y * (n - R + 1) - L * (n - R + 1));
}
