#include <bits/stdc++.h>
using namespace std;
int q, n;
string s;
int main() {
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> n >> s;
    if (n == 1) {
      cout << "NO" << endl;
      continue;
    } else if (n == 2) {
      if (s[0] >= s[1]) {
        cout << "NO" << endl;
        continue;
      }
    }
    cout << "YES" << endl << 2 << endl << s[0] << " ";
    for (int i = 1; i < s.size(); ++i) {
      cout << s[i];
    }
    cout << endl;
  }
}
