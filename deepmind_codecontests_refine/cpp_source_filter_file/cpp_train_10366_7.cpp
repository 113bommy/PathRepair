#include <bits/stdc++.h>
using namespace std;
int n, sz;
vector<int> v[25];
void bin(int l, int r, int k) {
  if (l == r) return;
  int mid = (l + r) / 2;
  for (int i = l; i <= mid; ++i)
    if (i <= n) v[k].push_back(i);
  bin(l, mid, ++k);
  for (int i = mid + 1; i <= r; ++i)
    if (i <= n) v[k].push_back(i);
  bin(mid + 1, r, ++k);
}
void solve() {
  int ans[1100], us[1100];
  fill(ans, ans + 1100, 2e9);
  fill(us, us + 1100, 2e9);
  bin(1, sz, 0);
  for (int i = 0; i < n; ++i) {
    if (!v[i].size()) break;
    printf("%d\n", v[i].size());
    for (auto to : v[i]) {
      us[to] = i;
      printf("%d ", to);
    }
    printf("\n");
    fflush(stdout);
    for (int j = 0; j < n; ++j) {
      int x;
      scanf("%d", &x);
      if (us[j] != i) ans[j] = min(ans[j], x);
    }
    fflush(stdout);
  }
  printf("-1\n");
  for (int i = 0; i < n; ++i) printf("%d ", ans[i] == 2e9 ? 0 : ans[i]);
  fflush(stdout);
  return;
}
int main() {
  scanf("%d", &n);
  for (sz = 1; sz < n; sz *= 2)
    ;
  solve();
}
