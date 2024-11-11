#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> s;
map<string, int> c;
string a, b, t;
int z;
int f(string p) {
  int q(0), x(0), y(p.size() - 1);
  while (p[x] == '&') {
    x++;
    q--;
  }
  while (p[y] == '*') {
    y--;
    q++;
  }
  string r = p.substr(x, y + 1 - x);
  if (c.find(r) == c.end() || c[r] == -1)
    return -1;
  else
    return max(q + c[r], -1);
}
int main() {
  c["void"] = 0;
  cin >> n;
  getline(cin, t);
  s.resize(n);
  for (int i = 0; i < n; i++) getline(cin, s[i]);
  for (int i = 0; i < n; i++) {
    if (s[i][4] == 'd') {
      z = -1;
      for (int j = 8; z == -1 && j < s[i].size(); j++)
        if (s[i][j] == ' ') z = j;
      a = s[i].substr(8, z - 8);
      b = s[i].substr(z + 1, s[i].size() - z - 1);
      c[b] = f(a);
    } else {
      a = s[i].substr(7, s[i].size() - 7);
      z = f(a);
      if (z == -1)
        cout << "errtype"
             << "\n";
      else {
        cout << "void";
        for (int i = 0; i < z; i++) cout << "*";
        cout << "\n";
      }
    }
  }
  return 0;
}
