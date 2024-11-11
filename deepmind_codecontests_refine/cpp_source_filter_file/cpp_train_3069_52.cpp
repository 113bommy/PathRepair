#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<string> a(8);
  vector<string> b;
  int black = 0, white = 0;
  map<char, int> m;
  m['q'] = 9;
  m['r'] = 5;
  m['b'] = 3;
  m['n'] = 3;
  m['p'] = 4;
  m['k'] = 0;
  for (int i = 0; i < 8; i++) {
    cin >> a[i];
    b.push_back(a[i]);
    transform(a[i].begin(), a[i].end(), a[i].begin(), ::tolower);
  }
  for (int i = 0; i < 8; i++) {
    string s = a[i];
    string s1 = b[i];
    for (int j = 0; j < 8; j++)
      if (s[j] == s1[j] && s[j] != '.') {
        black += m[s[j]];
      } else if (s[j] != s1[j] && s[j] != '.') {
        white += m[s[j]];
      }
  }
  if (black == white)
    cout << "Draw";
  else
    cout << (black > white ? "Black" : "White");
}
