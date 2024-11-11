#include <bits/stdc++.h>
using namespace std;
int main() {
  int ii;
  scanf("%d", &ii);
  for (int j = 0; j < ii; j++) {
    int n, k;
    int R[200001], G[200001], B[200001];
    char str[200001];
    scanf("%d %d", &n, &k);
    scanf("%s", &str);
    char x[3];
    x[0] = 'R';
    x[1] = 'G';
    x[2] = 'B';
    R[0] = 0;
    G[0] = 0;
    B[0] = 0;
    for (int i = 0; i < n; i++) {
      if (str[i] != x[i % 3])
        R[i + 1] = R[i] + 1;
      else
        R[i + 1] = R[i];
      if (str[i] != x[(i + 1) % 3])
        G[i + 1] = G[i] + 1;
      else
        G[i + 1] = G[i];
      if (str[i] != x[(i + 2) % 3])
        B[i + 1] = B[i] + 1;
      else
        B[i + 1] = B[i];
    }
    int mn = 100000;
    for (int i = 0; i <= n - k; i++) {
      if ((R[k + i] - R[i]) < mn) mn = R[k + i] - R[i];
      if ((G[k + i] - G[i]) < mn) mn = G[k + i] - G[i];
      if ((B[k + i] - B[i]) < mn) mn = B[k + i] - B[i];
    }
    printf("%d\n", mn);
  }
  return 0;
}
