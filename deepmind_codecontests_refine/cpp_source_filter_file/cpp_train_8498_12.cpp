#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, dp[N], l, r;
struct Box {
  int v, tp;
} a[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> l >> r;
  int sum = 0;
  for (int i = 1; i <= n; i++) cin >> a[i].v, sum += a[i].v;
  for (int i = 1; i <= n; i++) cin >> a[i].tp;
  sort(a + 1, a + n + 1,
       [](Box a, Box b) { return a.tp < b.tp || (a.tp == b.tp && a.v < b.v); });
  int tmp = l;
  l = sum - r;
  r = sum - tmp;
  for (int i = 1; i <= sum; i++) dp[i] = INT_MIN >> 2;
  dp[0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = sum; j >= a[i].v; --j)
      dp[j] = max(dp[j], dp[j - a[i].v] + a[i].tp * (l <= j && j <= r));
  cout << *max_element(dp + 1, dp + sum + 1) << endl;
  return 0;
}
