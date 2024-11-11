#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int M = 505;
int f[N][26], app[N];
int l[M], r[M], pl[M], pr[M];
char s[N], fl[5], c[M];
int res, m, L, R, n;
long long ans;
void work(int x, int v) {
  res -= (app[x] >= L && app[x] <= R);
  app[x] += v;
  res += (app[x] >= L && app[x] <= R);
}
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(0); j <= (int)(25); j++)
      f[i][j] = (f[i - 1][j] + (s[i] - 97 == j));
  scanf("%d%d%d", &m, &L, &R);
  for (int i = (int)(1); i <= (int)(m); i++) {
    scanf("%s%d%d", fl, &l[i], &r[i]);
    c[i] = fl[0] - 97;
    pl[i] = 0;
    pr[i] = 0;
  }
  for (int i = (int)(1); i <= (int)(n); i++) {
    res += (!L);
    for (int j = (int)(1); j <= (int)(m); j++) {
      for (; pr[j] + 1 <= i && f[i][c[j]] - f[pr[j]][c[j]] >= l[j];
           work(++pr[j], 1))
        ;
      for (; pl[j] + 1 <= i && f[i][c[j]] - f[pl[j]][c[j]] > r[j];
           work(++pl[j], -1))
        ;
    }
    ans += res;
  }
  printf("%lld\n", ans);
}
