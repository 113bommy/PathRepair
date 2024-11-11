#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long f = 1, sum = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum * f;
}
int num[25];
double f[25][25][25], ans;
double vf[25], ve[25], rf, re, rs;
int nf, ne, ns, n, df, de;
double _get(double l1, double r1, double l2, double r2) {
  return max(0.0, min(r1, r2) - max(l1, l2));
}
void calc() {
  memset(vf, 0, sizeof(vf));
  memset(ve, 0, sizeof(ve));
  for (int i = 1; i <= n; i++) {
    vf[i] = 2 * rf * df;
    ve[i] = 2 * re * de;
    for (int j = 1; j <= n; j++) {
      vf[i] += num[j] * df * _get(j - rs, j + rs, i - rf, i + rf);
      ve[i] += num[j] * de * _get(j - rs, j + rs, i - re, i + re);
    }
  }
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= nf; j++) {
      for (int k = 0; k <= ne; k++) {
        double &ret = f[i][j][k];
        ret = max(ret, f[i - 1][j][k]);
        if (!num[i]) {
          if (k >= 2) ret = max(ret, f[i - 1][j][k - 2] + 2 * ve[i]);
          if (k && j) ret = max(ret, f[i - 1][j - 1][k - 1] + ve[i] + vf[i]);
          if (j >= 2) ret = max(ret, f[i - 1][j - 2][k] + 2 * vf[i]);
        }
        if (num[i] <= 1) {
          if (k) ret = max(ret, f[i - 1][j][k - 1] + ve[i]);
          if (j) ret = max(ret, f[i - 1][j - 1][k] + vf[i]);
        }
      }
    }
  }
  ans = max(ans, f[n][nf][ne]);
}
void dfs(int x, int rest) {
  if (x > n) {
    if (!rest) calc();
    return;
  }
  for (num[x] = 0; num[x] <= 2 && num[x] <= rest; num[x]++)
    dfs(x + 1, rest - num[x]);
}
int main() {
  scanf("%d%d%d", &nf, &ne, &ns);
  n = nf + ne + ns;
  n++;
  n /= 2;
  scanf("%lf%lf%lf", &rf, &re, &rs);
  rf = sqrt(pow(rf, 2) - 1);
  re = sqrt(pow(re, 2) - 1);
  rs = sqrt(pow(rs, 2) - 1);
  scanf("%d%d", &df, &de);
  dfs(1, ns);
  printf("%.8lf", ans);
  return 0;
}
