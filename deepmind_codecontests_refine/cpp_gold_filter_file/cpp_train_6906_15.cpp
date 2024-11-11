#include <bits/stdc++.h>
using namespace std;
bool isSpell(string);
void printBuf(string);
int main() {
  ios_base::sync_with_stdio(false);
  string emp = "" + char(15);
  string buf = emp;
  string str;
  while (getline(cin, str)) {
    if (isSpell(str)) {
      if (buf != emp) printBuf(buf);
      cout << str << endl;
      buf = emp;
    } else {
      if (buf == emp)
        buf = str;
      else
        buf += str;
    }
  }
  if (buf != emp) printBuf(buf);
  return 0;
}
bool isSpell(string str) {
  stringstream ss(str);
  string test;
  ss >> test;
  return (test[0] == '#');
}
void printBuf(string buf) {
  stringstream ss(buf);
  string cur;
  while (ss >> cur) cout << cur;
  cout << endl;
}
