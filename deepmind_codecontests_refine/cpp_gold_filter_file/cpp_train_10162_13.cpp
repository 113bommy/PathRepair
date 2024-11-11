#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > v[100100];
int dist[100100];
void dfs(int now) {
  for (int i = 0; i < (int)v[now].size(); i++) {
    if (dist[v[now][i].first] < 0) {
      dist[v[now][i].first] = dist[now] ^ v[now][i].second;
      dfs(v[now][i].first);
    }
  }
}
set<int> x;
bitset<100100> e[33];
int key[100100];
int res[33];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    v[a].push_back(make_pair(b, c));
    v[b].push_back(make_pair(a, c));
  }
  memset(dist, -1, sizeof(dist));
  dist[0] = 0;
  dfs(0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int)v[i].size(); j++) {
      x.insert(dist[v[i][j].first] ^ dist[i] ^ v[i][j].second);
    }
  }
  int cnt = 0;
  for (set<int>::iterator it = x.begin(); it != x.end(); it++, cnt++) {
    for (int j = 0; j < 31; j++) e[j][cnt] = ((*it) >> j) & 1;
  }
  memset(key, -1, sizeof(key));
  int ans = 0;
  for (int j = 30; j >= 0; j--) {
    int val = (dist[n - 1] >> j) & 1;
    res[j] = 0;
    bool found = 0;
    for (int i = 0; i < (int)x.size(); i++) {
      if (!e[j][i]) continue;
      if (key[i] >= 0)
        e[j] ^= e[key[i]], res[j] ^= res[key[i]];
      else {
        key[i] = j;
        found = 1;
        break;
      }
    }
    if (!found && res[j] != val) {
      ans += (1 << j);
    } else
      res[j] ^= val;
  }
  cout << ans << endl;
  return 0;
}
