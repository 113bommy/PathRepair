#include <bits/stdc++.h>
using namespace std;
int c[2222][2222];
int main(int argc, char *argv[]) {
  for (int i = 0; i < 2222; i++)
    for (int j = 0; j < 2222; j++) {
      if (i == j || j == 0)
        c[i][j] = 1;
      else {
        if (j > i)
          c[i][j] = 0;
        else
          c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 1000000007;
      }
    }
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);
  printf("%d\n",
         (int)(((long long)c[N - 1][2 * K] * c[M - 1][2 * K]) % 1000000007));
  return 0;
}
