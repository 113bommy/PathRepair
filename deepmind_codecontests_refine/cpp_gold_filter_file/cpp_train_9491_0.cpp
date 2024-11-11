#include <bits/stdc++.h>
using namespace std;
struct no {
  int u, to, w;
  bool operator<(const no &a) const { return w < a.w; }
};
no eg[200005 * 5];
int n, m, w[200005], ans = 1e9;
int finds(int x) { return w[x] == x ? x : w[x] = finds(w[x]); }
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) w[i] = i;
  for (int i = 1; i <= m; i++) scanf("%d%d%d", &eg[i].u, &eg[i].to, &eg[i].w);
  sort(eg + 2, eg + m + 1);
  for (int i = 2; i <= m; i++) {
    int x = finds(eg[i].u), y = finds(eg[i].to);
    if (x != y) w[x] = y;
    if (finds(eg[1].u) == finds(eg[1].to)) {
      ans = eg[i].w;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
