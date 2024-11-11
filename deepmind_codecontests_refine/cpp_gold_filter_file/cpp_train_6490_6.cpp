#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, mit;
  scanf("%d%d", &N, &M);
  mit = (M + 1) / 2;
  if (M % 2 == 0) {
    for (int i = 0, tmp; i < N; i++) {
      tmp = ((i % M) + 1) / 2;
      if ((i % M) % 2) {
        printf("%d\n", mit + tmp);
      } else {
        printf("%d\n", mit - tmp);
      }
    }
  } else {
    for (int i = 0, tmp; i < N; i++) {
      tmp = ((i % M) + 1) / 2;
      if ((i % M) % 2) {
        printf("%d\n", mit - tmp);
      } else {
        printf("%d\n", mit + tmp);
      }
    }
  }
  return 0;
}
