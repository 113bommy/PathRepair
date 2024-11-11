#include <bits/stdc++.h>
using namespace std;
int n, i, j, nxt[1234567];
string s, t;
void kmp(string st) {
  int i, j = 0;
  for (i = 2; i <= n; i++) {
    while (j && st[i] != st[j + 1]) j = nxt[j];
    if (st[i] == st[j + 1]) j++;
    nxt[i] = j;
  }
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin >> n >> s >> t;
  s = " " + s;
  t = " " + t;
  n--;
  for (i = 1; i <= n; i++) {
    if (s[i] == 'W')
      s[i] = 'E';
    else if (s[i] == 'S')
      s[i] = 'N';
    else if (s[i] == 'E')
      s[i] = 'W';
    else if (s[i] == 'N')
      s[i] = 'S';
  }
  reverse(s.begin() + 1, s.end());
  kmp(s);
  j = 0;
  for (i = 1; i <= n; i++) {
    while (j && s[i] != t[j + 1]) j = nxt[j];
    if (s[i] == t[j + 1]) j++;
    if (i == n && j) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
