#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int v, next;
} e[100005];
map<string, int> mp;
vector<string> name;
int start[100005], tot;
void _add(int u, int v) {
  e[tot].v = v;
  e[tot].next = start[u];
  start[u] = tot++;
}
void addedge(int u, int v) {
  _add(u, v);
  _add(v, u);
}
int main() {
  int m, cnt = 0, tot = 0;
  memset(start, -1, sizeof(start));
  cin >> m;
  while (m--) {
    string s1, s2;
    cin >> s1 >> s2;
    if (mp.find(s1) == mp.end()) {
      mp[s1] = cnt++;
      name.push_back(s1);
    }
    if (mp.find(s2) == mp.end()) {
      mp[s2] = cnt++;
      name.push_back(s2);
    }
    int u = mp[s1], v = mp[s2];
    addedge(u, v);
  }
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++) {
    bool vis[5005];
    memset(vis, false, sizeof(vis));
    for (int j = start[i]; j != -1; j = e[j].next) vis[e[j].v] = true;
    vis[i] = true;
    int ans = 0, mmax = -1;
    for (int k = 0; k < cnt; k++) {
      if (vis[k]) continue;
      int c = 0;
      for (int j = start[i]; j != -1; j = e[j].next)
        if (!vis[e[j].v]) c++;
      if (c > mmax)
        mmax = c, ans = 1;
      else if (c == mmax)
        ans++;
    }
    cout << name[i] << " " << ans << endl;
  }
  return 0;
}
