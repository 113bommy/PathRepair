#include <bits/stdc++.h>
using namespace std;
const int Len = 100010, Mod = 1000000007;
char s[Len], t[Len];
vector<char> a[Len];
int n;
long long val[20], len[20];
long long ksm(long long bas, int tm) {
  long long ret;
  if (tm == 0) return 1;
  if (tm == 1) return bas;
  ret = ksm(bas, tm / 2);
  ret = (ret * ret) % Mod;
  if (tm & 1) ret = (ret * bas) % Mod;
  return ret;
}
int main() {
  scanf("%s%d", s + 1, &n);
  for (int i = 1, lent; i <= n; i++) {
    scanf("%s", t + 1);
    lent = strlen(t + 1);
    for (int j = 1; j <= lent; j++) a[i].push_back(t[j]);
  }
  for (int i = 0; i < 10; i++) {
    len[i] = 1;
    val[i] = i;
  }
  len[10] = 0;
  int size, now, nlen, nval, v;
  for (int i = n; i >= 1; i--) {
    size = a[i].size();
    now = a[i][0] - '0';
    nlen = nval = 0;
    if (size == 3) {
      len[now] = 0;
      val[now] = 0;
    } else {
      for (int j = 3; j < size; j++) {
        v = a[i][j] - '0';
        nval = (nval * ksm(10, len[v]) % Mod + val[v]) % Mod;
        nlen = (nlen + len[v]) % Mod;
      }
      len[now] = nlen;
      val[now] = nval;
    }
  }
  int lens = strlen(s + 1);
  long long ans = 0;
  for (int i = 1; i <= lens; i++)
    ans = (ans * ksm(10, len[s[i] - '0']) % Mod + val[s[i] - '0']) % Mod;
  printf("%lld\n", ans);
  return 0;
}
