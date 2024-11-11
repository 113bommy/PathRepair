#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    bool th = false;
    string a = "1", b = "1";
    for (int i = 1; !(1 == n - 1 && i != n - 1) &&
                    ((i <= n - 1 && n - 1 >= 1) || (i >= n - 1 && 1 >= n - 1));
         i += (1 <= n - 1 ? 1 : -1)) {
      if (th) {
        b += s[i];
        a += '0';
        continue;
      }
      if (s[i] == '2') {
        a += '1';
        b += '1';
      } else if (s[i] == '1') {
        a += '1';
        b += '0';
        th = true;
      } else {
        a += '0';
        b += '0';
      }
    }
    cout << a << "\n" << b << "\n";
  }
  return 0;
}
