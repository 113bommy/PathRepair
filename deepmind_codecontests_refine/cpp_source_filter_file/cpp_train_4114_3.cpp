#include <bits/stdc++.h>
using namespace std;
vector<string> a1;
vector<string> a2;
string s;
int main() {
  cin >> s;
  int n = s.size();
  string kek = "";
  bool a = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != ';' && s[i] != ',') kek.push_back(s[i]);
    if ((s[i] > '9' || s[i] < '0') && (s[i] != ';' && s[i] != ',') ||
        ((s[i] == ';' || s[i] == ',') && kek.size() == 0) ||
        (kek.size() == 1 && s[i] == '0'))
      a = 1;
    if (s[i] == ';' || s[i] == ',') {
      if (a == 0)
        a1.push_back(kek);
      else
        a2.push_back(kek);
      if (i == n - 1) {
        a2.push_back("");
        break;
      }
      kek = "";
      a = 0;
    }
    if (i == n - 1) {
      if (a == 0)
        a1.push_back(kek);
      else
        a2.push_back(kek);
      kek = "";
      a = 0;
    }
  }
  n = a1.size();
  if (n == 0)
    cout << '-' << endl;
  else
    cout << '\"';
  for (int i = 0; i < n; i++) {
    if (i != 0) cout << ",";
    cout << a1[i];
  }
  if (n != 0) cout << '\"' << endl;
  n = a2.size();
  if (n == 0)
    cout << '-' << endl;
  else
    cout << '\"';
  for (int i = 0; i < n; i++) {
    if (i != 0) cout << ",";
    cout << a2[i];
  }
  if (n != 0) cout << '\"' << endl;
  return 0;
}
