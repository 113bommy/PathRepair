#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
void p() {
  for (int i = 1; i <= n; i++) {
    cout << "PRINT " << s[i - 1] << endl;
    if (i < n) cout << "RIGHT\n";
  }
}
void p2() {
  for (int i = n; i >= 1; i--) {
    cout << "PRINT " << s[i - 1] << endl;
    if (i > 1) cout << "LEFT\n";
  }
}
int main() {
  cin >> n >> m;
  cin >> s;
  if (m != n && m != 1) {
    if (m >= n / 2) {
      for (int i = m; i < n; i++) {
        cout << "RIGHT\n";
      }
      p2();
    } else {
      for (int i = m; i > 1; i--) {
        cout << "LEFT\n";
      }
      p();
    }
  } else if (m == 1)
    p();
  else
    p2();
  return 0;
}
