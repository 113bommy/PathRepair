#include <bits/stdc++.h>
const double PI = acos(-1);
using namespace std;
int tr[1000010];
vector<int> Lx[1000010], Rx[1000010];
vector<pair<int, int> > ver[1000010];
int sum(int i) {
  int ans = 0;
  while (i > 0) {
    ans += tr[i];
    i -= (i & -i);
  }
  return ans;
}
void update(int i, int val) {
  while (i < 1000010) {
    tr[i] += val;
    i += (i & -i);
  }
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    int y, l, r;
    cin >> y >> l >> r;
    Lx[l].push_back(y);
    Rx[r + 1].push_back(y);
    if (l == 0 && r == 1000000) ans++;
  }
  for (int i = 0; i <= 1000000; i++) ver[i].clear();
  for (int i = 1; i <= m; i++) {
    int x, l, r;
    cin >> x >> l >> r;
    ver[x].push_back({l, r});
    if (l == 0 && r == 1000000) ans++;
  }
  for (int i = 0; i <= 1000000; i++) {
    for (int y : Lx[i]) update(y, 1);
    for (int y : Rx[i]) update(y, -1);
    for (pair<int, int> p : ver[i]) {
      if (p.first == 0) {
        ans += sum(p.second);
      } else {
        ans += sum(1000000) - sum(p.first - 1);
      }
    }
  }
  cout << ans << '\n';
}
