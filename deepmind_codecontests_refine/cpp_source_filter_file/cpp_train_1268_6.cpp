#include <bits/stdc++.h>
using namespace std;
const int N = 8e5 + 10;
int m1, p, t, m2, n;
bool mark[N << 1], ch[N << 1];
vector<int> gr[N << 1], rg[N << 1], tps;
int Not(int x) { return (x > n) ? x - n : x + n; }
void addEdge(int x, int y) {
  gr[Not(x)].push_back(y);
  gr[Not(y)].push_back(x);
  return;
}
void dfs(int v) {
  mark[v] = 1;
  for (auto u : gr[v]) {
    if (!mark[u]) dfs(u);
  }
  tps.push_back(v);
}
void FindSat(int v) {
  if (mark[Not(v)]) {
    ch[Not(v)] = 0;
    ch[v] = 1;
  }
  mark[v] = 1;
  for (auto u : rg[v]) {
    if (!mark[u]) FindSat(u);
  }
  return;
}
void getAns() {
  for (int i = 0; i < 2 * n; i++) {
    if (!mark[i]) dfs(i);
    for (auto u : gr[i]) rg[u].push_back(i);
  }
  reverse(tps.begin(), tps.end());
  memset(mark, 0, sizeof(mark));
  for (auto u : tps) {
    if (!mark[u]) FindSat(u);
  }
  for (int i = 0; i < 2 * n; i++) {
    for (auto u : gr[i]) {
      if (ch[i] && !ch[u]) {
        cout << -1;
        exit(0);
      }
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> m1 >> p >> t >> m2;
  n = p + t + 1;
  for (int i = 0; i < m1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    addEdge(x, y);
  }
  for (int i = 0; i < p; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    addEdge(Not(i), l);
    addEdge(Not(i), Not(r));
  }
  for (int i = 0; i < m2; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    addEdge(Not(x), Not(y));
  }
  for (int i = p + 1; i <= p + t; i++) {
    addEdge(Not(i), i - 1);
  }
  getAns();
  vector<int> ctr;
  int lst = 0;
  for (int i = 0; i < p; i++) {
    if (ch[i]) ctr.push_back(i + 1);
  }
  for (int i = p; i < n; i++) {
    if (ch[i]) lst = i - p;
  }
  cout << ctr.size() << " " << lst + 1 << "\n";
  for (auto u : ctr) cout << u << " ";
  return 0;
}
