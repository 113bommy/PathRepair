#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:536870912")
#pragma warning(disable : 4996)
using namespace std;
const int N = 5e5 + 100;
int q[N], a[N], b[N], w[N], used[N], in[N];
bool ok[N];
vector<int> tr[N], d[N];
vector<pair<int, vector<int>>> gr[N];
vector<pair<int, int>> ed;
int col = 0, cg = 0;
int find(int v) { return q[v] < 0 ? v : q[v] = find(q[v]); }
bool un(int a, int b) {
  a = find(a), b = find(b);
  if (a != b) {
    if (q[a] > q[b]) swap(a, b);
    q[a] += q[b];
    q[b] = a;
    return true;
  }
  return false;
}
bool dfs(int node, int p) {
  used[node] = col;
  for (int to : tr[node]) {
    if (to == p) continue;
    if (used[to] == col)
      return true;
    else if (dfs(to, node))
      return true;
  }
  return false;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(q, -1, sizeof(q));
  ;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &a[i], &b[i], &w[i]);
    a[i]--, b[i]--;
    ed.push_back({w[i], i});
  }
  sort(ed.begin(), ed.end());
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &in[j]);
      in[j]--;
      if (gr[w[in[j]]].empty() || !gr[w[in[j]]].back().second.empty()) {
        gr[w[in[j]]].push_back({cg, vector<int>()});
        d[i].push_back(cg);
        cg++;
      }
    }
    for (int j = 0; j < k; j++) {
      gr[w[in[j]]].back().second.push_back(in[j]);
    }
  }
  for (int i = 0; i < ed.size(); i++) {
    if (i == 0 || ed[i].first != ed[i - 1].first) {
      for (auto &p : gr[ed[i].first]) {
        for (int j : p.second) {
          int x = find(a[j]), y = find(b[j]);
          tr[x].push_back(y);
          tr[y].push_back(x);
        }
        col++;
        ok[p.first] = 1;
        for (int j : p.second) {
          int x = find(a[j]);
          if (used[x] != col && dfs(x, -1)) {
            ok[p.first] = 0;
            break;
          }
        }
        for (int j : p.second) {
          int x = find(a[j]), y = find(b[j]);
          swap(tr[x], *(new vector<int>()));
          swap(tr[y], *(new vector<int>()));
        }
      }
    }
    un(a[ed[i].second], b[ed[i].second]);
  }
  for (int i = 0; i < t; i++) {
    bool f = true;
    for (int j : d[i]) {
      if (!ok[j]) {
        f = false;
        break;
      }
    }
    printf("%s\n", f ? "YES" : "NO");
  }
  return 0;
}
