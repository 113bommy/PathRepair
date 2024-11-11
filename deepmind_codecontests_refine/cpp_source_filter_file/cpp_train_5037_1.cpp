#include <bits/stdc++.h>
using namespace std;
map<int, map<int, string> > G;
long long ans;
int pref[300000][2];
int used[100001];
int pr(string &a, int n, int sz) {
  int cnt = 0;
  if (n == 0) {
    n++;
    pref[0][0] = 0;
    pref[0][1] = a[0];
    a.erase(a.begin());
  }
  for (int i = n; i < n + a.size(); i++) {
    int j = pref[i - 1][0];
    pref[i][1] = a[i - n];
    while (j > 0 && a[i - n] != pref[j][1]) j = pref[j - 1][0];
    if (a[i - n] == pref[j][1]) j++;
    pref[i][0] = j;
    if (j == sz) cnt++;
  }
  return cnt;
}
void dfs(int v, int pos, int s) {
  if (used[v]) return;
  used[v] = 1;
  for (map<int, string>::iterator i = G[v].begin(); i != G[v].end(); i++) {
    ans += pr(i->second, pos, s);
    dfs(i->first, pos + i->second.size(), s);
    used[i->first] = 1;
  }
}
int main() {
  int n;
  cin >> n;
  int p;
  string c;
  for (int i = int(1); i < int(n); ++i) {
    cin >> p >> c;
    G[p][i + 1] = c;
  }
  cin >> c;
  c.push_back('#');
  pr(c, 0, -1);
  dfs(1, c.size(), c.size() - 1);
  cout << ans;
  return 0;
}
