#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int cu = 0, cd = 0, cl = 0, cr = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s.substr(i, 1) == "U") cu++;
  }
  for (int i = 0; i < s.size(); i++) {
    if (s.substr(i, 1) == "D") cd++;
  }
  for (int i = 0; i < s.size(); i++) {
    if (s.substr(i, 1) == "L") cl++;
  }
  for (int i = 0; i < s.size(); i++) {
    if (s.substr(i, 1) == "R") cr++;
  }
  cout << min(cr, cl) * 2 + min(cd, cu) * 2 << endl;
}
