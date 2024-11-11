#include <bits/stdc++.h>
using namespace std;
int main() {
  string b, s;
  cin >> s;
  int t = 0, i;
  for (i = 0; i < 5; i++) {
    cin >> b;
    if (s[0] == b[0] || s[1] == b[1]) {
      cout << "YES";
      t++;
      break;
    } else {
      continue;
    }
  }
  if (t == 0) cout << "NO";
}
