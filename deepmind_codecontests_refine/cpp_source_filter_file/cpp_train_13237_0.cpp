#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
set<int> ss[MAXN];
int par[MAXN], n, m, C, Q;
vector<int> vec[MAXN];
map<int, int> mp[MAXN];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (vec[x].size() < vec[y].size()) swap(x, y);
  par[y] = x;
  vec[x].insert(vec[x].end(), vec[y].begin(), vec[y].end());
  for (int i : vec[y]) ss[i].insert(x);
  vec[y].clear();
}
void add(int x, int y, int c) {
  int &t = mp[x][c];
  if (!t)
    t = y;
  else
    merge(y, t);
  int &p = mp[y][c];
  if (!p)
    p = x;
  else
    merge(x, p);
  ss[x].insert(find(y));
  ss[y].insert(find(x));
  vec[find(y)].push_back(y);
  vec[find(x)].push_back(x);
}
int main() {
  scanf("%d%d%d%d", &n, &m, &C, &Q);
  for (int i = 1; i <= n; i++) {
    par[i] = i;
    ss[i].insert(i);
    vec[i].push_back(i);
  }
  for (int i = 1; i <= m; i++) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    add(x, y, c);
  }
  while (Q--) {
    char opt[5];
    int x, y, z;
    scanf("%s%d%d", opt, &x, &y);
    if (opt[0] == '+') {
      scanf("%d", &z);
      add(x, y, z);
    } else
      puts(ss[y].find(find(x)) != ss[y].end() ? "Yes" : "No");
  }
  return 0;
}
