#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, y, a[N], b[N], pw[31], ans = 2;
void solve(int u) {
  map<int, int> c1, c2;
  int mod = pw[u + 1];
  for (int i = 1; i <= n; i++) c1[a[i] % mod]++;
  for (int i = 1; i <= m; i++) c2[b[i] % mod]++;
  for (int i = 1; i <= n; i++)
    ans = max(ans, c1[a[i] % mod] + c2[(a[i] + pw[u]) % mod]);
  for (int i = 1; i <= m; i++)
    ans = max(ans, c2[b[i] % mod] + c1[(b[i] + pw[u]) % mod]);
}
int main() {
  for (int i = 0; i <= 30; i++) pw[i] = (1 << i);
  scanf("%d%d", &n, &y);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d%d", &m, &y);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  for (int i = 0; i <= 29; i++) solve(i);
  printf("%d\n", ans);
  return 0;
}
