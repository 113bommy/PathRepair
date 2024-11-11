#include <bits/stdc++.h>
using namespace std;
const int M = 200200;
const int N = 100200;
const int kind = 26;
const int inf = 1 << 29;
const double eps = 1e-6;
const double pi = acos(-1.0);
const double sq2 = sqrt(2.0);
string s;
int minzer, minu, maxzer, maxu;
bool check() {
  return (maxzer >= int(s.size() / 2) && minzer <= int(s.size() / 2) &&
          maxu >= int(s.size() / 2) + s.size() % 2 &&
          minu <= int(s.size() / 2) + s.size() % 2);
}
int main() {
  while (cin >> s) {
    minzer = minu = maxzer = maxu = 0;
    int bcz = -1, bcu = -1, wcz = -1, wcu = -1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        wcz = bcz = i;
        minzer++;
      } else if (s[i] == '1') {
        wcu = bcu = i;
        minu++;
      } else if (s[i] == '?') {
        bcu = bcz = i;
        maxzer++;
      }
    }
    maxu = maxzer + minu;
    maxzer += minzer;
    if (maxzer >= int((s.size() - 2) / 2) + 2) cout << "00" << endl;
    if (check()) {
      if (wcu > bcz)
        cout << "01" << endl;
      else {
        if (int(s.size() / 2) + s.size() % 2 - minu > 0 && bcu > wcz)
          cout << "01" << endl;
      }
      if (wcz > bcu)
        cout << "10" << endl;
      else {
        if (int(s.size() / 2) - minzer > 0 && bcz > wcu) cout << "10" << endl;
      }
    }
    if (maxu >= min(s.size() - 2, int((s.size() - 2) / 2) + s.size() % 2) + 2)
      cout << "11" << endl;
  }
  return 0;
}
