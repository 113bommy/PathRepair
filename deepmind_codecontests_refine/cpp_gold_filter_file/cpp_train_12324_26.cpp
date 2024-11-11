#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, j, m = 0, n;
  string s;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> s;
    if (s == "++X" || s == "X++")
      m += 1;
    else
      m -= 1;
  }
  cout << m << endl;
  return 0;
}
