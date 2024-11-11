#include <bits/stdc++.h>
using namespace std;
int main() {
  int c = 0, i;
  string s, p;
  cin >> s;
  for (i = 0; i < 5; i++) {
    cin >> p;
    if (s[0] == p[i] || s[1] == p[1]) {
      c++;
    }
  }
  if (c > 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
