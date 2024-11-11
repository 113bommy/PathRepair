#include <bits/stdc++.h>
using namespace std;
int test(string str) {
  int len = str.length();
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] == 'A')
      a += 1;
    else if (str[i] == 'B')
      b += 1;
    else if (str[i] == 'C')
      c += 1;
  }
  if (a == b && b - a == c) return 1;
  return 0;
}
int main() {
  int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    if (test(s))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
