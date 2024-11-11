#include <bits/stdc++.h>
using namespace std;
long long mi[1000100];
vector<int> des[1000100];
int x[100010], y[100010];
map<int, int> mp;
bool vis[1000100];
pair<int, int> dfs(int s) {
  vis[s] = true;
  pair<int, int> p = make_pair(1, 0);
  for (int k = 0; k < des[s].size(); k++) {
    p.second++;
    if (!vis[des[s][k]]) {
      pair<int, int> q = dfs(des[s][k]);
      p.first += q.first;
      p.second += q.second;
    }
  }
  return p;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    mp[x[i]] = 0;
    mp[y[i]] = 0;
  }
  int tp = 0;
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    it->second = ++tp;
  for (int i = 1; i <= n; i++) {
    x[i] = mp[x[i]];
    y[i] = mp[y[i]];
    des[x[i]].push_back(y[i] + tp);
    des[y[i] + tp].push_back(x[i]);
  }
  long long ans = 1;
  mi[0] = 1;
  for (int i = 1; i <= 2 * tp; i++) mi[i] = mi[i - 1] * 2 % 1000000007;
  for (int i = 1; i <= 2 * tp; i++)
    if (!vis[i]) {
      pair<int, int> p = dfs(i);
      if (p.first > p.second / 2)
        ans = ans * (mi[p.first] - 1) % 1000000007;
      else
        ans = ans * mi[p.first] % 1000000007;
    }
  cout << ans << endl;
}
