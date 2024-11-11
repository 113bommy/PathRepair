#include <bits/stdc++.h>
using namespace std;
char s[20][20];
long long n;
long long tmp1[15][16400][65];
long long tmp2[15][16400][65];
long long visit[20];
long long a[20];
long long k;
long long fst;
long long all;
void dfs(long long pos, long long msk, long long ans) {
  if (pos == k) {
    tmp1[fst][msk][ans]++;
  }
  if (pos == n - k) {
    tmp2[visit[pos - 1]][msk][ans]++;
    return;
  }
  for (long long i = 0; i < n; i++) {
    if (msk & (1 << i)) continue;
    visit[pos] = i;
    dfs(pos + 1, msk | (1 << i), (ans << 1) | s[i][visit[pos - 1]]);
  }
}
long long cnt[20000];
signed main() {
  cin >> n;
  all = (1 << n) - 1;
  k = n / 2;
  long long allk = (1 << (k - 1));
  long long allkk = (1 << (n - k - 1));
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < n; j++) s[i][j] -= '0';
  for (fst = 0; fst < n; fst++) {
    visit[0] = fst;
    dfs(1, 1 << fst, 0);
  }
  for (long long msk = 0; msk < all; msk++) {
    long long c = 0;
    for (long long i = 0; i < n; i++)
      if (msk & (1 << i)) c++;
    if (c != k) continue;
    for (long long i = 0; i < n; i++)
      if (msk & (1 << i))
        for (long long j = 0; j < n; j++) {
          if (msk & (1 << j)) continue;
          for (long long mk = 0; mk < allk; mk++) {
            if (tmp1[i][msk][mk] == 0) continue;
            for (long long mkk = 0; mkk < allkk; mkk++) {
              cnt[mkk << (k) | s[i][j] << (k - 1) | mk] +=
                  tmp2[j][all ^ msk][mkk] * tmp1[i][msk][mk];
            }
          }
        }
  }
  for (long long i = 0; i < (1 << (n - 1)); i++) printf("%lld ", cnt[i]);
  return ~~(0 ^ 0 ^ 0);
}
