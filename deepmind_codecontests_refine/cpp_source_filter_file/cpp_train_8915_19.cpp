#include <bits/stdc++.h>
using namespace std;
int n, a[200010];
int dp[200010][2];
int b[200010];
int tree[3][200010 * 2];
void Update(int k, int i, int x) {
  for (; i <= b[0]; tree[k][i] = max(tree[k][i], x), i += i & -i)
    ;
}
int Prefix(int k, int i) {
  int res = 0;
  for (; i; res = max(res, tree[k][i]), i -= i & -i)
    ;
  return res;
}
void Init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i), a[i] -= i;
    b[++b[0]] = a[i];
    b[++b[0]] = a[i] + 1;
  }
  sort(b + 1, b + 1 + b[0]);
  b[0] = unique(b + 1, b + 1 + b[0]) - b - 1;
}
void Work() {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = Prefix(0, lower_bound(b + 1, b + 1 + b[0], a[i]) - b) + 1;
    dp[i][1] = max(Prefix(1, lower_bound(b + 1, b + 1 + b[0], a[i]) - b),
                   Prefix(2, lower_bound(b + 1, b + 1 + b[0], a[i] + 1) - b)) +
               1;
    ans = max(ans, dp[i][0]);
    ans = max(ans, dp[i][1]);
    Update(0, lower_bound(b + 1, b + 1 + b[0], a[i]) - b, dp[i][0]);
    Update(1, lower_bound(b + 1, b + 1 + b[0], a[i]) - b, dp[i][1]);
    if (i > 1)
      Update(2, lower_bound(b + 1, b + 1 + b[0], a[i - 1]) - b, dp[i - 1][0]);
  }
  printf("%d\n", max(n - 1 - ans, 0));
}
int main() {
  Init();
  Work();
  return 0;
}
