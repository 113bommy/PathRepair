#include <bits/stdc++.h>
void tobinary(char *A, int *B, int *C, int size) {
  int apos = 0, bpos = 0, cpos = 0;
  int n = 0;
  while (apos < size) {
    if (A[apos] == '0') {
      while (A[apos] == '0') {
        B[bpos]++;
        apos++;
      }
      if (B[bpos] > 1)
        while (n < B[bpos] - 1) printf("0", n++);
      bpos++;
      n = 0;
    } else if (A[apos] == '1') {
      while (A[apos] == '1') {
        C[cpos]++;
        apos++;
      }
      printf("%d", C[cpos]);
      cpos++;
    }
  }
  if (A[size - 1] == '0') printf("0");
}
int main() {
  int size;
  char a[100];
  int b[200] = {0}, c[200] = {0};
  int i = 0;
  scanf("%d", &size);
  scanf("%s", a);
  tobinary(a, b, c, size);
}
