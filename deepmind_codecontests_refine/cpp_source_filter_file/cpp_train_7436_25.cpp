#include <bits/stdc++.h>
using namespace std;
int N, K;
char a[105];
int main() {
  scanf("%d%d", &N, &K);
  scanf("%s", a);
  if (K <= N / 2) {
    while (K-- != 1) {
      printf("LEFT");
    }
    for (int i = 0; i < N; i++) {
      printf("PRINT %c\n", a[i]);
      if (i != N - 1) printf("RIGHT\n");
    }
  } else {
    while (K++ != N) {
      printf("RIGHT\n");
    }
    for (int i = N - 1; i >= 0; i--) {
      printf("PRINT %c\n", a[i]);
      if (i != 0) printf("LEFT\n");
    }
  }
  return 0;
}
