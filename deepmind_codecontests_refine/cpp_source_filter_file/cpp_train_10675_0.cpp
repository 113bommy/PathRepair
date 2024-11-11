#include <bits/stdc++.h>
using namespace std;
signed main() {
  string s;
  cin >> s;
  long long i = 0;
  for (; s[i] == '0'; i++)
    ;
  s = s.substr(i);
  long long n = ((long long)s.size()), p = -1;
  for (long long i = (0); i < (n); i++) {
    if (s[i] == '.') p = i;
  }
  if (p == ((long long)s.size()) - 1) s.erase(s.end() - 1), p = -1;
  n = ((long long)s.size());
  if (p == -1) {
    long long i = n - 1, E = n - 1;
    for (; s[i] == '0'; i--)
      ;
    s = s.substr(0, i + 1);
    if (E == 0)
      cout << s;
    else {
      cout << s[0];
      if (((long long)s.size()) > 1) cout << '.' << s.substr(1);
      cout << 'E' << E;
    }
    return 0;
  }
  long long p2 = -1;
  long long E = 0;
  for (long long i = (0); i < (n); i++) {
    if (s[i] != '0' && s[i] != '.') {
      E = p - ((i < p) ? (i + 1) : i);
      p2 = i;
      break;
    }
  }
  n = ((long long)s.size()) - 1;
  string t = "";
  t += s[p2];
  t += ".";
  t += s.substr(p2 + 1);
  s = t;
  for (long long i = (2); i < (((long long)s.size())); i++) {
    if (s[i] == '.') s.erase(s.begin() + i), i--;
  }
  i = n - 1;
  for (; s[i] == '0'; i--)
    ;
  s = s.substr(0, i + 1);
  if (s[((long long)s.size()) - 1] == '.') s.erase(s.end() - 1);
  cout << s;
  if (E) cout << 'E' << E;
  return 0;
}
