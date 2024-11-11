#include <bits/stdc++.h>
using namespace std;
int n, ma, a[1111], kk;
string s[1111];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = (1), _b = (n); i <= _b; i++) cin >> a[i];
  for (int i = (2), _b = (n); i <= _b; i++)
    if (i % 2 == 0)
      a[i] = a[i - 1] - a[i];
    else
      a[i] = a[i - 1] + a[i];
  ma = -1000000;
  for (int i = (0), _b = (n); i <= _b; i++) ma = max(ma, a[i]);
  for (int i = (0), _b = (n); i <= _b; i++) a[i] = ma - a[i];
  kk = 0;
  for (int i = (0), _b = (n); i <= _b; i++) kk = max(kk, a[i]);
  for (int i = (1), _b = (n); i <= _b; i++) {
    if (a[i - 1] > a[i]) {
      s[a[i - 1]] += "/";
      for (int j = (a[i - 1] - 1), _a = (a[i] + 1); j >= _a; j--) {
        while (s[j].length() < s[j + 1].length()) s[j] += " ";
        s[j] += "/";
      }
    } else {
      s[a[i - 1] + 1] += "\\";
      for (int j = (a[i - 1] + 2), _b = (a[i]); j <= _b; j++) {
        while (s[j].length() < s[j - 1].length()) s[j] += " ";
        s[j] += "\\";
      }
    }
  }
  ma = 0;
  for (int i = (1), _b = (n); i <= _b; i++) {
    int x = s[i].length();
    ma = max(ma, x);
  }
  for (int i = (1), _b = (n); i <= _b; i++)
    while (s[i].length() < ma) s[i] += " ";
  for (int i = (1), _b = (kk); i <= _b; i++) cout << s[i] << "\n";
  return 0;
}
