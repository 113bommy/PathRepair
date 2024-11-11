#include <bits/stdc++.h>
using namespace std;
char s[111111];
int a[26], v = 0, p, ans;
int main() {
  gets(s);
  int n = strlen(s);
  for (int i = 0; i < 26; ++i) {
    a[i] = 0;
  }
  if (s[0] == '?')
    ans = 9;
  else
    ans = 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?' && i != 0) ++v;
    if (s[i] >= 'A' && s[i] <= 'J') a[s[i] - 'A'] = 1;
  }
  p = 0;
  for (int i = 0; i < 26; ++i) p += a[i];
  int mn = 10;
  for (int i = 0; i < p; ++i) {
    ans *= mn;
    mn--;
  }
  if (s[0] >= 'A' && s[0] <= 'J') ans = ans / 10 * 9;
  cout << ans;
  for (int i = 0; i < v; ++i) cout << 0;
  cout << endl;
  return 0;
}
