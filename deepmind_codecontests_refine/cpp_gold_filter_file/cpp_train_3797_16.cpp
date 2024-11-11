#include <bits/stdc++.h>
using namespace std;
long long i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,
    dp1[155][155][105], dp2[155][155][105], ans[155][155];
char a[155], b[155];
string jess_chao_cai;
struct node {
  char c;
  char t, f;
} d[55];
int main() {
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    cin >> jess_chao_cai;
    d[i].c = jess_chao_cai[0];
    d[i].t = jess_chao_cai[3];
    d[i].f = jess_chao_cai[4];
  }
  for (i = 1; a[i]; i++) {
    dp1[i][i][a[i]] = 1;
    for (j = 1; j <= n; j++) {
      if (d[j].t == a[i] && d[j].f == a[i + 1]) dp1[i][i + 1][d[j].c] = 1;
    }
    p = max(i, p);
  }
  for (i = 1; b[i]; i++) {
    dp2[i][i][b[i]] = 1;
    for (j = 1; j <= n; j++) {
      if (d[j].t == b[i] && d[j].f == b[i + 1]) dp2[i][i + 1][d[j].c] = 1;
    }
    q = max(i, q);
  }
  for (i = 2; i <= p; i++) {
    for (l = 1; l <= p - i + 1; l++) {
      r = l + i - 1;
      for (k = l; k < r; k++) {
        for (j = 1; j <= n; j++) {
          dp1[l][r][d[j].c] |= (dp1[l][k][d[j].t] & dp1[k + 1][r][d[j].f]);
        }
      }
    }
  }
  for (i = 2; i <= q; i++) {
    for (l = 1; l <= q - i + 1; l++) {
      r = l + i - 1;
      for (k = l; k < r; k++) {
        for (j = 1; j <= n; j++) {
          dp2[l][r][d[j].c] |= (dp2[l][k][d[j].t] & dp2[k + 1][r][d[j].f]);
        }
      }
    }
  }
  for (i = 0; i <= p; i++) {
    for (j = 0; j <= q; j++) {
      ans[i][j] = 99999999;
    }
  }
  ans[0][0] = 0;
  for (i = 1; i <= p; i++) {
    for (j = 1; j <= q; j++) {
      for (l = 1; l <= i; l++) {
        for (r = 1; r <= j; r++)
          for (k = 'a'; k <= 'z'; k++)
            if (dp1[l][i][k] && dp2[r][j][k])
              ans[i][j] = min(ans[i][j], ans[l - 1][r - 1] + 1);
      }
    }
  }
  if (ans[p][q] >= 99999999)
    printf("-1\n");
  else
    printf("%lld\n", ans[p][q]);
}
