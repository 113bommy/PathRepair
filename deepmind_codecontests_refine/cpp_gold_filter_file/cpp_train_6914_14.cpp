#include <bits/stdc++.h>
const int MAXN = 310;
const int MAXA = 1001000;
int N;
int ar[MAXN];
int ans[MAXA];
int cnt = 0;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < ar[i]; ++j) {
      printf("P");
      if (j + 1 < ar[i]) {
        if (i + 1 < N)
          printf("RL");
        else
          printf("LR");
      }
    }
    if (i + 1 < N) printf("R");
  }
  printf("\n");
  return 0;
}
