#include <bits/stdc++.h>
using namespace std;
long long int Mod = 1000000007;
int main() {
  int i, j, k, l, m, n, x, y, z, a, b, r, g;
  scanf("%d", &n);
  scanf("%d", &m);
  int B[n], G[m];
  memset(B, 0, sizeof(B));
  memset(G, 0, sizeof(G));
  scanf("%d", &b);
  for (i = 0; i < b; i++) {
    scanf("%d", &x);
    B[x] = 1;
  }
  scanf("%d", &g);
  for (i = 0; i < g; i++) {
    scanf("%d", &x);
    G[x] = 1;
  }
  int minn = max(n, m);
  bool A[minn + 1];
  memset(A, 0, sizeof(A));
  for (i = 0; i <= n * m; i++) {
    y = i % n;
    z = i % m;
    A[i % minn] |= B[y] | G[z];
    B[y] = A[i % minn];
    G[z] = A[i % minn];
  }
  for (i = 0; i < minn; i++) {
    if (!A[i]) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
