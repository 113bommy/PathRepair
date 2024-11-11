#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;
    int a[26] = {0};
    for (i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (char ch : s) {
        ++a[ch - 'a'];
      }
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] % n != 0) {
        ans = 0;
        break;
      }
    }
    if (ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
