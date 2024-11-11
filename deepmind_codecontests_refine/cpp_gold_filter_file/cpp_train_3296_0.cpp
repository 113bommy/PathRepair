#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int u[N], v[N], tot, n, d[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
  for (int i = 1; i <= n; i++)
    for (int s = d[i]; s > d[i - 1]; s--)
      for (int t = d[n + 1 - i] + 1; t > s; t--) u[tot] = s, v[tot] = t, tot++;
  printf("%d\n", tot);
  for (int i = 0; i < tot; i++) printf("%d %d\n", u[i], v[i]);
}
