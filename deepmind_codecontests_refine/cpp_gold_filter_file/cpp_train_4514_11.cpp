#include <bits/stdc++.h>
using namespace std;
const int maxn = 150;
int n;
long long dp[maxn] = {1, 2};
char str[maxn], ss[maxn];
int main() {
  int t, i, j, cnt, st = -1;
  long long ans = 1;
  for (i = 2; i <= 50; i++) dp[i] = dp[i - 1] + dp[i - 2];
  cin >> str;
  n = strlen(str);
  for (i = 0; i < n && str[i] == 'B'; i++)
    ;
  for (j = 0; j < n && str[j] == 'A'; j++)
    ;
  if (i == n || j == n || n <= 3)
    cout << 1 << endl;
  else {
    for (j = i + 1;; j = (j + 2) % n) {
      if (str[(j - 1 + n) % n] == 'A' && str[j] == 'B') {
        if (j == (i - 1 + n) % n) {
          if (n / 2 == 1)
            cout << 1 << endl;
          else if (n / 2 == 2)
            cout << 3 << endl;
          else
            cout << dp[n / 2 - 1] + dp[n / 2 - 3] << endl;
          return 0;
        }
      } else
        break;
    }
    for (i = 0; i < n; i++) {
      if (str[i] == 'A' && str[(i + 1) % n] == 'A' && str[(i + 2) % n] == 'B' &&
          str[(i + 3) % n] == 'B') {
        cout << 0 << endl;
        return 0;
      }
    }
    for (i = 0; i < n; i = (i + 1) % n) {
      if (str[i] == 'B' && str[(i + 1) % n] == 'B') {
        st = (i + 1) % n;
        break;
      } else if (str[i] == 'B' && str[(i - 1 + n) % n] == 'A' &&
                 str[(i - 2 + n) % n] == 'A') {
        st = (i + 2) % n;
        break;
      }
    }
    for (i = 1, j = st; i <= n; i++, j = (j + 1) % n) ss[i] = str[j];
    for (i = 1; i < n;) {
      for (; i < n && !(ss[i] == 'B' && ss[i + 1] == 'A');) {
        if (ss[i] == 'A') {
          while (ss[i] == 'A') i++;
          i += 2;
        } else
          i++;
      }
      if (i >= n) break;
      for (cnt = 0; i < n && (ss[i] == 'B' && ss[i + 1] == 'A'); cnt++, i += 2)
        ;
      ans = ans * dp[ss[i] == 'A' ? cnt : cnt - 1];
    }
    cout << ans << endl;
  }
  return 0;
}
