#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string s;
  int p = 0, m = 0;
  for (int i = 0; i < t; i++) {
    cin >> s;
    if (s == "++X" || s == "X++")
      p++;
    else
      m++;
  }
  cout << abs(p - m) << endl;
}
