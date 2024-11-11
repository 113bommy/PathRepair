#include <bits/stdc++.h>
using namespace std;
vector<int> G[100005];
int a[100005], b[100005], l[2], c, p[100005], n, m, s, t;
bool f = 1, v[100005];
void D(int x) {
  p[++c] = x;
  v[x] = 1;
  if (x == t) f = 0;
  for (unsigned i = 0; i < G[x].size(); i++)
    if (!v[G[x][i]]) D(G[x][i]);
}
int main() {
  scanf("%d%d", &n, &m);
  s = m + 1;
  t = m + 2;
  for (int C = 1; C <= n; C++) {
    scanf("%d", &l[1]);
    for (int i = 1; i <= l[1]; i++) {
      scanf("%d", &b[i]);
      if (C == 1) l[0] = l[1], a[i] = b[i];
    }
    int q = 1;
    while (a[q] == b[q] && l[1] >= q) q++;
    if (q <= l[0] && q > l[1]) return 0 * puts("No");
    if (q <= l[0] && q <= l[1]) {
      if (a[q] > b[q])
        G[s].push_back(a[q]), G[b[q]].push_back(t);
      else
        G[b[q]].push_back(a[q]);
    }
    l[0] = l[1];
    for (int i = 1; i <= l[1]; i++) a[i] = b[i];
  }
  D(s);
  if (!f) return 0 * puts("No");
  puts("Yes");
  printf("%d\n", c - 1);
  for (int i = 2; i <= c; i++) printf("%d ", p[i]);
  return 0;
}
