#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, k;
  cin >> t;
  string s;
  while (t--) {
    cin >> n;
    cin >> s;
    k = 0;
    k = s.size() - 11;
    if (k < 0)
      cout << "NO" << endl;
    else {
      int cnt = 0;
      for (int i = 0; i < k; i++) {
        if (s[i] == '8') {
          cnt = 1;
          break;
        }
      }
      if (cnt == 1)
        cout << "YES";
      else
        cout << "NO";
    }
    cout << endl;
  }
}
