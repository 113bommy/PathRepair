#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m;
int a[maxn];
int cnt[maxn];
double ans;
double pro[maxn][110];
int u, v, s;
double fac[10];
void read(int &x) {
  char ch = getchar();
  int tag = 1;
  x = 0;
  while ((ch < '0' || ch > '9') && ch != '-') {
    ch = getchar();
  }
  if (ch == '-') {
    tag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= tag;
}
double C(int a, int b) {
  double u = 1;
  for (int i = a; i > a - b; i--) u *= i;
  u /= fac[b];
  return u;
}
int main() {
  fac[0] = 1;
  for (int i = 1; i <= 5; i++) fac[i] = fac[i - 1] * i;
  ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[i] = a[i];
    pro[i][a[i]] = 1;
    if (a[i] == 0) ans += 1;
  }
  scanf("%d", &m);
  while (m--) {
    scanf("%d%d%d", &u, &v, &s);
    ans -= pro[u][0];
    int tot = cnt[u];
    double z = C(tot, s);
    double sum;
    double p;
    for (int i = 0; i <= a[u]; ++i) {
      sum = 0;
      if (s + i > tot) {
        pro[u][i] = 0;
        continue;
      }
      p = C(tot - i, s) / z;
      for (int j = i; j <= i + s; ++j) {
        sum += pro[u][j] * p;
        p = p * (j + 1) / (j - i + 1) / (tot - j) * (s - j + i);
      }
      pro[u][i] = sum;
    }
    ans += pro[u][0];
    cnt[u] -= s;
    cnt[v] += s;
    printf("%.10lf\n", ans);
  }
  return 0;
}
