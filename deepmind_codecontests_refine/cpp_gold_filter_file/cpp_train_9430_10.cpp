#include <bits/stdc++.h>
using namespace std;
const int maxN = 110;
char A[maxN], B[maxN], C[maxN];
inline int baga(char S[]) {
  int ret = 0;
  for (int i = 0; S[i] != 0; i++)
    if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u')
      ret++;
  return ret;
}
int main() {
  int i, j;
  fgets(A, 106, stdin);
  fgets(B, 106, stdin);
  fgets(C, 106, stdin);
  int a = baga(A);
  int b = baga(B);
  int c = baga(C);
  if (a == 5 && b == 7 && c == 5) {
    printf("YES\n");
    return 0;
  }
  printf("NO\n");
  return 0;
}
