#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n, m, st[500005 + 5][30];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  int lg = ceil(log2(n));
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    st[l][0] = max(st[l][0], r);
  }
  for (int i = 0; i <= 5e5; i++) st[i][0] = max(st[i][0], st[i - 1][0]);
  for (int i = 1; i <= lg; i++) {
    for (int j = 0; j <= 5e5; j++) st[j][i] = st[st[j][i - 1]][i - 1];
  }
  while (m--) {
    int l, r, ans = 0;
    cin >> l >> r;
    for (int i = lg; i >= 0; i--) {
      if (st[l][i] < r) {
        l = st[l][i];
        ans += (1 << i);
      }
    }
    if (st[l][0] < r)
      cout << -1 << endl;
    else
      cout << ans + 1 << endl;
  }
}
