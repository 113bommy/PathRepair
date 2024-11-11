#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int a, b, d, num;
} edge[100000];
bool comp(Edge a, Edge b) { return a.d < b.d; }
int p[100001];
int sz[100001];
int pd[100001];
int root[100001];
bool mark[100001];
vector<int> ss[100001];
int getp(int v) {
  if (p[v] != v) p[v] = getp(p[v]);
  return p[v];
}
void dfs(int v, int r) {
  root[v] = r;
  mark[v] = 1;
  pd[v] = sz[v];
  for (int i = 0; i < ss[v].size(); i++)
    if (!mark[ss[v][i]]) {
      dfs(ss[v][i], r);
      pd[v] += pd[ss[v][i]];
    }
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> edge[i].a >> edge[i].b >> edge[i].d;
    edge[i].num = i + 1;
  }
  sort(edge, edge + n - 1, comp);
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    sz[i] = 1;
  }
  long long ans = 0;
  vector<int> anse;
  int cure = 0;
  while (cure < n - 1) {
    vector<int> doze;
    doze.push_back(cure++);
    while (cure < n - 1 && edge[cure].d == edge[cure - 1].d)
      doze.push_back(cure++);
    vector<int> toclear;
    for (int i = 0; i < doze.size(); i++) {
      ss[getp(edge[doze[i]].a)].push_back(getp(edge[doze[i]].b));
      ss[p[edge[doze[i]].b]].push_back(p[edge[doze[i]].a]);
      toclear.push_back(p[edge[doze[i]].a]);
      toclear.push_back(p[edge[doze[i]].b]);
    }
    memset(mark, 0, n + 1);
    for (int i = 0; i < doze.size(); i++) {
      if (!mark[p[edge[doze[i]].a]])
        dfs(p[edge[doze[i]].a], p[edge[doze[i]].a]);
    }
    for (int i = 0; i < doze.size(); i++) {
      long long vodnustoronu, vdruguustoronu;
      vodnustoronu = pd[p[edge[doze[i]].a]];
      vdruguustoronu = pd[p[edge[doze[i]].b]];
      long long podderevo = min(vodnustoronu, vdruguustoronu);
      long long res =
          2 * podderevo * (pd[root[p[edge[doze[0]].a]]] - podderevo);
      if (res > ans) {
        ans = res;
        anse.clear();
        anse.push_back(edge[doze[i]].num);
      } else if (res == ans)
        anse.push_back(edge[doze[i]].num);
    }
    for (int i = 0; i < doze.size(); i++) {
      sz[getp(edge[doze[i]].a)] += sz[getp(edge[doze[i]].b)];
      p[p[edge[doze[i]].b]] = p[edge[doze[i]].a];
    }
    for (int i = 0; i < toclear.size(); i++) ss[toclear[i]].clear();
  }
  sort(anse.begin(), anse.end());
  cout << ans << ' ' << anse.size() << '\n';
  for (int i = 0; i < anse.size(); i++) cout << anse[i] << ' ';
  return 0;
}
