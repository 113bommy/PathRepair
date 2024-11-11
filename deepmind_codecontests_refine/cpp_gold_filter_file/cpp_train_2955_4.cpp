#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
int A[maxn];
int Lmin[maxn];
int LminI[maxn];
int Lmax[maxn];
int LmaxI[maxn];
int Rmin[maxn];
int RminI[maxn];
int Rmax[maxn];
int RmaxI[maxn];
int main() {
  int n, i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
    LminI[i] = i;
    RminI[i] = i;
    LmaxI[i] = i;
    RmaxI[i] = i;
  }
  Lmin[1] = Lmax[1] = A[1];
  for (i = 2; i <= n; i++) {
    if (A[i] > Lmax[i - 1]) {
      Lmax[i] = A[i];
      LmaxI[i] = i;
    } else {
      Lmax[i] = Lmax[i - 1];
      LmaxI[i] = LmaxI[i - 1];
    }
    if (A[i] < Lmin[i - 1]) {
      Lmin[i] = A[i];
      LminI[i] = i;
    } else {
      Lmin[i] = Lmin[i - 1];
      LminI[i] = LminI[i - 1];
    }
  }
  Rmax[n] = Rmin[n] = A[n];
  for (i = n - 1; i >= 1; i--) {
    if (A[i] > Rmax[i + 1]) {
      Rmax[i] = A[i];
      RmaxI[i] = i;
    } else {
      Rmax[i] = Rmax[i + 1];
      RmaxI[i] = RmaxI[i + 1];
    }
    if (A[i] < Rmin[i + 1]) {
      Rmin[i] = A[i];
      RminI[i] = i;
    } else {
      Rmin[i] = Rmin[i + 1];
      RminI[i] = RminI[i + 1];
    }
  }
  bool isover = false;
  if (n >= 3) {
    for (i = 2; i < n; i++) {
      if (A[i] > Lmin[i - 1] && A[i] > Rmin[i + 1]) {
        printf("3\n");
        printf("%d %d %d\n", LminI[i - 1], i, RminI[i + 1]);
        isover = true;
        break;
      } else if (A[i] < Lmax[i - 1] && A[i] < Rmax[i + 1]) {
        printf("3\n");
        printf("%d %d %d\n", LmaxI[i - 1], i, RmaxI[i + 1]);
        isover = true;
        break;
      }
    }
  }
  if (!isover) printf("0\n");
  return 0;
}
