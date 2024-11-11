#include <bits/stdc++.h>
using namespace std;
int n, q;
int val[2 * 100100];
vector<int> adj[2 * 100100];
bool lev[2 * 100100];
int par[2 * 100100];
int st[2 * 100100], en[100100];
int fen[2 * 100100];
int num;
void dfs(int u, int pa, bool l) {
  lev[u] = l;
  par[u] = pa;
  st[u] = ++num;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == pa) continue;
    dfs(v, u, !l);
  }
  en[u] = num;
}
void up(int st, int val) {
  while (st <= n + 1) {
    fen[st] += val;
    st += (st & -st);
  }
  return;
}
int query(int e) {
  int sum = 0;
  while (e) {
    sum += fen[e];
    e -= (e & -e);
  }
  return sum;
}
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0, 0);
  while (q--) {
    int a, no, co;
    cin >> a >> no;
    if (a == 1) {
      cin >> co;
      int s, e;
      s = st[no];
      e = en[no];
      if (lev[no]) {
        up(s, -co);
        up(e + 1, co);
      } else {
        up(s, co);
        up(e + 1, -co);
      }
    } else {
      cout << val[no] + (lev[no] ? -1 : +1) * query(st[no]) << endl;
    }
  }
  return 0;
}
