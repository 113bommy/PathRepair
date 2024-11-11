#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
vector<int> g[N];
int cnt[N];
bool bad[N];
string s[N];
int main() {
  int m, now = 0;
  map<string, int> name;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    if (!name.count(s1)) {
      name[s1] = now;
      s[now] = s1;
      now++;
    }
    if (!name.count(s2)) {
      name[s2] = now;
      s[now] = s2;
      now++;
    }
    int a = name[s1];
    int b = name[s2];
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cout << now << endl;
  for (int i = 0; i < now; i++) {
    for (int j = 0; j < now; j++) cnt[j] = bad[j] = 0;
    bad[i] = 1;
    int mx = -1, ans = 0;
    for (int j = 0; j < g[i].size(); j++) {
      int u = g[i][j];
      bad[u] = 1;
      for (int k = 0; k < g[u].size(); k++) cnt[g[u][k]]++;
    }
    for (int j = 0; j < now; j++)
      if (!bad[j]) mx = max(mx, cnt[j]);
    for (int j = 0; j < now; j++)
      if (!bad[j] && cnt[j] == mx) ans++;
    cout << s[i] << ' ' << ans << endl;
  }
  return 0;
}
