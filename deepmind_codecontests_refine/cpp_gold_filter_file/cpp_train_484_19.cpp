#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;
int deg[maxn], fa[maxn], nd[maxn];
vector<pair<int, int> > vAns;
int nFind(int id) { return (fa[id] == id) ? id : (fa[id] = nFind(fa[id])); }
void vUnion(int x, int y) {
  deg[x]++;
  deg[y]++;
  fa[nFind(x)] = nFind(y);
}
int main() {
  int i, j, n, m, u, v;
  bool ci = false;
  scanf("%d%d", &n, &m);
  if (n == 1 && m == 0) {
    printf("YES\n1\n1 1\n");
    return 0;
  }
  for (i = 1; i <= n; i++) fa[i] = i;
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    if (nFind(u) == nFind(v)) ci = true;
    vUnion(u, v);
  }
  for (i = 1; i <= n; i++) {
    if (deg[i] > 2) {
      printf("NO\n");
      return 0;
    }
  }
  if (ci) {
    u = nFind(1);
    for (i = 1; i <= n; i++) {
      if (nFind(i) != u || deg[i] < 2) {
        printf("NO\n");
        return 0;
      }
    }
    printf("YES\n0\n");
    return 0;
  }
  for (i = 1; i <= n; i++) {
    for (u = 1; u <= 2 && deg[i] < 2; u++) {
      for (j = i + 1; j <= n; j++) {
        if (deg[j] < 2 && nFind(i) != nFind(j)) {
          vUnion(i, j);
          vAns.push_back(make_pair(i, j));
          break;
        }
      }
    }
  }
  u = 0;
  for (i = 1; i <= n && u <= 2; i++) {
    if (deg[i] == 0 || deg[i] > 2)
      u = 3;
    else if (deg[i] == 1)
      nd[++u] = i;
  }
  if (u != 2) {
    printf("NO\n");
    return 0;
  }
  vAns.push_back(make_pair(nd[1], nd[2]));
  printf("YES\n%d\n", vAns.size());
  for (i = 0; i < vAns.size(); i++)
    printf("%d %d\n", vAns[i].first, vAns[i].second);
  return 0;
}
