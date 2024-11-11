#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i;
  cin >> t;
  while (t--) {
    int n, m;
    string s;
    cin >> n >> s;
    m = n;
    for (i = 0; i < n; i++) {
      if (s[i] == '1') {
        m = max(m, 2 * max(i + 1, n - i));
      }
    }
    cout << m << endl;
  }
}
