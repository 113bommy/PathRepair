#include <bits/stdc++.h>
using namespace std;
const int MaxN = 5 * 1e5 + 5;
int n, d[MaxN], t[MaxN], p[MaxN], c, res, a[MaxN];
int main() {
  scanf("%d%d", &n, &c);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == c)
      d[i] = d[i - 1] + 1;
    else
      d[i] = d[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    t[a[i]]++;
    if (t[a[i]] == 1) p[a[i]] = d[i - 1];
    res = max(res, t[a[i]] + p[a[i]] + d[n] - d[i]);
    p[a[i]] = max(p[a[i]], d[i - 1] - t[a[i]] + 1);
  }
  printf("%d", res);
}
