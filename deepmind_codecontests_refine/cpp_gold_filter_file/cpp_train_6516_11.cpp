#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n;
  string s;
  cin >> n;
  for (i = 0; i < n; i++) {
    s += "a";
  }
  for (i = 2; i < n; i = i + 4) {
    s[i] = 'b';
    if (i + 1 < n) {
      s[i + 1] = 'b';
    }
  }
  cout << s << endl;
  return 0;
}
