#include <bits/stdc++.h>
using namespace std;
int rt[150005];
long long ans[150005];
int fd(int x) {
  if (rt[x] == x) return x;
  return rt[x] = fd(rt[x]);
}
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    int i;
    int x, y, fx, fy;
    for (i = 0; i <= n; i++) rt[i] = i;
    for (i = 0; i < m; i++) {
      scanf("%d%d", &x, &y);
      fx = fd(x);
      fy = fd(y);
      if (fx != fy) rt[fx] = fy;
    }
    memset(ans, 0, sizeof(ans));
    for (i = 1; i <= n; i++) ans[fd(i)]++;
    long long sum = 0;
    for (i = 1; i <= n; i++) {
      if (ans[i] == 0 || ans[i] == 1) continue;
      sum += (ans[i] * (ans[i] - 1) / 2);
    }
    if (sum != m)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
