#include <bits/stdc++.h>
const int mod = 1000000007;
const int seed = 131;
char s[100005], t[1000005];
int hshv[1000005];
int powm(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = 1LL * ret * a % mod;
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return ret;
}
void gethash(char* s) {
  int len = strlen(s), now;
  now = 0;
  for (int i = 0; i < len; i++) {
    now = (1LL * now * seed + s[i]) % mod;
    hshv[i] = now;
  }
}
int get(int s, int t) {
  int a, b;
  if (s == 0)
    a = 0;
  else
    a = 1LL * hshv[s - 1] * powm(seed, t - s + 1) % mod;
  b = hshv[t];
  return (b - a + mod) % mod;
}
int main() {
  int cnt0, cnt1, lens, lent, len0, len1, hsh0, hsh1, p, ans;
  bool f;
  scanf("%s", s);
  scanf("%s", t);
  lens = strlen(s);
  lent = strlen(t);
  if (s[0] == '1')
    for (int i = 0; i < lens; i++) s[0] = ((s[0] - '0') ^ 1) + '0';
  cnt0 = 0;
  cnt1 = 0;
  for (int i = 0; i < lens; i++)
    if (s[i] == '0')
      cnt0++;
    else
      cnt1++;
  ans = 0;
  gethash(t);
  for (int i = 1; cnt0 * i < lent; i++) {
    if ((lent - cnt0 * i) % cnt1 != 0) continue;
    len0 = i;
    len1 = (lent - cnt0 * len0) / cnt1;
    hsh0 = -1;
    hsh1 = -1;
    p = 0;
    f = true;
    for (int j = 0; j < lens; j++) {
      if (s[j] == '0') {
        if (hsh0 == -1)
          hsh0 = get(p, p + len0 - 1);
        else if (get(p, p + len0 - 1) != hsh0) {
          f = false;
          break;
        }
        p += len0;
      } else {
        if (hsh1 == -1)
          hsh1 = get(p, p + len1 - 1);
        else if (get(p, p + len1 - 1) != hsh1) {
          f = false;
          break;
        }
        p += len1;
      }
    }
    if (f && hsh0 != hsh1) ans++;
  }
  printf("%d\n", ans);
}
