#include <bits/stdc++.h>
using namespace std;
long long cnt[2000010], acum_val[2000010], acum_cnt[2000010], vis[2000010];
int main() {
  int n, i, esq_l, esq_r, dir_l, dir_r, j, d;
  long long x, y, aux, ans;
  scanf("%d%lld%lld", &n, &x, &y);
  for (i = 1; i <= n; i++) scanf("%lld", &aux), cnt[aux]++;
  for (i = 1; i < 2000010; i++)
    acum_val[i] = acum_val[i - 1] + (cnt[i] * i),
    acum_cnt[i] = acum_cnt[i - 1] + cnt[i];
  ans = x * n;
  aux = 0;
  for (i = 1; i < 2000010; i++)
    if (i & 1) aux += (cnt[i] * (x < y ? x : y));
  ans = min(ans, aux);
  for (i = 3; i < 2000010; i++) {
    if (vis[i]) continue;
    d = min((int)(x / y), i / 2);
    aux = 0;
    for (j = i; j < 2000010; j += i) {
      vis[j] = 1;
      esq_l = max(1, j - d);
      esq_r = j - 1;
      dir_l = j - i + 1;
      dir_r = esq_l - 1;
      if (dir_r >= dir_l) aux += ((acum_cnt[dir_r] - acum_cnt[dir_l - 1]) * x);
      if (esq_r >= esq_l)
        aux += ((((acum_cnt[esq_r] - acum_cnt[esq_l - 1]) * j) -
                 (acum_val[esq_r] - acum_val[esq_l - 1])) *
                y);
    }
    ans = min(ans, aux);
  }
  printf("%lld\n", ans);
}
