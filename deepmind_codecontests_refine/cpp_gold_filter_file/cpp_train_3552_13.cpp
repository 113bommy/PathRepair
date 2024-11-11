#include <bits/stdc++.h>
using namespace std;
const int M = 255;
const int MOD = 1e9 + 7;
int read() {
  int x = 0, flag = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * flag;
}
int n, m, k, cnt[26], H[M][M], t[M][M];
char s[M];
int l[M], c[2 * M];
long long ans;
int lowbit(int x) { return x & (-x); }
int Hash() {
  long long res = 0;
  for (int i = 0; i < 26; i++) res = (res * (m + 1) + cnt[i]) % MOD;
  return res;
}
void manacher() {
  int r = 0, C = 0;
  for (int i = 0; i < k; i++) {
    if (c[i] < -1) continue;
    l[i] = r > i ? min(l[2 * C - i], r - i + 1) : 1;
    while (i + l[i] < k && i - l[i] >= 0 && c[i + l[i]] == c[i - l[i]]) l[i]++;
    if (i + l[i] > r) {
      r = i + l[i] - 1;
      C = i;
    }
    ans += l[i] / 2;
  }
}
signed main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    memset(cnt, 0, sizeof cnt);
    for (int j = 1; j <= m; j++) {
      cnt[s[j] - 'a']++;
      H[i][j] = Hash();
      t[i][j] = t[i][j - 1] ^ (1 << (s[j] - 'a'));
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = i; j <= m; j++) {
      k = 0;
      c[k++] = -1;
      for (int l = 1; l <= n; l++) {
        int tmp = t[l][j] ^ t[l][i - 1];
        if ((!tmp) || (!(tmp ^ lowbit(tmp))))
          c[k++] = (H[l][j] - H[l][i - 1] + MOD) % MOD;
        else
          c[k++] = -(l + 1);
        c[k++] = -1;
      }
      manacher();
    }
  }
  printf("%lld\n", ans);
}
