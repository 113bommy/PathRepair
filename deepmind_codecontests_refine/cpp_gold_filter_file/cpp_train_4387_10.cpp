#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, a = 0;
  string s, ss;
  cin >> s;
  for (i = 0; i < 5; i++) {
    cin >> ss;
    if (s[0] == ss[0] || s[1] == ss[1]) {
      a++;
    }
  }
  if (a > 0) {
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
