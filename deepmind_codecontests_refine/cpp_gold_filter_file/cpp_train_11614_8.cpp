#include <bits/stdc++.h>
using namespace std;
const int N = 15, INF = 0x3f3f3f3f;
int n, h[N], mx = INF, a, b;
vector<int> ans, t;
void dfs(int i, int cnt) {
  if (cnt >= mx) return;
  if (i == n) {
    if (h[n] < 0 && cnt < mx) {
      ans = t;
      mx = cnt;
    }
    return;
  }
  int k = max(h[i - 1] / b + 1, max(h[i] / a + 1, h[i + 1] / b + 1));
  for (int j = 0; j <= k; j++)
    if (h[i - 1] < j * b) {
      h[i - 1] -= j * b;
      h[i + 1] -= j * b;
      h[i] -= j * a;
      for (int x = 0; x < j; x++) t.push_back(i);
      dfs(i + 1, cnt + j);
      h[i - 1] += j * b;
      h[i + 1] += j * b;
      h[i] += j * a;
      for (int x = 0; x < j; x++) t.pop_back();
    }
}
int main() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  dfs(2, 0);
  printf("%d\n", mx);
  for (int i = 0; i < mx; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
