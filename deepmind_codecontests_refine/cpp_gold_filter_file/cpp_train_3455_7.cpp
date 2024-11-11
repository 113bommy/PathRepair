#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (n == 1 && k > 0) {
    cout << 0 << endl;
  } else {
    if (s[0] != '1' && s[0] != '0' && k > 0) {
      s[0] = '1';
      k--;
    }
    for (int i = 1; i < n; ++i) {
      if (s[i] == '0')
        continue;
      else if (k > 0) {
        s[i] = '0';
        k--;
      }
      if (k == 0) break;
    }
    cout << s << endl;
  }
}
