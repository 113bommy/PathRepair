#include <bits/stdc++.h>
int n, a[100005], vis[100005];
int p, tot, l[100005];
int m, x[100005], y[100005], z[100005];
int k, u[100005], v[100005];
int ans, s[100005], c[100005][2][5];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), vis[i] = 0;
  ans = m = k = 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      p = i;
      tot = 0;
      while (!vis[p]) l[++tot] = p, vis[p] = 1, p = a[p];
      while (tot >= 4) {
        if (tot == 4) {
          s[++ans] = 4;
          for (int i = 0; i <= 3; i++)
            c[ans][0][i] = l[i + 1], c[ans][1][i] = a[l[i + 1]];
          break;
        }
        s[++ans] = 5;
        for (int i = 0; i <= 4; i++)
          c[ans][0][i] = l[tot - i], c[ans][1][i] = a[l[tot - i]];
        c[ans][1][0] = l[tot - 4];
        a[l[tot - 4]] = a[l[tot]];
        tot -= 4;
      }
      if (tot == 2) {
        ++k;
        u[k] = l[1];
        v[k] = l[2];
      }
      if (tot == 3) {
        ++m;
        x[m] = l[1];
        y[m] = l[2];
        z[m] = l[3];
      }
    }
  while (m || k) {
    if (m == 1 && k == 0) {
      s[++ans] = 3;
      c[ans][0][0] = c[ans][1][2] = x[1];
      c[ans][0][1] = c[ans][1][0] = y[1];
      c[ans][0][2] = c[ans][1][1] = z[1];
      break;
    }
    if (m == 0 && k == 1) {
      s[++ans] = 2;
      c[ans][0][0] = c[ans][1][1] = u[1];
      c[ans][0][1] = c[ans][1][0] = v[1];
      break;
    }
    if (m > k) {
      s[++ans] = 5;
      c[ans][0][0] = c[ans][1][2] = x[m];
      c[ans][0][1] = c[ans][1][0] = y[m];
      c[ans][0][2] = c[ans][1][1] = z[m];
      m--;
      c[ans][0][3] = c[ans][1][4] = y[m];
      c[ans][0][4] = c[ans][1][3] = z[m];
      k++;
      u[k] = x[m];
      v[k] = y[m];
      m--;
    } else if (m) {
      s[++ans] = 5;
      c[ans][0][0] = c[ans][1][2] = x[m];
      c[ans][0][1] = c[ans][1][0] = y[m];
      c[ans][0][2] = c[ans][1][1] = z[m];
      m--;
      c[ans][0][3] = c[ans][1][4] = u[k];
      c[ans][0][4] = c[ans][1][3] = v[k];
      k--;
    } else {
      s[++ans] = 4;
      c[ans][0][0] = c[ans][1][1] = u[k];
      c[ans][0][1] = c[ans][1][0] = v[k];
      k--;
      c[ans][0][2] = c[ans][1][3] = u[k];
      c[ans][0][3] = c[ans][1][2] = v[k];
      k--;
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++) {
    printf("%d\n", s[i]);
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= s[i] - 1; k++) printf("%d ", c[i][j][k]);
      printf("\n");
    }
  }
}
