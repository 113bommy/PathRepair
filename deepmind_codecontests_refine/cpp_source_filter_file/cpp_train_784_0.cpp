#include <bits/stdc++.h>
using namespace std;
int const oo = 1e9, bound = 1e6, mod = oo + 7;
long long const OO = 1e18;
char tile[2][26];
string s;
int app[26];
int main() {
  cin >> s;
  memset(app, -1, sizeof app);
  int ed = -1, cr;
  for (int(i) = 0; (i) < (s.size()); (i)++) {
    if (i < s.size() - 1 && s[i] == s[i + 1]) {
      cout << "Impossible\n";
      return 0;
    }
    if (app[s[i] - 'A'] == -1) {
      app[s[i] - 'A'] = i;
    } else {
      ed = i;
      cr = s[i] - 'A';
      break;
    }
  }
  int i = 0, j = 13 - (ed - app[cr]) / 2, fl = 0, idx = app[cr], dir = 1;
  while (fl < 26) {
    tile[i][j] = s[idx];
    idx = (idx + 1) % 27;
    j += dir;
    fl++;
    if (j == 13) j = 12, i = 1, dir = -1;
    if (j == -1) j = 0, i = 0, dir = 1;
    if (s[idx] - 'A' == cr) idx = (idx + 1) % 27;
  }
  for (int(i) = 0; (i) < (2); (i)++) {
    for (int(j) = 0; (j) < (13); (j)++) cout << tile[i][j];
    cout << endl;
  }
  return 0;
}
