#include <bits/stdc++.h>
using namespace std;
const int MOD = 51123987;
int ans;
int len[4000010], a[4000010];
char s[2000010];
int cnt, n;
int l[2000010], r[2000010];
inline int mo(int x) {
  if (x >= MOD) return x - MOD;
  return x;
}
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) a[i * 2] = s[i] - 'a', a[i * 2 - 1] = 26;
  cnt = n * 2 + 1;
  a[cnt] = 26;
  int maxn = 0, pos = 0;
  for (int i = 1; i <= cnt; i++) {
    if (maxn >= i)
      len[i] = min(maxn - i + 1, len[pos * 2 - i]);
    else
      len[i] = 1;
    while (i - len[i] > 0 && i + len[i] <= cnt &&
           a[i - len[i]] == a[i + len[i]])
      len[i]++;
    if (maxn < i + len[i] - 1) maxn = i + len[i] - 1, pos = i;
  }
  for (int i = 1; i <= cnt; i++) len[i] /= 2, ans = mo(ans + len[i]);
  ans = 1ll * (ans - 1) * ans / 2 % MOD;
  for (int i = 1; i <= n; i++)
    if (len[i + i])
      l[i + len[i + i] - 1]++, l[i - 1]--, r[i - len[i + i] + 1]++, r[i + 1]--;
  for (int i = 1; i < n; i++)
    if (len[i + i + 1])
      l[i + len[i + i + 1]]++, l[i]--, r[i - len[i + i + 1] + 1]++, r[i + 1]--;
  for (int i = n; i; i--) l[i] += l[i + 1];
  for (int i = 1; i <= n; i++) r[i] += r[i - 1];
  for (int i = 2; i <= n; i++) l[i] = mo(l[i] + l[i - 1]);
  for (int i = 1; i < n; i++) ans = mo(ans - 1ll * l[i] * r[i + 1] % MOD + MOD);
  printf("%d\n", ans);
}
