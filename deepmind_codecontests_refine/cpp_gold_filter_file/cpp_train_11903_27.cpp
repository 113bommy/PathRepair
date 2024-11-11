#include <bits/stdc++.h>
using namespace std;
const int G = 1000 * 1000 + 10;
int a[G];
int l[G];
int r[G];
int main() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  int n = s.size();
  if (s[0] == '1') a[0]++;
  for (int i = 1; i < n; i++) {
    a[i] = a[i - 1] + s[i] - '0';
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      int t = 1;
      while (i < n - 1 && s[i] == s[i + 1]) {
        i++;
        t++;
      }
      i++;
      l[i] = t;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      int t = 1;
      while (i >= 0 && s[i] == s[i - 1]) {
        i--;
        t++;
      }
      i--;
      r[i] = t;
    }
  }
  long long ans = 0;
  if (!k) {
    for (int i = 0; i < n; i++) {
      int t = 0;
      while (i < n && s[i] == '0') {
        i++;
        t++;
      }
      ans += (1LL * t * (t + 1) / 2);
    }
    cout << ans << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      int ll = lower_bound(a, a + n, a[i] + k - 1) - a;
      if (ll < n) {
        ans += 1LL * (l[i] + 1) * (r[ll] + 1);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
