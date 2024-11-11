#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 1000007;
int n;
char s[MAXN];
int preu[MAXN], pred[MAXN];
int numu[MAXN], numd[MAXN];
int indu[MAXN], indd[MAXN];
void init();
void input();
void work();
int main() {
  init();
  input();
  work();
}
void init() { ios::sync_with_stdio(false); }
void input() { scanf("%d%s", &n, s + 1); }
void work() {
  preu[0] = pred[0] = numu[0] = numd[0] = 0;
  for (int i = 1; i <= n; ++i) {
    preu[i] = preu[i - 1];
    pred[i] = pred[i - 1];
    numu[i] = numu[i - 1];
    numd[i] = numd[i - 1];
    if (s[i] == 'U') preu[i] += i, ++numu[i], indu[numu[i]] = i;
    if (s[i] == 'D') pred[i] += i, ++numd[i], indd[numd[i]] = i;
  }
  int uu, dd, us, ds, un, dn, cn;
  long long ans;
  for (int i = 1; i <= n; ++i) {
    un = numd[n] - numd[i];
    dn = numu[i - 1];
    cn = (((un) < (dn)) ? (un) : (dn));
    if (cn) {
      us = indd[numd[i] + cn];
      ds = indu[numu[i - 1] - cn + 1];
      ans = pred[us] - pred[i] -
            static_cast<long long>(i) * (numd[us] - numd[i]) +
            static_cast<long long>(i) * (numu[i - 1] - numu[ds - 1]) -
            preu[i - 1] + preu[ds - 1];
      ans *= 2;
    } else
      us = ds = i, ans = 0;
    if (s[i] == 'U') {
      if (un <= dn) {
        ans += n - i + 1;
      } else {
        ans += 2 * (indd[numd[us] + 1] - i) + i;
      }
    } else if (s[i] == 'D') {
      if (dn <= un) {
        ans += i;
      } else {
        ans += 2 * (i - indu[numu[ds - 1]]) + n - i + 1;
      }
    }
    printf("%I64d ", ans);
  }
  printf("\n");
}
