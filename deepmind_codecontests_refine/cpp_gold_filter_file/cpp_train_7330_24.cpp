#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 7;
const int oo = (int)3e5 + 7;
int n, curx, cury;
int l[N], r[N], v[N];
int ll[4 * oo], rr[4 * oo], lazy[4 * oo], maxx[4 * oo];
vector<int> veL[oo], veR[oo];
void Enter() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &l[i], &v[i], &r[i]);
    veL[l[i]].push_back(i);
    veR[v[i]].push_back(i);
  }
}
void Build(int node, int leftt, int rightt) {
  ll[node] = leftt, rr[node] = rightt;
  if (leftt == rightt) return;
  int mid = (leftt + rightt) / 2;
  Build(node * 2, leftt, mid);
  Build(node * 2 + 1, mid + 1, rightt);
}
void down(int node) {
  if (!lazy[node]) return;
  lazy[node * 2] += lazy[node];
  lazy[node * 2 + 1] += lazy[node];
  maxx[node * 2] += lazy[node];
  maxx[node * 2 + 1] += lazy[node];
  lazy[node] = 0;
}
void update(int node, int u, int v, int val) {
  if (ll[node] > v || rr[node] < u) return;
  if (u <= ll[node] && rr[node] <= v) {
    lazy[node] += val;
    maxx[node] += val;
    return;
  }
  down(node);
  update(node * 2, u, v, val);
  update(node * 2 + 1, u, v, val);
  maxx[node] = max(maxx[node * 2], maxx[node * 2 + 1]);
}
int query(int node, int u, int v) {
  if (ll[node] > v || rr[node] < u) return 0;
  if (u <= ll[node] && rr[node] <= v) return maxx[node];
  down(node);
  int res = max(query(node * 2, u, v), query(node * 2 + 1, u, v));
  maxx[node] = max(maxx[node * 2], maxx[node * 2 + 1]);
  return res;
}
void Process() {
  int ans = 0;
  Build(1, 1, (int)3e5);
  for (int i = 1; i <= (int)3e5; i++) {
    if (veL[i].size())
      for (auto j : veL[i]) update(1, v[j], r[j], 1);
    if (veR[i - 1].size())
      for (auto j : veR[i - 1]) update(1, v[j], r[j], -1);
    if (ans < query(1, 1, (int)3e5)) {
      ans = query(1, 1, (int)3e5);
      curx = i;
    }
  }
  memset(maxx, 0, sizeof(maxx));
  memset(lazy, 0, sizeof(lazy));
  printf("%d\n", ans);
  for (int i = 1; i <= curx; i++) {
    if (veL[i].size())
      for (auto j : veL[i]) update(1, v[j], r[j], 1);
    if (veR[i - 1].size())
      for (auto j : veR[i - 1]) update(1, v[j], r[j], -1);
  }
  for (int i = 1; i <= (int)3e5; i++)
    if (query(1, i, i) == ans) {
      cury = i;
      break;
    }
  for (int i = 1; i <= n; i++)
    if (l[i] <= curx && curx <= v[i] && v[i] <= cury && cury <= r[i])
      printf("%d ", i);
}
int main() {
  Enter();
  Process();
}
