#include <bits/stdc++.h>
using namespace std;
const long long base = 1000000007;
string a[3];
map<char, int> m;
void sol(int pos, string s) {
  for (int i = (0); i < (s.size()); i++) {
    int l = m[s[i]] - 1, res;
    for (int j = (0); j < (a[l].size()); j++)
      if (a[l][j] == s[i]) {
        res = j;
        break;
      }
    cout << a[l][res + pos];
  }
}
int main() {
  char c;
  string s;
  a[0] = "asdfghjkl;";
  a[1] = "qwertyuiop[";
  a[2] = "zxcvbnm,";
  for (int i = (0); i <= (2); i++)
    for (int j = (0); j < (a[i].size()); j++) m[a[i][j]] = i + 1;
  cin >> c >> s;
  if (c == 'R')
    sol(-1, s);
  else
    sol(1, s);
}
