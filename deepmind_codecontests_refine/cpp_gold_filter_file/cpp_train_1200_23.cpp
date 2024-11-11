#include <bits/stdc++.h>
using namespace std;
int cnt[22000000], pri[22000000 / 12], tot;
int f[100005][170];
bool fl[22000000];
void init() {
  fl[1] = 1;
  cnt[1] = 0;
  for (int i = 2; i < 22000000; i++) {
    cnt[i] = cnt[i - 1];
    if (cnt[2] > 10) exit(i);
    if (!fl[i]) {
      pri[++tot] = i;
      cnt[i]++;
    }
    for (int j = 1; i * pri[j] < 22000000 && j <= tot; j++) {
      fl[i * pri[j]] = 1;
      if (i % pri[j] == 0) break;
    }
  }
  for (int i = 1; i <= 100000; i++) f[i][0] = i;
  for (int i = 1; i < 170; i++)
    for (int j = 1; j <= 100000; j++)
      f[j][i] = f[j][i - 1] - f[j / pri[i]][i - 1];
}
map<long long, long long> mp;
long long dp(long long x, int y) {
  if (x <= 100000 && y < 170) return f[x][y];
  if (!y) return x;
  long long hsh = x * 1000 + y;
  if (mp.find(hsh) != mp.end()) return mp[hsh];
  return mp[hsh] = dp(x, y - 1) - dp(x / pri[y], y - 1);
}
long long calcpri(long long lim) {
  if (lim < 22000000) return (long long)cnt[lim];
  long long tmp = 1;
  for (; 1ll * pri[tmp] * pri[tmp] * pri[tmp] <= lim; tmp++)
    ;
  tmp--;
  long long ans = dp(lim, tmp) + tmp - 1;
  for (int id = tmp + 1; 1ll * pri[id] * pri[id] <= lim; id++)
    ans -= cnt[lim / pri[id]] - id + 1;
  return ans;
}
long long n;
int main() {
  init();
  scanf("%I64d", &n);
  long long ans = 0;
  for (int i = 1; 1ll * pri[i] * pri[i] * pri[i] <= n; i++) ans++;
  for (int i = 1; 1ll * pri[i] * pri[i] <= n; i++)
    ans += calcpri(n / pri[i]) - i;
  printf("%lld", ans);
}
