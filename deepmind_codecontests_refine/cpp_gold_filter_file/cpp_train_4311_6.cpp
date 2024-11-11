#include <bits/stdc++.h>
using namespace std;
int n, m, l = 0, a[33], b[33], S = 0, x;
char s[1111];
int main() {
  cin >> s >> n;
  m = strlen(s);
  if (n >= m) {
    cout << "1" << endl;
    cout << s;
    for (int i = 0; i < n - m; i++) cout << "a";
    return 0;
  }
  for (int i = 0; i < m; i++) a[s[i] - 'a']++;
  for (int i = 0; i < 26; i++)
    if (a[i]) l++;
  if (l > n) {
    cout << "-1";
    return 0;
  }
  x = 2;
  while (1) {
    S = 0;
    for (int i = 0; i < 26; i++)
      if (a[i]) {
        if (a[i] % x)
          b[i] = a[i] / x + 1;
        else
          b[i] = a[i] / x;
        S += b[i];
      }
    if (S <= n) {
      b[0] += n - S;
      cout << x << endl;
      for (int i = 0; i < 26; i++)
        for (int j = 0; j < b[i]; j++) cout << (char)('a' + i);
      return 0;
    }
    x++;
  }
  return 0;
}
