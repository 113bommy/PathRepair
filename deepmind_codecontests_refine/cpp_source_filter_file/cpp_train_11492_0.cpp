#include <bits/stdc++.h>
int s_bos, b, s_grup = -1, n, m, arr[105][105], k, h[105];
void oku() {
  scanf("%d %d", &n, &m);
  int a, i, k, j;
  for (i = 0; i < n; i++) {
    scanf("%d", &k);
    for (j = 0; j < k; j++) {
      scanf("%d", &a);
      arr[i][a - 1] = 1;
    }
  }
}
void f(int x) {
  int i, j;
  h[x] = 1;
  for (i = 0; i < m; i++) {
    if (arr[x][i]) {
      b = 1;
      for (j = 0; j < n; j++)
        if (arr[j][i] && !h[j]) f(j);
    }
  }
}
void coz() {
  int i;
  for (i = 0; i < n; i++) {
    b = 0;
    if (!h[i]) {
      f(i);
      s_grup++;
      if (!b) s_bos++;
    }
  }
}
int main() {
  oku();
  coz();
  printf("%d", s_grup + (s_bos >= 2));
}
