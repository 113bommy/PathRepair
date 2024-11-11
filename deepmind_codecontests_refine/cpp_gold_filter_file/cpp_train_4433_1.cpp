#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long int INFF = 1e17;
const double EPS = 1e-9;
const long long int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a = 0, c = 0, g = 0, t = 0, cnt = 0, no = 0;
  string s;
  cin >> n;
  cin >> s;
  for (int i = (0); i < (n); ++i) {
    if (s[i] == 'A')
      a++;
    else if (s[i] == 'C')
      c++;
    else if (s[i] == 'G')
      g++;
    else if (s[i] == 'T')
      t++;
  }
  cnt = max(a, max(c, max(g, t)));
  for (int i = (0); i < (n); ++i) {
    if (s[i] == '?') {
      if (a < cnt)
        s[i] = 'A', a++;
      else if (c < cnt)
        s[i] = 'C', c++;
      else if (g < cnt)
        s[i] = 'G', g++;
      else if (t < cnt)
        s[i] = 'T', t++;
      else
        no++;
    }
  }
  if (a == c && c == g && g == t && !(no % 4)) {
    cnt = no / 4;
    a = c = g = t = 0;
    for (int i = (0); i < (n); ++i) {
      if (s[i] == '?') {
        if (a < cnt)
          s[i] = 'A', a++;
        else if (c < cnt)
          s[i] = 'C', c++;
        else if (g < cnt)
          s[i] = 'G', g++;
        else if (t < cnt)
          s[i] = 'T', t++;
      }
    }
    cout << s << '\n';
  } else
    cout << "===" << '\n';
  return 0;
}
