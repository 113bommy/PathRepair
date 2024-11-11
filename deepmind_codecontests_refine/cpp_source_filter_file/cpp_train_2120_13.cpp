#include <bits/stdc++.h>
using namespace std;
int Na, Ma, Nb, Mb;
int A[55][55], B[55][55];
int main() {
  int ans = -2;
  scanf("%d %d", &Na, &Ma);
  for (int i = 0; i < Na; i++)
    for (int j = 0; j < Ma; j++) scanf("%1d", &A[i][j]);
  scanf("%d %d", &Nb, &Mb);
  for (int i = 0; i < Nb; i++)
    for (int j = 0; j < Mb; j++) scanf("%1d", &B[i][j]);
  int a1 = -1, a2 = -1;
  for (int x = -Na; x < Nb; x++) {
    for (int y = -Ma; y < Mb; y++) {
      int cur = 0;
      for (int i = 0; i < Na; i++) {
        if (i + x < 0 || i + x >= Nb) continue;
        for (int j = 0; j < Ma; j++) {
          if (j + y < 0 || j + y >= Mb) continue;
          cur += A[i][j] * B[i + x][j + y];
        }
      }
      if (cur > ans) {
        ans = cur;
        a1 = x, a2 = y;
      }
    }
  }
  printf("%d %d", a1, a1);
}
