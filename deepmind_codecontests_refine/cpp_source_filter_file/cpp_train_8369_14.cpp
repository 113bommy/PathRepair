#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n;
char s[109];
int main() {
  gets(s);
  n = strlen(s);
  int l = n;
  for (int i = 1; i < n; i++) {
    s[l] = '0';
    s[++l] = 0;
  }
  n = l;
  reverse(s, s + n);
  long long t = 2, ans = 0;
  if (s[0] == '1') ans = 1;
  for (int i = 1; s[i]; i++) {
    int key = s[i] - '0';
    if (key) ans = (ans + t) % mod;
    t = (t * 2) % mod;
  }
  cout << ans << endl;
  return 0;
}
