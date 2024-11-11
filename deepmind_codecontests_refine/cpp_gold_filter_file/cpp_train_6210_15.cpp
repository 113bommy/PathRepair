#include <bits/stdc++.h>
using namespace std;
const int Dim = 2e5 + 5;
int c[Dim], aib[Dim], st[Dim], dr[Dim];
int n, m, x, y, ans;
int query(int pos) {
  int ans = 0;
  while (pos >= 1) {
    ans = max(ans, aib[pos]);
    pos -= pos & (pos ^ (pos - 1));
  }
  return ans;
}
void update(int pos, int val) {
  while (pos <= m + 1) {
    aib[pos] = max(aib[pos], val);
    pos += pos & (pos ^ (pos - 1));
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> x >> y;
    ++c[x];
    --c[y + 1];
  }
  for (int i = 1; i <= m; ++i) {
    c[i] += c[i - 1];
  }
  for (int i = 1; i <= m; ++i) {
    ++c[i];
  }
  for (int i = 1; i <= m; ++i) {
    st[i] = query(c[i]) + 1;
    update(c[i], st[i]);
  }
  memset(aib, 0, sizeof(aib));
  for (int i = m; i >= 1; --i) {
    dr[i] = query(c[i]) + 1;
    update(c[i], dr[i]);
  }
  for (int i = 1; i <= m; ++i) {
    ans = max(ans, st[i] + dr[i] - 1);
  }
  cout << ans << '\n';
  return 0;
}
