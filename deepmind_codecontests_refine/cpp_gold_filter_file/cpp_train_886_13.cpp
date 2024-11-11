#include <bits/stdc++.h>
using namespace std;
int color[10010], c[10010], d[10010], f[10010], N, t, x;
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", color + i);
    if (!f[color[i]]) f[color[i]] = i;
  }
  int m, col;
  for (int i = 1; i <= N; i++) {
    m = 1;
    col = color[i];
    d[col]++;
    for (int j = 1; j <= N; j++) {
      c[j] = 0;
    }
    c[color[i]]++;
    for (int j = i + 1; j <= N; j++) {
      c[color[j]]++;
      if ((c[color[j]] > m) || (c[color[j]] == m && color[j] < col)) {
        m = c[color[j]];
        col = color[j];
      }
      d[col]++;
    }
  }
  for (int i = 1; i < N; i++) printf("%d ", d[i]);
  printf("%d\n", d[N]);
}
