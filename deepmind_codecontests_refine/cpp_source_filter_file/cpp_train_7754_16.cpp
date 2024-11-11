#include <bits/stdc++.h>
int const MAXN = 1e3 + 10;
bool mrk[MAXN];
int main() {
  int N;
  scanf("%d", &N);
  int atual = 1;
  for (int k = 1; k <= 1e6; k++) {
    int next = (k - 1) % N;
    mrk[atual] = true;
    atual = (atual + next) % N;
  }
  for (int i = 0; i < N; i++) {
    if (!mrk[i]) {
      printf("N\n");
      return 0;
    }
  }
  printf("S\n");
  return 0;
}
