#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
vector<int> e[N], o;
int a[N], n;
void dfs(int u, int f, int s) {
  if (a[u] ^ (s & 1)) {
    s ^= 2;
    o.push_back(u);
  }
  s = s >> 1 | (s & 1) << 1;
  for (int v : e[u])
    if (v != f) dfs(v, u, s);
}
int main() {
  scanf("%d", &n);
  for (int i = 1, a, b; i < n; ++i) {
    scanf("%d%d", &a, &b);
    e[a].push_back(b);
    e[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1, t; i <= n; ++i) {
    scanf("%d", &t);
    a[i] ^= t;
  }
  dfs(1, 0, 0);
  printf("%d\n", o.size());
  for (int t : o) printf("%d\n", t);
}
