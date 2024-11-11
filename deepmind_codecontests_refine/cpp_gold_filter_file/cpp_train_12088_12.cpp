#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 13;
const int MAXM = 51;
const int LOG = 18;
const long long INF = 1e18;
int licz = 0, tim = 0;
vector<pair<int, long long> > v[MAXN];
vector<int> dospr;
bool odw[MAXN];
bool odw2[MAXM][MAXN];
long long roz[MAXN];
long long odl[MAXM][MAXN];
int pre[MAXN][LOG];
int in[MAXN];
int out[MAXN];
priority_queue<pair<long long, int>, vector<pair<long long, int> >,
               greater<pair<long long, int> > >
    q;
void dijkstra(int x, int k) {
  pair<long long, int> p;
  q.push({0, x});
  while (!q.empty()) {
    p = q.top();
    q.pop();
    if (odw2[k][p.second]) continue;
    odw2[k][p.second] = true;
    odl[k][p.second] = p.first;
    for (auto it : v[p.second]) {
      if (!odw2[k][it.first]) q.push({it.second + p.first, it.first});
    }
  }
}
void DFS(int x, int oj) {
  tim++;
  in[x] = tim;
  odw[x] = true;
  pre[x][0] = oj;
  for (int i = 1; i < LOG; i++) pre[x][i] = pre[pre[x][i - 1]][i - 1];
  for (auto it : v[x]) {
    if (!odw[it.first]) {
      roz[it.first] = roz[x] + it.second;
      DFS(it.first, x);
    } else if (it.first != oj) {
      licz++;
      dospr.push_back(x);
      dijkstra(x, licz);
    }
  }
  out[x] = tim;
  tim++;
}
bool sprawdz(int x, int y) {
  if (in[x] <= in[y] && out[x] >= out[y])
    return true;
  else
    return false;
}
long long LCA(int x, int y) {
  if (sprawdz(x, y)) return roz[x] + roz[y] - 2 * roz[x];
  if (sprawdz(y, x)) return roz[x] + roz[y] - 2 * roz[y];
  tim = y;
  for (int i = LOG - 1; i >= 0; i--) {
    if (!sprawdz(pre[y][i], x)) y = pre[y][i];
  }
  y = pre[y][0];
  return roz[x] + roz[tim] - 2 * roz[y];
}
int main() {
  int n, m;
  int x, y;
  long long d, wyn;
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d %lld", &x, &y, &d);
    v[x].push_back({y, d});
    v[y].push_back({x, d});
  }
  DFS(1, 0);
  out[0] = tim + 1;
  scanf("%d", &m);
  while (m--) {
    scanf("%d %d", &x, &y);
    wyn = LCA(x, y);
    for (int i = 1; i <= licz; i++) {
      wyn = min(wyn, LCA(x, dospr[i - 1]) + odl[i][y]);
      wyn = min(wyn, LCA(y, dospr[i - 1]) + odl[i][x]);
    }
    printf("%lld\n", wyn);
  }
  return 0;
}
