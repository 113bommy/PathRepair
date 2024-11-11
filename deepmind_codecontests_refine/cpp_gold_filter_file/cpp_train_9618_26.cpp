#include <bits/stdc++.h>
using namespace std;
const int NMax = 6000;
char A[NMax];
int N, SG[NMax], F[NMax];
int main() {
  scanf("%s", A);
  N = strlen(A);
  SG[0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++)
      F[SG[max(j - 2, 0)] ^ SG[max(0, i - j - 1)]] = i;
    for (int j = 0; j <= i; j++)
      if (F[j] != i) {
        SG[i] = j;
        break;
      }
  }
  int cnt = 0, ret = 0;
  for (int i = 1; i < N - 1; i++)
    if (A[i - 1] == A[i + 1]) {
      ret = 0;
      for (int j = 1; j < N; j++) {
        if (j != i + 1 && j != i - 1 && j != i && A[j - 1] == A[j + 1])
          cnt++;
        else {
          ret ^= SG[cnt];
          cnt = 0;
        }
      }
      ret ^= SG[cnt];
      if (ret == 0) {
        puts("First");
        printf("%d\n", i + 1);
        return 0;
      }
    }
  puts("Second");
  return 0;
}
