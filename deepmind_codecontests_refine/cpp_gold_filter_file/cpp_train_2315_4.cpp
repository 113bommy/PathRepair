#include <bits/stdc++.h>
using namespace std;
string s;
int x = 0;
vector<int> d, u;
int main() {
  cin >> s;
  if (s.size() == 1) {
    if (s == "1")
      cout << 1 << endl << "+2^0";
    else
      cout << 0;
    return 0;
  }
  for (int i = 1; i < s.size() - 2; i++) {
    if (s[i + 1] == '1' && s[i - 1] == '1' && s[i] == '0' && s[i + 2] == '1') {
      d.push_back(i);
      s[i] = '1';
    } else if (s[i + 1] == '0' && s[i - 1] == '1' && s[i] == '1' &&
               s[i + 2] == '1') {
      d.push_back(i + 1);
      s[i + 1] = '1';
    }
  }
  for (int i = 1; i < s.size() - 1; i++) {
    if (s[i + 1] == '0' && s[i - 1] == '0' && s[i] == '1') {
      u.push_back(i);
      s[i] = '0';
    }
  }
  if (s[0] == '1' && s[1] == '0') {
    u.push_back(0);
    s[0] = '0';
  }
  if (s[s.size() - 1] == '1' && s[s.size() - 2] == '0') {
    u.push_back(s.size() - 1);
    s[s.size() - 1] = '0';
  }
  for (int i = 0; i < s.size(); i++) {
    if (x == 0 && s[i] == '1') {
      u.push_back(i - 1);
      x = 1;
    } else if (x == 1 && s[i] == '0') {
      d.push_back(i - 1);
      x = 0;
    }
  }
  if (x == 1) d.push_back(s.size() - 1);
  cout << u.size() + d.size() << endl;
  for (int i = 0; i < u.size(); i++) {
    cout << "+2^" << s.size() - u[i] - 1 << endl;
  }
  for (int i = 0; i < d.size(); i++) {
    cout << "-2^" << s.size() - d[i] - 1 << endl;
  }
}
