#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, b, c;
    cin >> a >> b >> c;
    bool ans = true;
    for (int i = 0; i < a.size(); i++) {
      if (c[i] != b[i] && c[i] != a[i]) ans = false;
    }
    if (ans)
      cout << "YES/n";
    else
      cout << "NO/n";
  }
  return 0;
}
