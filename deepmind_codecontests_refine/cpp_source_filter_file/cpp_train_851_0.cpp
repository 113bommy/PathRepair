#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff, MAXN = 2e6 + 10;
long long ans;
struct Node {
  int id, val;
} a[MAXN];
int b[MAXN], _next[MAXN];
int dp[MAXN];
bool cmp(Node a, Node b) { return a.val < b.val; }
int res[MAXN], tt[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].val), a[i].id = i;
  sort(a + 1, a + n + 1, cmp);
  a[0].val = -1;
  for (int i = 2; i <= n; i++) b[i] = a[i].val - a[i - 1].val;
  long long sum = a[n].val - a[1].val;
  if (n < 6) {
    printf("%lld 1\n", sum);
    for (int i = 1; i <= n; i++) cout << "1 ";
    return 0;
  }
  long long maxn = 0;
  int id = 0;
  for (int i = 4; i <= n; i++) {
    if (i >= 4) {
      if (max(dp[i - 3], b[i - 3]) > maxn) {
        maxn = dp[i - 3];
        id = i - 3;
      }
    }
    dp[i] = maxn + b[i];
    _next[i] = id;
  }
  int now = n - 2;
  if (dp[n - 3] > dp[now]) now = n - 3;
  if (dp[n - 4] > dp[now]) now = n - 4;
  int j = 1;
  printf("%lld ", sum - dp[now]);
  for (int i = now; i; i = _next[i], j++) {
    if (i < 3) break;
    res[i - 1] = j;
  }
  res[n] = j;
  for (int i = n; i; i--)
    if (!res[i]) res[i] = res[i + 1];
  printf("%d\n", j);
  for (int i = 1; i <= n; i++) tt[a[i].id] = res[i];
  for (int i = 1; i <= n; i++) printf("%d ", tt[i]);
  return 0;
}
