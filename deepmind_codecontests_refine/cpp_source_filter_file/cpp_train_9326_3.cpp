#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
int prnt[300000], ara[300000];
pair<int, int> chlds[300000];
map<int, int> ok;
int ppp = 0;
int ans;
void dfs(int pos, int low, int high) {
  if (ara[pos] < low || ara[pos] > high) {
    if (ok[ara[pos]] != -1) ok[ara[pos]]++;
  } else {
    ok[ara[pos]] = -1;
  }
  if (chlds[pos].first != -1) {
    dfs(chlds[pos].first, low, min(high, ara[pos]));
  }
  if (chlds[pos].second != -1) {
    dfs(chlds[pos].second, max(low, ara[pos]), high);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &z, &x, &y);
    chlds[i] = make_pair(x, y);
    ara[i] = z;
    if (x != -1) prnt[x] = i;
    if (y != -1) prnt[y] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (prnt[i] == 0) {
      ppp = i;
    }
  }
  dfs(ppp, 1, 1000000000);
  for (auto it : ok) {
    if (it.second != -1) ans += it.second;
  }
  cout << ans << endl;
  return 0;
}
