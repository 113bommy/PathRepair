#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, dx, dy;
  scanf("%d%d%d%d", &n, &m, &dx, &dy);
  int x = 0, y = 0;
  vector<int> g(n);
  for (int i = 1; i < n; ++i) {
    x = (x + dx) % n;
    y = (y + dy) % n;
    g[x] = y;
  }
  vector<int> cnt(n);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    ++cnt[(y - g[x] + n) % n];
  }
  int max_cnt = -1;
  for (int i = 0; i < n; ++i) {
    if (cnt[i] > max_cnt) {
      max_cnt = cnt[i];
      y = i;
    }
  }
  printf("0 %d\n", y);
}
int main() {
  {
    ios::sync_with_stdio(false), cin.tie(nullptr),
        cout << fixed << setprecision(10);
  }
  solve();
  return 0;
}
