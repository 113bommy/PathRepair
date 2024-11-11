#include <bits/stdc++.h>
using namespace std;
long long a, b, l, r, T, ans = 100, t, cnt = 0;
int vis[26];
int main() {
  cin >> a >> b >> l >> r;
  l--, r--, T = 2 * (a + b);
  if (a > b + 1)
    t = 2 * a - b;
  else
    t = a + 1;
  if (r - l >= T)
    ans = t;
  else {
    r %= T, l %= T;
    for (int i = 0; i < a; i++) {
      cnt = 0;
      char s[100];
      for (int j = 0; j < a; j++) s[j] = 'a' + j;
      for (int j = a; j < a + b; j++) s[j] = 'a' + i;
      memset(vis, 0, sizeof(vis));
      for (long long j = a + b - 1; j >= b; j--) vis[s[i] - 'a'] = 1;
      long long p = a + b, q = 0;
      while (p < 2 * a + b) {
        while (vis[q]) q++;
        s[p] = q + 'a', p++, q++;
      }
      for (int j = 2 * a + b; j < T; j++) s[j] = s[j - 1];
      memset(vis, 0, sizeof(vis));
      if (l <= r) {
        for (long long j = l; j <= r; j++) {
          if (!vis[s[j] - 'a']) cnt++, vis[s[j] - 'a'] = 1;
        }
      } else {
        for (long long j = 0; j <= r; j++) {
          if (!vis[s[j] - 'a']) cnt++, vis[s[j] - 'a'] = 1;
        }
        for (long long j = l; j < T; j++) {
          if (!vis[s[j] - 'a']) cnt++, vis[s[j] - 'a'] = 1;
        }
      }
      ans = min(cnt, ans);
    }
  }
  cout << ans;
  return 0;
}
