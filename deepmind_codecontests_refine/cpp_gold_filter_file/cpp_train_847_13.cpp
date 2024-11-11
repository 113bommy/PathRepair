#include <bits/stdc++.h>
using namespace std;
char A[15], B[15], C[15];
long long D[20];
int main() {
  int i, j, k;
  D[0] = 1;
  for (i = 1; i < 20; i++) D[i] = D[i - 1] * 10;
  long long a, b, mod, s, p;
  cin >> a >> b >> mod;
  long long t = min(a, mod);
  for (i = 0; i <= t; i++) {
    s = (long long)i * D[9];
    p = s / mod;
    if (s % mod) p++;
    p *= mod;
    if (p > s + b) {
      break;
    }
  }
  if ((long long)i > t) {
    printf("2\n");
  } else {
    k = i;
    for (i = 0; i < 9; i++) C[i] = (k % D[9 - i]) / D[8 - i] + '0';
    C[9] = '\0';
    printf("1 %s\n", C);
  }
}
