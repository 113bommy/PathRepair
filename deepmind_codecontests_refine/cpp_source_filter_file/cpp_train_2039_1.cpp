#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
vector<int> g[MAXN];
int matcha[MAXN], matchb[MAXN], vis[MAXN];
string tab1[MAXN], tab2[MAXN], tmp[MAXN];
map<string, int> m1, m2;
bool dfs(int s) {
  if (vis[s]) return false;
  vis[s] = 1;
  for (int to : g[s])
    if (matchb[to] == -1 || dfs(matchb[to])) {
      matchb[to] = s;
      matcha[s] = to;
      return true;
    }
  return false;
}
int maxMatching(int n, int m) {
  fill(matcha, matcha + n, -1);
  fill(matchb, matchb + n + m, -1);
  int res = 0, czy = 1;
  while (czy) {
    czy = 0;
    fill(vis, vis + n, 0);
    for (int i = 0; i < n; i++)
      if (matcha[i] == -1) czy += dfs(i);
    res += czy;
  }
  return res;
}
void add(int i, string a, int& ile) {
  if (m2.find(a) == m2.end()) {
    m2[a] = ile;
    tmp[ile] = a;
    ile++;
  }
  int x = m2[a];
  g[i].push_back(x);
  g[x].push_back(i);
}
int main() {
  int n;
  string a, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    tab1[i] = a.substr(0, 3);
    tab2[i] = a.substr(0, 2) + b[0];
    m1[tab1[i]]++;
  }
  int ile = n;
  for (int i = 0; i < n; i++) {
    if (m1[tab1[i]] == 1) add(i, tab2[i], ile);
    add(i, tab2[i], ile);
  }
  int x = maxMatching(n, ile - n);
  if (x != n)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << tmp[matcha[i]] << endl;
  }
}
