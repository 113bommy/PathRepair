#include <bits/stdc++.h>
using namespace std;
vector<int>* v;
vector<int>* vt;
int n, m;
int pri[100005];
int pr[100005];
int dfs1[100005];
int dfs2[100005];
stack<int> ord;
map<pair<int, int>, int> mp;
void dfsf(vector<int>** v, int* vis, int x, int m, int r) {
  vis[x] = m;
  for (int i = 0; i < ((*v)[x]).size(); i++) {
    if (vis[(*v)[x][i]] == 0) dfsf(v, vis, (*v)[x][i], m, r);
  }
  if (r == 1) ord.push(x);
  if (r == 2)
    if (mp[make_pair(dfs1[x], dfs2[x])] != 0)
      pr[x] = mp[make_pair(dfs1[x], dfs2[x])];
    else {
      pr[x] = x;
      mp[make_pair(dfs1[x], dfs2[x])] = x;
    }
}
void tarjan() {
  for (int i = 0; i < n; i++)
    if (dfs1[i + 1] == 0) dfsf(&v, dfs1, i + 1, i + 1, 1);
  for (int i = 0; i < n; i++) {
    int o = ord.top();
    if (dfs2[ord.top()] == 0) {
      dfsf(&vt, dfs2, o, o, 2);
    }
    ord.pop();
  }
}
int main() {
  v = new vector<int>[100005];
  vt = new vector<int>[100005];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &pri[i + 1]);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    vt[y].push_back(x);
  }
  tarjan();
  int mod = (int)1e9 + 7;
  long long nacin = 1;
  int price = 0;
  int p[100005], b[n];
  for (int i = 0; i <= n; i++) p[i] = 1 << 30, b[i] = 0;
  for (int i = 1; i < n + 1; i++) {
    if (p[pr[i]] == pri[i]) b[pr[i]]++;
    if (p[pr[i]] > pri[i]) b[pr[i]] = 1, p[pr[i]] = pri[i];
  }
  for (int i = 1; i <= n; i++) {
    if (p[i] != 1 << 30) {
      nacin *= b[i];
      nacin %= mod;
      price += p[i];
    }
  }
  cout << price << ' ' << nacin;
  return 0;
}
