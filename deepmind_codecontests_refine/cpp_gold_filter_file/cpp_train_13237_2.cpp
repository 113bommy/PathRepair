#include <bits/stdc++.h>
using namespace std;
long n, m, c, q, u, v, par[100005];
char type;
set<long> s[100005];
map<long, long> color[100005];
long find(int i) {
  if (par[i] == i) {
    return i;
  } else {
    return par[i] = find(par[i]);
  }
}
void uni(int u, int v) {
  long par_u = find(u), par_v = find(v);
  if (par_u == par_v) {
    return;
  }
  if (s[par_u].size() > s[par_v].size()) {
    swap(s[par_u], s[par_v]);
  }
  for (auto w : s[par_u]) {
    s[par_v].insert(w);
  }
  par[par_u] = par_v;
}
void add(int u, int v, int c) {
  if (color[u][c] != 0) {
    uni(v, color[u][c]);
  }
  if (color[v][c] != 0) {
    uni(u, color[v][c]);
  }
  s[find(u)].insert(v);
  s[find(v)].insert(u);
  color[u][c] = v;
  color[v][c] = u;
}
int main() {
  scanf("%ld %ld %ld %ld", &n, &m, &c, &q);
  for (int i = 1; i <= n; i++) {
    par[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%ld %ld %ld", &u, &v, &c);
    add(u, v, c);
  }
  for (int i = 1; i <= q; i++) {
    cin >> type;
    if (type == '+') {
      scanf("%ld %ld %ld", &u, &v, &c);
      add(u, v, c);
    } else {
      scanf("%ld %ld", &u, &v);
      long par_u = find(u), par_v = find(v);
      if (par_u == par_v || s[par_u].find(v) != s[par_u].end()) {
        printf("Yes\n");
      } else {
        printf("No\n");
      }
    }
  }
}
