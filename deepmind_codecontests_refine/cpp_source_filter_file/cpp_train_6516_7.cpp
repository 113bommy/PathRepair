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
    s[i] = 'c';
    if (i + 1 < n) {
      s[i + 1] = 'c';
    }
  }
  cout << s << endl;
  return 0;
}
