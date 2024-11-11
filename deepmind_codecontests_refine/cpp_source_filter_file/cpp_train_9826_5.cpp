#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
const int maxn = 1000005;
int n;
int a[maxn];
bool vis[maxn];
int main() {
  long long ans = 0LL;
  scanf("%d", &n);
  for (int i = n; i >= 0; i--) {
    if (vis[i]) continue;
    int t = 0, s = 0;
    for (int j = 0; j < 20; j++)
      if (i & (1 << j)) s = j;
    for (int j = s - 1; j >= 0; j--)
      if (!(i & (1 << j))) t |= (1 << j);
    a[i] = t, a[t] = i;
    vis[i] = vis[t] = 1;
    ans += 2 * (i ^ t);
  }
  printf("%I64d\n", ans);
  for (int i = 0; i < n; i++) printf("%I64d ", a[i]);
  printf("%I64d\n", a[n]);
  return 0;
}
