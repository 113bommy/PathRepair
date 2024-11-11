#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  int m = 0;
  for (int i = 0; i < n; i++) {
    for (int c = 1; c < n; c++) {
      string str = s.substr(i, c);
      string left = s.substr(i + 1);
      int len = str.length();
      int v = left.find(str);
      if (v != -1) {
        m = max(m, len);
      }
    }
  }
  cout << m;
  return 0;
}
