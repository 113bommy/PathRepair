#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, s1 = "";
    cin >> s;
    if (n == 1)
      s1 += s;
    else {
      s1 += s[(2 * n - 1) / 2];
      for (int i = 1; i < n; i++) {
        s1 += s[i - 1];
      }
    }
    cout << s1 << "\n";
  }
}
