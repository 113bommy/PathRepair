#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 500;
const int OFF = (1 << 20);
const int INF = 0x3f3f3f3f;
int n, k, a[N], st[N], cur, dp[N], prop[2 * OFF], tour[2 * OFF], ans[N], C[N],
    nxt[N], L[N], R[N];
vector<int> v[N];
void refresh(int i) {
  if (!prop[i]) return;
  tour[i] += prop[i];
  if (i < OFF) {
    prop[2 * i] += prop[i];
    prop[2 * i + 1] += prop[i];
  }
  prop[i] = 0;
}
void update(int i, int a, int b, int lo, int hi, int x) {
  refresh(i);
  if (lo <= a && b <= hi) {
    prop[i] += x;
    refresh(i);
    return;
  }
  if (a > hi || b < lo) return;
  update(2 * i, a, (a + b) / 2, lo, hi, x);
  update(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, x);
  tour[i] = max(tour[2 * i], tour[2 * i + 1]);
}
void dfs(int x) {
  C[x] = cur++;
  L[x] = C[x];
  for (int y : v[x]) dfs(y);
  R[x] = cur - 1;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  cur = 1, st[0] = n;
  a[n] = n + 1;
  for (int i = n - 1; i >= 0; i--) {
    while (cur > 0 && a[st[cur - 1]] <= a[i]) cur--;
    dp[i] = 1;
    nxt[i] = st[cur - 1];
    v[st[cur - 1]].push_back(i);
    dp[i] = dp[st[cur - 1]] + 1;
    st[cur++] = i;
  }
  cur = 0;
  dfs(n);
  for (int i = 0; i < n; i++) update(1, 0, OFF - 1, C[i], C[i], -INF + dp[i]);
  for (int i = n - 1; i >= 0; i--) {
    update(1, 0, OFF - 1, C[i], C[i], INF);
    if (i + k < n) {
      update(1, 0, OFF - 1, L[i + k], R[i + k], -1);
      update(1, 0, OFF - 1, C[i + k], C[i + k], -INF);
    }
    if (i + k <= n) {
      refresh(1);
      ans[i] = tour[1];
    }
  }
  for (int i = 0; i + k <= n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}
