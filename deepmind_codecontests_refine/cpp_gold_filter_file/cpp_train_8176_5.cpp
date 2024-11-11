#include <bits/stdc++.h>
using namespace std;
char s[50002];
int main() {
  int n = 0, t = 0;
  while (cin >> s[n++])
    ;
  for (int i = 25; i < n; i++) {
    int a[30] = {0}, p = 0, q = 0, l = 0;
    for (int j = i; j > i - 26; j--)
      if (s[j] == '?')
        p++;
      else
        a[int(s[j] - 'A')]++;
    for (int j = 0; j < 26; j++)
      if (a[j] == 1) l++;
    if (l + p == 26) {
      for (int j = i - 25; j <= i; j++)
        if (s[j] == '?') {
          while (a[q] > 0) q++;
          s[j] = char(q + 'A');
          a[q]++;
        }
      t = 1;
    }
    if (t) break;
  }
  if (t)
    for (int i = 0; i < n - 1; i++)
      if (s[i] == '?')
        cout << 'A';
      else
        cout << s[i];
  else
    cout << -1;
  return 0;
}
