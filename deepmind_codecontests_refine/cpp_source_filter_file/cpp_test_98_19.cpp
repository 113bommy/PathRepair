#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, res;
  string keyboard, st;
  cin >> q;
  while (q--) {
    cin >> keyboard;
    cin >> st;
    int v[100];
    res = 0;
    for (int i = 0; i < st.length(); i++) {
      for (int j = 0; j < 26; j++) {
        if (keyboard[j] == st[i]) {
          v[i] = j;
          if (i > 0) res = abs(j - v[i - 1]);
        }
      }
    }
    if (st.length() == 1)
      cout << "0"
           << "\n";
    else
      cout << res << "\n";
  }
}
