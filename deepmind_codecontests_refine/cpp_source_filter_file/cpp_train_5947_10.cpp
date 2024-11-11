#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  char x, y;
  y = s[0];
  for (int i = 1; i < (n - 1); i++) {
    x = s[i];
    if (x != y) {
      cout << "YES" << endl;
      cout << y << x << endl;
      return 0;
    }
    y = x;
  }
  cout << "NO" << endl;
  return 0;
}
