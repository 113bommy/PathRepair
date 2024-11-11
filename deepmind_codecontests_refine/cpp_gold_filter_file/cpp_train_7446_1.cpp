#include <bits/stdc++.h>
using namespace std;
long long suf[500013], pre[500013], a, b, T;
int ans, n;
int time(char s) {
  if (s == 'w') return 1 + b;
  return 1;
}
int main() {
  string s;
  cin >> n >> a >> b >> T >> s;
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + time(s[i - 1]);
  for (int i = n; i > 0; i--) suf[i] = suf[i + 1] + time(s[i - 1]);
  for (int i = 1; i <= n; i++) {
    long long T1 = T - pre[i] - (a * (i - 1));
    if (T1 < 0) break;
    int s = i + 1, e = n, k = 0;
    while (s <= e) {
      int md = (s + e) / 2;
      if (T1 - (suf[md] + ((i + (n - md)) * a)) >= 0)
        k = n - md + 1, e = md - 1;
      else
        s = md + 1;
    }
    ans = max(ans, i + k);
  }
  for (int i = n; i > 0; i--) {
    long long T1 = T - pre[1] - suf[i] - (a * (n - i + 1));
    if (T1 < 0) break;
    int s = 1, e = i - 1, k = 0;
    while (s <= e) {
      int md = (s + e) / 2;
      if ((T1 - (pre[md] - pre[1] + (n - i + md) * a)) >= 0)
        k = md, s = md + 1;
      else
        e = md - 1;
    }
    ans = max(ans, n - i + 1 + k);
  }
  cout << ans << endl;
}
