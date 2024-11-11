#include <bits/stdc++.h>
struct node {
  int val, id;
  bool operator<(node b) const { return val > b.val; }
} a[1010];
int n, ans[1010][1010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].val), a[i].id = i;
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n + 1; i++)
    for (int j = 1; j <= n; j++)
      ans[i][a[j].id] = ((i - j + n + 1) % (n + 1) < a[j].val);
  printf("%d\n", n + 1);
  for (int i = 1; i <= n + 1; i++, puts(""))
    for (int j = 1; j <= n; j++) printf("%d", ans[i][j]);
}
