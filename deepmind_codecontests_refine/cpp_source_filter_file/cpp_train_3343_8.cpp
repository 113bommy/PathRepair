#include <bits/stdc++.h>
using namespace std;
const int SN = 1e5 + 7, TN = 1e6 + 7;
const unsigned long long mod = 1000000007, B = 39;
int l[2], n[2] = {0}, ind, d;
char s[SN], t[TN];
int slen, tlen, ans = 0;
unsigned long long hval[TN] = {0}, val[2], Base[TN];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> (s + 1) >> (t + 1);
  slen = strlen(s + 1), tlen = strlen(t + 1);
  bool flag;
  for (int i = 1; i <= slen; ++i)
    if (s[i] == '0')
      ++n[0];
    else
      ++n[1];
  Base[0] = 1;
  for (int i = 1; i <= tlen; ++i)
    hval[i] = (hval[i - 1] * B + t[i] - 'a' + 1) % mod,
    Base[i] = B * Base[i - 1];
  for (l[0] = 1; l[0] * n[0] < tlen; ++l[0]) {
    l[1] = (tlen - n[0] * l[0]) / n[1];
    if (n[0] * l[0] + n[1] * l[1] != tlen) continue;
    flag = 1, val[0] = val[1] = ind = 0;
    for (int i = 1; i <= slen; ++i) {
      d = (s[i] == '0') ? 0 : 1;
      if (val[d]) {
        if (val[d] !=
            (hval[ind + l[d]] - (hval[ind] * Base[l[d]]) % mod + mod) % mod) {
          flag = 0;
          break;
        }
      } else
        val[d] =
            (hval[ind + l[d]] - (hval[ind] * Base[l[d]]) % mod + mod) % mod;
      if (val[0] == val[1]) {
        flag = 0;
        break;
      }
      ind += l[d];
    }
    if (flag) ++ans;
  }
  cout << ans;
  cout << flush;
  return 0;
}
