#include <bits/stdc++.h>
using namespace std;
int del, n, m;
struct Edge {
  int u, v;
} a[500010];
bitset<2010 * 2> A[2010], B[2010], C[2010];
inline int Get_del() {
  for (int i = 1; i <= n; i++) B[i] = A[i];
  for (int i = 1; i <= n; i++) {
    int k = 0;
    for (int j = i; j <= n; j++)
      if (B[j][i]) k = j;
    if (!k) return (0);
    swap(B[i], B[k]);
    for (int j = i + 1; j <= n; j++)
      if (B[j][i]) B[j] ^= B[i];
  }
  return (1);
}
inline void Get_inv() {
  for (int i = 1; i <= n; i++) C[i] = A[i];
  for (int i = 1; i <= n; i++) C[i][i + n] = 1;
  for (int i = 1; i <= n; i++) {
    int k = 0;
    for (int j = i; j <= n; j++)
      if (C[j][i]) k = j;
    if (!k) return;
    swap(C[i], C[k]);
    for (int j = 1; j <= n; j++)
      if (C[j][i] && j != i) C[j] ^= C[i];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a[i].u, &a[i].v);
    A[a[i].u][a[i].v] = 1;
  }
  del = Get_del();
  Get_inv();
  for (int i = 1; i <= m; i++) {
    if (!del || C[a[i].v][a[i].u + n])
      puts("NO");
    else
      puts("YES");
  }
}
