#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 3001;
int t, n;
int dp[kMaxN], l[kMaxN], r[kMaxN];
struct E {
  int l, r;
  int v;
  bool operator<(const E &e) const { return r - l < e.r - e.l; }
} e[kMaxN];
void C(int x) {
  fill_n(dp, n + 1, 0);
  for (int i = 0, j = 0, v = 0; i <= n; i++) {
    if (e[l[i]].l >= e[x].l && e[l[i]].r <= e[x].r) {
      for (; j <= n && e[r[j]].r < e[l[i]].l; j++) {
        v = max(v, dp[r[j]]);
      }
      dp[l[i]] = v + e[l[i]].v;
      e[x].v = max(e[x].v, dp[l[i]]);
    }
  }
  e[x].v++;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    l[0] = r[0] = 0;
    e[0] = {0, ~(1 << 31), 0};
    for (int i = 1; i <= n; i++) {
      cin >> e[i].l >> e[i].r;
      l[i] = r[i] = i;
      e[i].v = 0;
    }
    sort(e, e + 1 + n);
    sort(l, l + 1 + n, [](int i, int j) { return e[i].l < e[j].l; });
    sort(r, r + 1 + n, [](int i, int j) { return e[i].r < e[j].r; });
    for (int i = 0; i <= n; i++) {
      C(i);
    }
    cout << e[n].v - 1 << endl;
  }
  return 0;
}
