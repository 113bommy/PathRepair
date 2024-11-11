#include <bits/stdc++.h>
using namespace std;
const int N = 132674, MOD = 1e9 + 7;
pair<pair<int, int>, pair<int, int>> a[N];
int n;
map<pair<pair<int, int>, pair<int, int>>, bool> vis[N];
void solve(int i = 0, int l1 = -1e9, int l2 = -1e9, int r1 = 1e9, int r2 = 1e9,
           int c = 0) {
  if (l1 > r1 || l2 > r2) return;
  if (i == n) {
    cout << l1 << " " << l2 << "\n";
    exit(0);
  }
  bool &x = vis[i][{{l1, l2}, {r1, r2}}];
  if (x) return;
  x = 1;
  if (!c) {
    solve(i + 1, l1, l2, r1, r2, 1);
  }
  solve(i + 1, max(l1, a[i].first.first), max(l2, a[i].first.second),
        min(r1, a[i].second.first), min(r2, a[i].second.second), c);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d", &a[i].first.first, &a[i].first.second,
          &a[i].second.first, &a[i].second.second);
  }
  solve();
  return 0;
}
