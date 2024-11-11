#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
map<string, int> user_id;
vector<int> g[N];
int n, ans[N], m;
string at[N];
bool was[N];
int main() {
  ios::sync_with_stdio(0);
  cin >> m;
  for (int i = (1); i <= (int)(m); i++) {
    string s1, s2;
    cin >> s1 >> s2;
    int x = user_id[s1], y = user_id[s2];
    if (x == 0) {
      user_id[s1] = ++n;
      at[n] = s1;
      x = n;
    }
    if (y == 0) {
      user_id[s2] = ++n;
      at[n] = s2;
      y = n;
    }
    g[x].push_back(y);
    g[y].push_back(x);
  }
  cout << n << endl;
  for (int i = (1); i <= (int)(n); i++) {
    for (int j = (1); j <= (int)(n); j++) was[j] = ans[j] = 0;
    for (int j = (0); j <= (int)(g[i].size() - 1); j++) was[g[i][j]] = 1;
    for (int j = (0); j <= (int)(g[i].size() - 1); j++) {
      int to = g[i][j];
      for (int k = (0); k <= (int)(g[to].size() - 1); k++) {
        int v = g[to][k];
        if (i != v && !was[v]) ans[v]++;
      }
    }
    int cnt = 0, mx = 1;
    for (int j = (1); j <= (int)(n); j++)
      if (j != i && !was[j]) mx = max(mx, ans[j]);
    for (int j = (1); j <= (int)(n); j++)
      if (j != i && !was[j])
        if (ans[j] == mx) cnt++;
    cout << at[i] << " " << cnt << endl;
  }
  return 0;
}
