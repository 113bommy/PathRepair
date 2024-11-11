#include <bits/stdc++.h>
const int MAXN = 2005;
int N, X[MAXN], Y[MAXN], cnt;
bool C[10000005];
int main() {
  int i, j;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) scanf("%d", X + i), C[X[i]] = 1;
  for (i = 1; i <= N; i++) scanf("%d", Y + i), C[Y[i]] = 1;
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= N; j++) {
      if (C[(X[i] ^ Y[i])]) cnt++;
    }
  }
  printf("%s", (cnt % 2 == 0) ? "Koyomi" : "Karen");
  return 0;
}
