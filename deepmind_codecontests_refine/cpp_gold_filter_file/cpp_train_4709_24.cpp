#include <bits/stdc++.h>
using namespace std;
long long int a, b, c, d, n, m, k, l;
string s;
string h = "qwertyuiopasdfghjklzxcvbnm";
string g = "QWERTYUIOPASDFGHJKLZXCVBNM";
int main() {
  cin >> s;
  for (int i = 1; i < (int)s.size(); i++) {
    if (s[i] - 'a' < 0)
      b = 1;
    else
      c = 1;
  }
  if (c == 0 && s[0] - 'a' < 0) d = 1;
  if (c == 0 && s[0] - 'a' >= 0) d = 1;
  if (d == 0) {
    cout << s << endl;
    return 0;
  }
  for (int i = 0; i < (int)s.size(); i++) {
    for (int j = 0; j < h.size(); j++)
      if (s[i] == h[j]) cout << g[j];
    for (int j = 0; j < g.size(); j++)
      if (s[i] == g[j]) cout << h[j];
  }
  return 0;
}
