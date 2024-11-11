#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int b[maxn], n, flag = 1, dp[maxn];
struct node {
  int id, x;
} a[maxn];
int cmp(node a, node b) { return a.x > b.x; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].x);
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  int k = n / 2 + 1;
  printf("%d\n%d\n", k, a[1].id);
  for (int i = 2; i <= n; i += 2)
    if (b[a[i].id] > b[a[i + 1].id])
      printf("%d\n", a[i].id);
    else
      printf("%d\n", a[i + 1].id);
  return 0;
}
