#include <bits/stdc++.h>
using namespace std;
int pre[100000 + 5];
int getnext(char* B, int pre[]) {
  int i, j, k;
  pre[0] = -1;
  j = -1;
  int Lb = strlen(B);
  for (i = 1; i < Lb; i++) {
    while (j >= 0 && B[j + 1] != B[i]) j = pre[j];
    if (B[j + 1] == B[i]) j = j + 1;
    pre[i] = j;
  }
  int cir = Lb - 1 - pre[Lb - 1];
  if (Lb % cir == 0)
    return cir;
  else
    return -1;
}
char A[100000 + 5], B[100000 + 5];
int min(int x, int y) { return x < y ? x : y; }
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int i, j, k;
  scanf("%s", A);
  scanf("%s", B);
  int La = strlen(A);
  int Lb = strlen(B);
  int ca = getnext(A, pre);
  int cb = getnext(B, pre);
  if (ca == -1 || cb == -1) {
    printf("0\n");
  } else {
    if (ca != cb) {
      printf("0\n");
    } else {
      int f = 0;
      for (i = 0; i < ca; i++) {
        if (A[i] != B[i]) {
          f = 1;
          break;
        }
      }
      if (f == 1)
        printf("0\n");
      else {
        int aa = La / ca, bb = Lb / cb;
        int ans = 0;
        for (i = 1; i <= aa && i <= bb; i++)
          if (aa % i == 0 && bb % i == 0) ans++;
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
