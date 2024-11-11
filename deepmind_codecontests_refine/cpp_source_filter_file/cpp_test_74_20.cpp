#include <bits/stdc++.h>
int a[1001], b[1001], sum = 0, s[10000000], S = 0, n, k, I[501], got,
                      taken[1001], J[501][80000], ns[100000], sn[10000000], m;
int find(int i, int tail) {
  int j, l;
  if (i == 0) {
    if (s[S] == 1) {
      got = 1;
    }
    if (s[S] == 0) {
      s[S] = 1;
      m++;
      ns[m] = S;
      sn[S] = m;
      for (l = 1; l <= k; l++) {
        J[l][m] = I[l];
      }
    }
    return (0);
  }
  if (i >= 1) {
    for (j = tail + 1; j <= n + 1 - i && got == 0; j++) {
      S = S + b[j];
      if (S <= sum / 2) {
        I[i] = j;
        find(i - 1, j);
      }
      if (got == 1) break;
      S = S - b[j];
    }
  }
  return (0);
}
int main() {
  int find(int, int);
  int x, odd = 0, even = 0, O[1001], E[1001];
  scanf("%d", &n);
  for (x = 1; x <= n; x++) {
    scanf("%d", &b[x]);
    sum = sum + b[x];
    if (b[x] % 2) {
      odd++;
      O[odd] = b[x];
    } else {
      even++;
      E[even] = b[x];
    }
  }
  if (n == 2) {
    if (b[1] == b[2]) {
      printf("YES\n0 %d", b[1]);
    } else {
      printf("NO");
    }
    return (0);
  }
  if (n == 3) {
    if (even == 3 || even == 1) {
      a[3] = (b[2] + b[3] - b[1]) / 2;
      a[2] = b[2] - a[3];
      a[1] = b[3] - a[3];
      printf("YES\n%d %d %d", a[3], a[2], a[1]);
    }
    if (even == 2) {
      if (E[1] == E[2]) {
        printf("YES\n0 %d %d", E[1], O[1]);
      } else {
        printf("NO");
      }
    }
    if (even == 0) {
      if (b[1] == b[2]) {
        printf("YES\n0 %d %d", b[1], b[3]);
        return (0);
      }
      if (b[1] == b[3]) {
        printf("YES\n0 %d %d", b[1], b[2]);
        return (0);
      }
      if (b[2] == b[3]) {
        printf("YES\n0 %d %d", b[1], b[2]);
        return (0);
      }
      printf("NO");
    }
  }
  if (n >= 4) {
    if (odd == 1 || odd == 0) {
      a[1] = (E[1] + E[3] - E[2]) / 2;
      a[2] = (E[1] + E[2] - E[3]) / 2;
      a[3] = (E[2] + E[3] - E[1]) / 2;
      for (x = 1; x <= odd; x++) {
        a[3 + x] = O[x] - a[1];
      }
      for (x = 4; x <= even; x++) {
        a[x + odd] = E[x] - a[1];
      }
      printf("YES\n");
      for (x = 1; x <= n; x++) {
        printf("%d ", a[x]);
      }
      return (0);
    }
    if (odd >= 2 && even >= 1) {
      a[1] = (O[1] + E[1] - O[2]) / 2;
      a[2] = (O[1] + O[2] - E[1]) / 2;
      a[3] = (O[2] + E[1] - O[1]) / 2;
      for (x = 3; x <= odd; x++) {
        a[x + 1] = O[x] - a[1];
      }
      for (x = 2; x <= even; x++) {
        a[x + odd] = E[x] - a[1];
      }
      printf("YES\n");
      for (x = 1; x <= n; x++) {
        printf("%d ", a[x]);
      }
      return (0);
    }
    if (even == 0) {
      got = 0;
      m = 0;
      for (k = 1; k <= n / 2; k++) {
        for (x = 1; x <= m; x++) {
          s[ns[x]] = 0;
          sn[ns[m]] = 0;
        }
        find(k, 0);
        if (got) break;
      }
      if (got == 0) {
        printf("NO");
      }
      if (got) {
        printf("YES\n");
        for (x = 1; x <= k; x++) {
          taken[I[x]] = 1;
          taken[J[x][sn[S]]] = 1;
        }
        a[1] = 0;
        for (x = 2; x <= 2 * k; x++) {
          if (x % 2 == 0) {
            a[x] = b[I[x / 2]] - a[x - 1];
          } else {
            a[x] = b[J[(x - 1) / 2][sn[S]]] - a[x - 1];
          }
        }
        int f = 2 * k;
        for (x = 1; x <= n; x++) {
          if (taken[x] == 0) {
            f++;
            a[f] = b[x];
          }
        }
        for (x = 1; x <= n; x++) {
          printf("%d ", a[x]);
        }
      }
    }
  }
}
