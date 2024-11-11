#include <bits/stdc++.h>
using namespace std;
int n, x;
int L[1000009], p[1000009][21];
int LCA(int a, int b) {
  if (L[a] < L[b]) swap(a, b);
  for (int i = 20; i >= 0; i--)
    if (L[p[a][i]] >= L[b]) a = p[a][i];
  if (a == b) return a;
  for (int i = 20; i >= 0; i--)
    if (p[a][i] != 0 && p[a][i] != p[b][i]) a = p[a][i], b = p[b][i];
  return p[a][0];
}
int main() {
  cin >> n;
  L[1] = 1;
  L[2] = 2;
  L[3] = 2;
  L[4] = 2;
  p[2][0] = 1;
  p[3][0] = 1;
  p[4][0] = 1;
  int gos = 5, nah = 2, mal = 4, cmo = 2;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    p[gos][0] = x, p[gos + 1][0] = x;
    for (int i = 1; i <= 20; i++) {
      p[gos][i] = p[p[gos][i - 1]][i - 1],
      p[gos + 1][i] = p[p[gos + 1][i - 1]][i - 1];
    }
    L[gos] = L[x] + 1;
    L[gos + 1] = L[x] + 1;
    int lca1 = LCA(gos, nah);
    int lca2 = LCA(gos, mal);
    if ((L[gos] - L[lca1]) + (L[nah] - L[lca1]) > cmo &&
        (L[gos] - L[lca1]) + (L[nah] - L[lca1]) >
            (L[gos] - L[lca2]) + (L[mal] - L[lca2]))
      cmo = (L[gos] - L[lca1]) + (L[nah] - L[lca1]), mal = gos;
    else if ((L[gos] - L[lca2]) + (L[mal] - L[lca2]) > cmo)
      cmo = (L[gos] - L[lca2]) + (L[mal] - L[lca2]), nah = gos;
    cout << cmo << '\n';
    gos += 2;
  }
  return 0;
}
