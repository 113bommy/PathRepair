#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
int N, M, K;
int regro[limN];
char A[limN], B[limN], C[limN];
int dp[limN][limN][limN];
char sig[limN][limN][limN];
void kmp(int N, char* str, int* prevo) {
  int i = -1, j = 0;
  prevo[0] = -1;
  while (j < N) {
    while (i != -1 && str[i] != str[j]) i = prevo[i];
    i++, j++;
    prevo[j] = i;
  }
}
int maxLen(int a, int b, int c) {
  if (a == N || b == M) return 0;
  if (sig[a][b][c]) return dp[a][b][c];
  sig[a][b][c] = 'x';
  dp[a][b][c] = maxLen(a + 1, b, c);
  int w = maxLen(a, b + 1, c);
  if (w > dp[a][b][c]) {
    dp[a][b][c] = w;
    sig[a][b][c] = 'y';
  }
  if (A[a] == B[b]) {
    int i = c;
    while (i != -1 && C[i] != B[b]) i = regro[i];
    i++;
    if (i != K) {
      w = maxLen(a + 1, b + 1, i) + 1;
      if (w > dp[a][b][c]) {
        dp[a][b][c] = w;
        sig[a][b][c] = 'z';
      }
    }
  }
  return dp[a][b][c];
}
int main() {
  scanf("%s%s%s", A, B, C);
  N = strlen(A);
  M = strlen(B);
  K = strlen(C);
  kmp(K, C, regro);
  if (maxLen(0, 0, 0) == 0) {
    printf("0\n");
    return 0;
  }
  for (int a = 0, b = 0, c = 0; a < N && b < M;) {
    if (sig[a][b][c] != 'z') {
      if (sig[a][b][c] == 'x')
        a++;
      else
        b++;
      continue;
    }
    printf("%c", A[a]);
    while (c != -1 && C[c] != B[b]) c = regro[c];
    a++, b++, c++;
  }
  printf("\n");
}
