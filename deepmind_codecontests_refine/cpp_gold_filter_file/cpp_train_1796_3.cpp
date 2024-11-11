#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  scanf("%d", &tc);
  for (int i = 0; i < tc; i++) {
    int N, K;
    scanf("%d %d", &N, &K);
    if (N < K) {
      printf("NO\n");
      continue;
    }
    if (N % 2 == 0) {
      if (2 * K <= N) {
        printf("YES\n");
        for (int j = 0; j < K - 1; j++) {
          if (j != 0) printf(" ");
          printf("%d", 2);
        }
        printf(" %d\n", N - (2 * (K - 1)));
      } else if (N == K) {
        printf("YES\n");
        for (int j = 0; j < K; j++) {
          if (j != 0) printf(" ");
          printf("%d", 1);
        }
        printf("\n");
      } else if (K % 2 != 0) {
        printf("NO\n");
      } else {
        bool flag = false;
        int count = 0;
        while (N > K) {
          count++;
          N -= 3;
          K -= 1;
          if (N == K) {
            flag = true;
            printf("YES\n");
            for (int l = 0; l < count; l++) {
              if (l != 0) printf(" ");
              printf("%d", 3);
            }
            for (int l = 0; l < N; l++) {
              printf(" %d", 1);
            }
            printf("\n");
            break;
          }
        }
        if (!flag) {
          printf("NO\n");
        }
      }
    } else {
      if (K % 2 != 1) {
        printf("NO\n");
      } else {
        printf("YES\n");
        for (int j = 0; j < K - 1; j++) {
          if (j != 0) printf(" ");
          printf("%d", 1);
        }
        printf(" %d\n", N - ((K - 1)));
      }
    }
  }
  return 0;
}
