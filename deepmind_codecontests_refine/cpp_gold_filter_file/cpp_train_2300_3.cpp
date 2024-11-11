#include <bits/stdc++.h>
int n, m;
int res[100005][2];
int cnt;
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  if (a == 0) {
    return b;
  }
  if (a > b) {
    return gcd(b, a % b);
  }
  return gcd(a, b % a);
}
int main() {
  int i, j;
  scanf("%d %d", &n, &m);
  if (n - 1 > m) {
    printf("Impossible\n");
    return 0;
  }
  for (i = 1; i < n; ++i) {
    for (j = i + 1; j <= n; ++j) {
      if (gcd(i, j) == 1) {
        res[cnt][0] = i;
        res[cnt][1] = j;
        cnt++;
        if (cnt == m) {
          goto l;
        }
      }
    }
  }
l:
  if (cnt == m) {
    printf("Possible\n");
    for (i = 0; i < m; ++i) {
      printf("%d %d\n", res[i][0], res[i][1]);
    }
  } else {
    printf("Impossible\n");
  }
  return 0;
}
