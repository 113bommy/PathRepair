#include <bits/stdc++.h>
using namespace std;
int pal(string str) {
  string tmp = str;
  reverse(tmp.begin(), tmp.end());
  if (str == tmp) return 0;
  return 1;
}
int main() {
  string str;
  int i, j;
  cin >> str;
  int n = str.length();
  for (i = 0; i < n; i++) {
    if (pal(str.substr(i, n - i)) || pal(str.substr(0, n - i))) {
      cout << n - i << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
