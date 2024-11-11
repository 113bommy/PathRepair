#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const int MAX = 1000;
const int inf = 999999999;
const int p1 = 104393321, p2 = 104393329;
int main() {
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  for (int i = (0); i < int(s.size()); ++i)
    if (s[i] == '.') s[i] = ' ';
  istringstream sin(s);
  string k;
  sin >> k;
  if (k[k.size() - 1] == '9') {
    cout << "GOTO vasilisa." << endl;
    return 0;
  }
  string p;
  sin >> p;
  if (p[0] < '5')
    cout << k << endl;
  else
    cout << k.substr(0, k.size() - 1) << char(k[k.size() - 1] + 1) << endl;
  return 0;
}
