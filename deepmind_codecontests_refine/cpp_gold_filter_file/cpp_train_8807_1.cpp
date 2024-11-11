#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, id, an, i, v[5050];
vector<int> V[5050];
bool ok(int x, int y) {
  v[x] = id;
  if (V[x].size() < an) return V[x].push_back(y), 1;
  for (int i = 0, z; i < V[x].size(); i++)
    if (v[z = V[x][i]] != id && ok(z, x)) return V[x][i] = y, 1;
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (; m--;) {
    scanf("%d%d", &x, &y);
    if (++id, !ok(x, y))
      if (++id, !ok(y, x)) an++, V[x].push_back(y);
  }
  printf("%d\n", an);
  for (x = 1; x <= n; x++)
    for (i = 0; i < V[x].size(); i++) printf("%d %d\n", x, V[x][i]);
}
