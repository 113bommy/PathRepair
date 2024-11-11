#include <bits/stdc++.h>
using namespace std;
int n, grau[70012], xors[70012], gr;
queue<int> q;
set<pair<int, int> > st;
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &grau[i], &xors[i]);
    gr += grau[i];
    if (grau[i] == 1) {
      q.push(i);
    }
  }
  gr >>= 1;
  printf("%d\n", gr);
  int u, v;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    if (grau[u] == 0) continue;
    v = xors[u];
    printf("%d %d\n", u, v);
    grau[u]--;
    grau[v]--;
    xors[v] ^= u;
    xors[u] ^= v;
    if (grau[v] == 0) q.push(v);
  }
  return 0;
}
