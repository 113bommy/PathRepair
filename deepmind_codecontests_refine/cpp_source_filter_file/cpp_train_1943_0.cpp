#include <bits/stdc++.h>
using namespace std;
const int maxN = 1234;
const long long mod = 1000000007ll;
char s[maxN], e[maxN];
int Q, k;
long long p8[maxN], p10[maxN], yes[maxN], no[maxN];
inline int ATOI(char *v, int poi) {
  long long ret = 0;
  while (poi != -1) {
    ret = ret * 10 + v[poi] - '0';
    ret %= mod;
    poi--;
  }
  return (int)ret;
}
inline int solve(char *v) {
  int len = strlen(v);
  if (len == 0) return 0;
  int past = -1;
  long long ret = 0;
  for (int i = len; i > 0; i--) {
    if (past != -1 && past - i > k) past = -1;
    int luck = 0, oth = 0;
    for (int j = 0; j < v[i - 1] - '0'; j++) luck += (j == 4 || j == 7);
    oth = v[i - 1] - '0' - luck;
    if (past == -1) {
      ret += (oth * no[i] + luck * yes[i]) % mod;
      ret %= mod;
    } else {
      ret += luck * p10[i - 1];
      ret %= mod;
      int cnt = (i - past + k);
      if (past - k > 0) {
        ret += oth *
               (p8[cnt] *
                ((2 * yes[max(0, i - cnt - 1)] + 8 * no[max(0, i - cnt - 1)]) %
                 mod)) %
               mod;
        ret %= mod;
        ret += oth * (((p10[cnt] - p8[cnt]) * p10[max(0, i - cnt - 1)]) % mod);
        ret %= mod;
      } else {
        ret += oth * (p10[i - 1] - p8[i - 1]);
        ret %= mod;
      }
    }
    if (v[i - 1] == '4' || v[i - 1] == '7') {
      if (past != -1) {
        ret = (ret + ATOI(v, i - 2)) % mod;
        return (ret + mod) % mod;
      }
      past = i;
    }
  }
  return (ret % mod + mod) % mod;
}
inline void init() {
  p8[0] = 1, p10[0] = 1;
  for (int i = 1; i < maxN; i++) {
    p8[i] = (p8[i - 1] * 8ll) % mod;
    p10[i] = (p10[i - 1] * 10ll) % mod;
  }
  yes[1] = 0, no[1] = 0;
  for (int i = 2; i < maxN; i++) {
    no[i] = (2 * yes[i - 1] + 8 * no[i - 1]) % mod;
    for (int j = 1; j <= k; j++)
      if (i - j > 0) {
        yes[i] += p8[j - 1] * 2 * p10[i - j - 1];
        yes[i] %= mod;
      }
    if (i - k - 1 > 0) {
      yes[i] +=
          (p8[k] * ((2 * yes[i - k - 1] + 8 * no[i - k - 1]) % mod)) % mod;
      yes[i] %= mod;
    }
  }
}
inline bool islucky(char *v) {
  int past = 2 * maxN;
  for (int i = 0; v[i] != 0; i++)
    if (v[i] == '4' || v[i] == '7') {
      if (i - past <= k) return true;
      past = i;
    }
  return false;
}
int main() {
  scanf("%d%d", &Q, &k);
  init();
  while (Q) {
    scanf("%s %s", s, e);
    int lens = strlen(s), lene = strlen(e);
    reverse(s, s + lens);
    reverse(e, e + lene);
    cout << (solve(e) - solve(s) + islucky(e) + mod) % mod << endl;
    Q--;
  }
  return 0;
}
