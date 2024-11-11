#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353ll;
int N, T;
int sol[307];
int otherVal;
int sum = 0;
int main() {
  scanf("%d %d", &N, &T);
  otherVal = T;
  for (int i = N - 1; i >= 1; i--) {
    for (int j = 0; j < 16; j++) {
      printf("? %d %d\n", 1, i);
      printf("? %d %d\n", 1, i);
      fflush(stdout);
      int val;
      scanf("%d", &val);
      scanf("%d", &val);
      if (val != T) {
        if (val > otherVal) {
          sol[i + 1] = 0;
        } else {
          sol[i + 1] = 1;
          sum++;
        }
        otherVal = val;
        while (val != T) {
          printf("? %d %d\n", 1, i);
          printf("? %d %d\n", 1, i);
          fflush(stdout);
          scanf("%d", &val);
          scanf("%d", &val);
        }
        goto nextVal;
      }
    }
    if (otherVal > T) {
      sol[i + 1] = 1;
      sum++;
    } else {
      sol[i + 1] = 0;
    }
    otherVal = T;
  nextVal:;
  }
  if (sum < T) {
    printf("! 1");
  } else {
    printf("! 0");
  }
  for (int i = 2; i <= N; i++) {
    printf("%d", sol[i]);
  }
  printf("\n");
  return 0;
}
