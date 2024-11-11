#include <bits/stdc++.h>
using namespace std;
const int inf = 1e18;
const int N = 2e+5;
const int M = 6e+5;
int mod = 1e9 + 7;
int n, m, a, b;
int h[N];
int e[M], ne[M], idx = 1, num = 1;
long long anscost = 0, mincnt;
long long mincost;
long long anscnt = 1;
int low[N], dfn[N];
stack<int> s;
bool st[N];
int cost[N];
void add(int a, int b) {
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx;
  idx++;
}
void tarjan(int a) {
  low[a] = dfn[a] = num++;
  st[a] = true;
  s.push(a);
  for (int i = h[a]; i != -1; i = ne[i]) {
    int b = e[i];
    if (dfn[b] == 0) {
      tarjan(b);
      low[a] = min(low[a], low[b]);
    }
    if (dfn[b] != 0 && st[b] == 1) {
      low[a] = min(low[a], dfn[b]);
    }
  }
  if (low[a] == dfn[a]) {
    int b;
    mincost = inf;
    mincnt = 0;
    do {
      b = s.top();
      if (mincost == cost[b]) {
        mincnt++;
      }
      if (mincost > cost[b]) {
        mincnt = 1;
      }
      mincost = min((long long)cost[b], mincost);
      s.pop();
      st[b] = false;
    } while (b != a);
    anscost += mincost;
    anscnt = 1ll * anscnt * mincnt % mod;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> cost[i];
  memset(h, -1, sizeof(h));
  memset(low, 0, sizeof(low));
  memset(dfn, 0, sizeof(dfn));
  memset(st, 0, sizeof(st));
  num = 1;
  idx = 1;
  cin >> m;
  while (m--) {
    cin >> a >> b;
    add(a, b);
  }
  for (int i = 1; i <= n; i++) {
    if (dfn[i] == 0) {
      tarjan(i);
    }
  }
  cout << anscost << " " << anscnt << endl;
}
