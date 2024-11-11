#include <bits/stdc++.h>
using namespace std;
int t, n, num, a[200000][2], ans;
vector<int> g[400000], pos[200000], temp;
bool bad, vis[400000], sw[200000];
void dfs(int x) {
  vis[x] = true;
  if (x & 1 ^ 1) num += int(sw[x]);
  for (int i = 0; i < g[x].size(); i++) {
    if (vis[g[x][i]] && (sw[g[x][i]] == sw[x])) bad = true;
    if (!vis[g[x][i]]) sw[g[x][i]] = sw[x] ^ 1, dfs(g[x][i]);
  }
  temp.push_back(x);
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < n; j++) cin >> a[j][i];
    bad = false, ans = 0;
    for (int i = 0; i < n; i++) sw[i] = false;
    for (int i = 0; i < 2 * n; i++) vis[i] = false;
    for (int i = 0; i < n; i++)
      pos[min(a[i][0], n) - 1].push_back(2 * i),
          pos[min(a[i][1], n) - 1].push_back(2 * i + 1);
    for (int i = 0; i < n; i++)
      if (pos[i].size() != 2) bad = true;
    if (!bad) {
      for (int i = 0; i < n; i++)
        g[2 * i].push_back(2 * i + 1), g[2 * i + 1].push_back(2 * i);
      for (int i = 0; i < n; i++)
        g[pos[i][0]].push_back(pos[i][1]), g[pos[i][1]].push_back(pos[i][0]);
      for (int i = 0; i < 2 * n; i++)
        if (!vis[i]) {
          num = 0;
          dfs(i);
          int k = temp.size() / 2;
          if (num > k - num) {
            num = k - num;
            for (int i = 0; i < temp.size(); i++) sw[temp[i]] ^= 1;
          }
          temp.clear();
          ans += num;
        }
      for (int i = 0; i < n; i++) temp.push_back(a[i][int(sw[2 * i])]);
      sort(temp.begin(), temp.end());
      for (int i = 0; i < n - 1; i++)
        if (temp[i] != temp[i + 1] - 1) bad = true;
    }
    if (bad)
      cout << -1 << endl;
    else {
      cout << ans << endl;
      for (int i = 0; i < n; i++)
        if (sw[2 * i]) cout << i + 1 << " ";
      cout << endl;
    }
    for (int i = 0; i < 2 * n; i++) g[i].clear();
    for (int i = 0; i < n; i++) pos[i].clear();
    temp.clear();
  }
}
