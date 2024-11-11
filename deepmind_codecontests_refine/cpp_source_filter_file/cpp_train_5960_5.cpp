#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  string s = "";
  for (int i = 0; i < n - 1; i++) {
    s += "U";
  }
  for (int i = 0; i < m - 1; i++) {
    s += "L";
  }
  int val = 1;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      if (val) {
        s += "R";
      } else {
        s += "L";
      }
    }
    if (i != n - 1) s += "D";
    val = 1 - val;
  }
  cout << s.size();
  cout << endl;
  cout << s << endl;
}
