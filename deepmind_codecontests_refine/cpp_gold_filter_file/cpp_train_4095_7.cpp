#include <bits/stdc++.h>
using namespace std;
inline double sqr(double x) { return x * x; }
#pragma comment(linker, "/STACK:16777216")
int a[26], b[26], f[26][26];
string s, c;
int main() {
  cin >> s;
  int n;
  cin >> n;
  while (n--) {
    cin >> c;
    f[c[0] - 'a'][c[1] - 'a'] = 1;
    f[c[1] - 'a'][c[0] - 'a'] = 1;
  }
  n = 0;
  memset(b, 0, sizeof(b));
  b[s[0] - 'a'] = 1;
  while (++n < s.size()) {
    memcpy(a, b, sizeof(a));
    int x;
    x = s[n] - 'a';
    for (int i = int(0); i < int(26); ++i)
      if (!f[i][x]) b[x] = max(b[x], a[i] + 1);
  }
  n = b[0];
  for (int i = int(0); i < int(26); ++i) n = max(n, b[i]);
  cout << s.size() - n;
  return 0;
}
