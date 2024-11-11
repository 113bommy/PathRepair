#include <bits/stdc++.h>
using namespace std;
struct node {
  int va, id;
} a[200015], b[200015];
int n, Q, rv[200015];
long long dp[200015];
inline bool cmp(node x, node y) { return x.va > y.va; }
int main() {
  scanf("%d%d", &n, &Q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].va), a[i].id = i;
  for (int i = 1; i <= n; i++) scanf("%d", &b[i].va), b[i].id = i;
  sort(a + 1, a + 1 + n, cmp);
  sort(b + 1, b + 1 + n, cmp);
  for (int i = 1; i <= n; i++) rv[b[i].id] = i;
  while (Q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    swap(rv[x], rv[y]);
    b[rv[x]].id = x, b[rv[y]].id = y;
    for (int i = 1; i <= n; i++) {
      dp[i] = 0;
      if (a[i].id ^ b[i].id)
        dp[i] = max(dp[i], dp[i - 1] + 1ll * a[i].va * b[i].va);
      if (i > 1) {
        if ((a[i].id ^ b[i - 1].id) && (a[i - 1].id ^ b[i].id)) {
          dp[i] = max(dp[i], dp[i - 2] + 1ll * a[i].va * b[i - 1].va +
                                 1ll * a[i - 1].va * b[i].va);
        }
      }
      if (i > 2) {
        if ((a[i].id ^ b[i - 2].id) && (a[i - 1].id ^ b[i].id) &&
            (a[i - 2].id ^ b[i - 1].id)) {
          dp[i] = max(dp[i], dp[i - 3] + 1ll * a[i - 2].va * b[i - 1].va +
                                 1ll * a[i - 1].va * b[i].va +
                                 1ll * a[i].va * b[i - 2].va);
        }
        if ((a[i - 2].id ^ b[i].id) && (a[i - 1].id ^ b[i - 2].id) &&
            (a[i].id ^ b[i - 1].id)) {
          dp[i] = max(dp[i], dp[i - 3] + 1ll * a[i - 2].va * b[i].va +
                                 1ll * a[i - 1].va * b[i - 2].va +
                                 1ll * a[i].va * b[i - 1].va);
        }
        if ((a[i].id ^ b[i - 2].id) && (a[i - 2].id ^ b[i].id) &&
            (a[i - 1].id ^ b[i - 1].id)) {
          dp[i] = max(dp[i], dp[i - 3] + 1ll * a[i].va * b[i - 2].va +
                                 1ll * a[i - 1].va * b[i - 1].va +
                                 1ll * a[i - 2].va * b[i].va);
        }
      }
    }
    printf("%lld\n", dp[n]);
  }
}
