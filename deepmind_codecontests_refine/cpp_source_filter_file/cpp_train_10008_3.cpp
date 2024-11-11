#include <bits/stdc++.h>
using namespace std;
struct edge {
  int from, to, cost;
} infor[200010];
int n, m, ans, father[200010], r[200010];
bool comp(edge a, edge b) { return a.cost < b.cost; }
void init(int n) {
  for (int i = 1; i <= n; i++) {
    father[i] = i;
    r[i] = 0;
  }
}
int find(int a) {
  if (a == father[a])
    return a;
  else
    return father[a] = find(father[a]);
}
bool same(int a, int b) { return find(a) == find(b); }
void unite(int a, int b) {
  a = find(a), b = find(b);
  if (a == b)
    return;
  else {
    if (r[a] < r[b])
      father[a] = b;
    else {
      father[b] = a;
      if (r[a] == r[b]) r[b]++;
    }
  }
}
int kruscal() {
  int i;
  sort(infor, infor + m, comp);
  for (i = 0; i < m;) {
    vector<edge> now;
    int j;
    for (j = i; j < m && infor[j].cost == infor[i].cost; j++)
      if (!same(infor[i].from, infor[i].to)) now.push_back(infor[j]);
    i = j;
    for (j = 0; j < now.size(); j++)
      if (!same(now[j].from, now[j].to))
        unite(now[j].from, now[j].to);
      else
        ans++;
  }
  return ans;
}
int main() {
  int i;
  std::ios::sync_with_stdio(0);
  cin >> n >> m;
  init(n);
  for (i = 0; i < m; i++) cin >> infor[i].from >> infor[i].to >> infor[i].cost;
  cout << kruscal() << endl;
  return 0;
}
