#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '.') continue;
    for (int j = 1; j <= n / 4; j++) {
      int ct = 0;
      for (int k = i; k < n; k = k + j) {
        if (s[k] == '.')
          break;
        else
          ct++;
      }
      if (ct > 4) {
        cout << "yes" << endl;
        return 0;
      }
    }
  }
  cout << "no" << endl;
  return 0;
}
