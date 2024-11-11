#include <bits/stdc++.h>
using namespace std;
int const lim = 1e6;
long long ans[lim + 3], mark[lim + 3], pre[lim + 3], suf[lim + 3];
char s[lim + 3 + 3];
int inf = 1e9;
int n;
void call(bool shit) {
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'D') pre[i] += i;
    pre[i] += pre[i - 1];
  }
  for (int i = n; i >= 0; i--) {
    if (i != 0 && s[i] == 'U') suf[i] += n - i + 1;
    suf[i] += suf[i + 1];
  }
  long long l = 0, r = 0, cnt_l = 0, cnt_r = 0;
  for (int i = 1; i <= n; i++) {
    int p = i;
    if (shit) p = n - i + 1;
    if (s[i] == 'D') {
      cnt_l--;
      continue;
    }
    while (cnt_l <= cnt_r && ++r <= n)
      if (s[r] == 'D') cnt_l++;
    if (r > n) r = n;
    if (cnt_l > cnt_r) {
      ans[p] = (pre[r] - pre[i - 1] - (cnt_l)*i * 1ll) * 2ll +
               (suf[l] - suf[i] - (n - i + 1) * cnt_r * 1ll) * 2ll + i;
    } else {
      while (cnt_l < cnt_r && l < n) {
        if (s[l] == 'U') cnt_r--;
        l++;
      }
      ans[p] = (pre[r] - pre[i - 1] - (cnt_l)*i * 1ll) * 2ll +
               (suf[l] - suf[i] - (n - i + 1) * cnt_r * 1ll) * 2ll +
               (n - i + 1);
    }
    cnt_r++;
  }
}
int main() {
  cin >> n;
  cin.ignore();
  for (int i = 1; i <= n; i++) scanf("%c", &s[i]);
  call(false);
  reverse(s + 1, s + n + 1);
  for (int i = 1; i <= n; i++)
    if (s[i] == 'U')
      s[i] = 'D';
    else
      s[i] = 'U';
  memset(pre, 0, sizeof pre);
  memset(suf, 0, sizeof suf);
  call(true);
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
}
