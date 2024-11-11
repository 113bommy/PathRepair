#include <bits/stdc++.h>
using namespace std;
const int LIM = 1e6;
int n, m, y, l, r, a[LIM + 2], b[LIM + 2];
vector<int> first[LIM + 2], last[LIM + 2];
int aib[LIM + 2];
void update(int x, int p) {
  for (int i = x; i <= LIM; i += (i & -i)) aib[i] += p;
}
int query(int x) {
  int s = 0;
  if (x < 0) return 0;
  for (int i = x; i; i -= (i & -i)) s += aib[i];
  return s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> y >> l >> r;
    if (l == 0 && r == LIM) ans++;
    first[l].push_back(y + 1);
    last[r].push_back(y + 1);
  }
  for (int i = 1; i <= m; i++) {
    cin >> y >> l >> r;
    if (l == 0 && r == LIM) ans++;
    a[y] = l + 1;
    b[y] = r + 1;
  }
  for (int i = 0; i <= LIM; i++) {
    for (auto it : first[i]) update(it, 1);
    ans += query(b[i]) - query(a[i] - 1);
    for (auto it : last[i]) update(it, -1);
  }
  cout << ans + 1;
  return 0;
}
