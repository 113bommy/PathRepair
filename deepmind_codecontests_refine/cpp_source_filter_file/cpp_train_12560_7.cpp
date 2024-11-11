#include <bits/stdc++.h>
using namespace std;
inline char tc(void) {
  static char fl[10000], *A = fl, *B = fl;
  return A == B && (B = (A = fl) + fread(fl, 1, 10000, stdin), A == B) ? EOF
                                                                       : *A++;
}
inline int read(void) {
  int a = 0;
  char c;
  while ((c = tc()) < '0' || c > '9')
    ;
  while (c >= '0' && c <= '9') a = a * 10 + c - '0', c = tc();
  return a;
}
int lena, lenb, m, sumA[100005], sumB[100005], lastA[100005], lastB[100005];
char A[100005], B[100005];
int main(void) {
  register int i, lA, rA, lB, rB, sA, sB, la1, la2;
  scanf("%s%s", A + 1, B + 1), lena = strlen(A + 1), lenb = strlen(B + 1);
  for (i = 1; i <= lena; ++i) {
    if (A[i] != 'A')
      sumA[i] = sumA[i - 1] + 1, lastA[i] = i;
    else
      sumA[i] = sumA[i - 1], lastA[i] = lastA[i - 1];
    if (A[i] == 'B') A[i] = 'C';
  }
  for (i = 1; i <= lenb; ++i) {
    if (B[i] != 'A')
      sumB[i] = sumB[i - 1] + 1, lastB[i] = i;
    else
      sumB[i] = sumB[i - 1], lastB[i] = lastB[i - 1];
    if (B[i] == 'B') B[i] = 'C';
  }
  m = read();
  while (m--) {
    lA = read(), rA = read(), lB = read(), rB = read();
    sA = sumA[rA] - sumA[lA - 1], sB = sumB[rB] - sumB[lB - 1];
    la1 = rA - max(lastA[rA], lA - 1), la2 = rB - max(lastB[rB], lB - 1);
    if ((sA & 1) != (sB & 1)) {
      putchar('0');
      continue;
    }
    if (sA > sB) {
      putchar('0');
      continue;
    }
    if (la1 < la2) {
      putchar('0');
      continue;
    }
    if (sA == sB && (la1 - la2 % 3) != 0) {
      putchar('0');
      continue;
    }
    if (sA == 0 && sA < sB && la1 == la2) {
      putchar('0');
      continue;
    }
    putchar('1');
  }
  return 0;
}
