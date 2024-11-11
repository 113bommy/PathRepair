#include <bits/stdc++.h>
using namespace std;
int n;
int p[300010];
int q[300010];
int pos[300010];
int lazy[300010 * 4];
int mn[300010 * 4];
void modify(int ind, int l, int r, int s, int e, int dx) {
  if (r < s || l > e) return;
  if (s <= l && r <= e) {
    lazy[ind] += dx;
    mn[ind] += dx;
    return;
  }
  int m = (l + r) / 2;
  int ind2 = ind * 2;
  modify(ind2 + 1, l, m, s, e, dx);
  modify(ind2 + 2, m + 1, r, s, e, dx);
  mn[ind] = min(mn[ind2 + 1], mn[ind2 + 2]) + lazy[ind];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    pos[p[i]] = i;
  }
  for (int i = 1; i <= n; i++) cin >> q[i];
  int ans = n;
  for (int i = 1; i <= n; i++) {
    while (1) {
      modify(0, 1, n, 1, pos[ans], -1);
      if (mn[0] < 0) {
        modify(0, 1, n, 1, pos[ans], 1);
        break;
      }
      ans--;
    }
    cout << ans << ' ';
    modify(0, 1, n, 1, q[i], 1);
  }
  return 0;
}
