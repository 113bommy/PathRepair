#include <bits/stdc++.h>
using namespace std;
int n, m;
int nxt[500005][20];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    l++, r++;
    nxt[l][0] = max(nxt[l][0], r);
  }
  for (int i = 0; i < 500004; i++) {
    nxt[i + 1][0] = max(nxt[i][0], nxt[i + 1][0]);
  }
  for (int l = 1; l < 20; l++) {
    for (int i = 0; i < 500005; i++) {
      nxt[i][l] = nxt[nxt[i][l - 1]][l - 1];
    }
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x++, y++;
    int ans = 1;
    for (int j = 19; j >= 0; j--) {
      if (nxt[x][j] < y) {
        x = nxt[x][j];
        ans += 1 << j;
      }
    }
    if (nxt[x][0] < y) {
      ans = -1;
    }
    cout << ans << "\n";
  }
}
