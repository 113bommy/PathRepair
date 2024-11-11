#include <bits/stdc++.h>
using namespace std;
void printNumber(char a) {
  int tr = a - '0';
  cout << "> ";
  while (tr > 0) {
    cout << "+";
    tr--;
  }
  cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++.\n";
}
int main() {
  string x;
  getline(cin, x);
  string ac = "";
  vector<int> n;
  string s = "";
  for (int i = 0; i < x.length(); i++) {
    if (x[i] != '+' && x[i] != '-') {
      ac = ac + x[i];
    }
    if ((x[i] == '+' || x[i] == '-') || i == x.length() - 1) {
      int t = 0;
      stringstream geek(ac);
      geek >> t;
      n.push_back(t);
      if (x[i] == '+' || x[i] == '-') {
        s = s + x[i];
      }
      ac = "";
    }
  }
  int ar = n[0];
  for (int i = 1; i < n.size(); i++) {
    if (s[i - 1] == '+') {
      ar = ar + n[i];
    } else {
      ar = ar - n[i];
    }
  }
  s = to_string(ar);
  for (int i = 0; i < s.length(); i++) {
    printNumber(s[i]);
  }
  return 0;
}
