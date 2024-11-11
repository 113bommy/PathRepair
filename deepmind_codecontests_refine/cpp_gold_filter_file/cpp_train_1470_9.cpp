#include <bits/stdc++.h>
const int MAX = 2000010, mod = 1000000007;
int n, m, mp[MAX], c[MAX], d[MAX], ds[MAX];
bool ty[MAX];
void upd(int i, int x) {
  x > d[i] ? d[i] = x, ds[i] = 1 : x == d[i] ? ds[i]++ : 0;
}
int main() {
  scanf("%d", &n);
  for (int p; n--;) scanf("%d", &p), c[p > m ? m = p : p]++;
  for (int i = 2; i <= m; i++)
    if (!mp[i])
      for (int j = i; j <= m; j += i)
        if (!mp[j]) mp[j] = i;
  int s = 1, t = 0;
  for (int i = m; i; i--)
    for (int j = c[i]; j--;) {
      if (d[i]) {
        for (int x = i - 1; x > 1;) {
          int p = mp[x], c = 0;
          for (; x % p == 0; x /= p) c++;
          for (int e = d[p]; e < c; e++) s = 1ll * s * p % mod;
          upd(p, c);
        }
        ty[i] = 1;
      } else
        upd(i, 1), s = 1ll * s * i % mod;
    }
  for (int i = m; i; i--)
    if (ty[i]) {
      bool fl = 1;
      for (int x = i - 1; x > 1;) {
        int p = mp[x], c = 0;
        for (; x % p == 0; x /= p) c++;
        if (c == d[p] && ds[p] == 1) fl = 0;
      }
      if (fl) t = 1;
    }
  printf("%d\n", (s + t) % mod);
}
