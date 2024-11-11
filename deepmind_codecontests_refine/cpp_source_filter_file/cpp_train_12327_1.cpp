#include <bits/stdc++.h>
int p[3000], ans[9000000];
int main() {
  int N, i, j, inv = 0;
  scanf("%d", &N);
  for (i = 0; i < N; i++) scanf("%d", &p[i]);
  for (i = 0; i < N; i++)
    for (j = i + 1; j < N; j++)
      if (p[i] > p[j]) inv++;
  ans[1] = 1;
  ans[2] = 2;
  for (i = 3; i <= inv; i++) ans[i] = 4 + ans[i - 2];
  printf("%d.000000", ans[inv]);
  return 0;
}
