#include <bits/stdc++.h>
using namespace std;
int n, x, y, vst[203005], par[203005], cnt;
bool flag;
vector<int> adj[200305];
map<int, int> redx, redy;
int cntx, cnty;
long long two[200005], ans;
void dfs(int cur) {
  cnt++;
  vst[cur] = 1;
  for (auto nex : adj[cur])
    if (nex != par[cur]) {
      if (vst[nex]) {
        flag = true;
        continue;
      }
      par[nex] = cur;
      dfs(nex);
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  cnty = n + 2;
  for (int i = (1); i <= (n); i++) {
    cin >> x >> y;
    if (redx.count(x))
      x = redx[x];
    else {
      redx[x] = ++cntx;
      x = cntx;
    }
    if (redy.count(y))
      y = redy[y];
    else {
      redy[y] = ++cnty;
      y = cnty;
    }
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  two[0] = 1;
  for (int i = (1); i <= (200003); i++) {
    two[i] = 2 * two[i - 1];
    two[i] %= 1000000007;
  }
  assert(cntx <= n + 2);
  ans = 1;
  for (int i = (1); i <= (cntx); i++)
    if (!vst[i]) {
      flag = false;
      cnt = 0;
      dfs(i);
      if (flag) {
        ans *= two[cnt];
        ans %= 1000000007;
      } else {
        ans *= (two[cnt] + 1000000007 - 1);
        ans %= 1000000007;
      }
    }
  for (int i = (n + 3); i <= (cnty); i++) assert(vst[i]);
  cout << ans;
}
