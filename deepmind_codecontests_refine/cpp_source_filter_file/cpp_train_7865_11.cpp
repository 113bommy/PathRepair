#include <bits/stdc++.h>
using namespace std;
int prime[2000010], tp;
int isp[2000010];
int ai[2000010];
int n, m;
void prime_cal() {
  tp = 0;
  memset(isp, 0, sizeof(isp));
  for (int i = 2; i < 2000010; ++i) {
    if (!isp[i]) prime[tp++] = i;
    for (int j = 0; j < tp && (long long)prime[j] * i < 2000010; ++j) {
      isp[i * prime[j]] = 1;
      if (i % prime[j] == 0) continue;
    }
  }
}
void solve() {
  if (m == 2) {
    puts("0");
    return;
  }
  for (int i = 0; i < n; ++i)
    if (ai[i] == 1) {
      puts("1");
      return;
    }
  sort(ai, ai + n);
  for (int pt = 0, i = 0; i < tp; ++i) {
    while (pt < n && ai[pt] < prime[i]) ++pt;
    if (pt < n && ai[pt] == prime[i]) isp[prime[i]] = 2;
  }
  int tot = 0;
  for (int i = 2; i <= m; ++i)
    if (isp[i] != 1) {
      if (isp[i] == 0) {
        puts("-1\n");
        return;
      }
      ++tot;
    }
  printf("%d\n", tot);
}
int main() {
  prime_cal();
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &ai[i]);
  solve();
  return 0;
}
