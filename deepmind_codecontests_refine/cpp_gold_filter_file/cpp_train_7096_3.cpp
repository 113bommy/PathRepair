#include <bits/stdc++.h>
using namespace std;
int n, m, to[1001], tp, t[1001], l[1001], r[1001];
int main() {
  scanf("%d %d", &n, &m);
  tp = n + 1;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &t[i], &l[i], &r[i]);
    if (!t[i]) continue;
    for (int j = l[i]; j <= r[i]; j++) to[j] = max(to[j], r[i]);
  }
  for (int i = n; i; i--) to[i] = to[to[i]];
  for (int i = 1; i <= m; i++) {
    if (t[i]) continue;
    if (to[l[i]] >= r[i]) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  for (int i = 1; i <= n; i++) {
    if (to[i - 1] >= i)
      printf("%d ", tp);
    else
      printf("%d ", --tp);
  }
}
