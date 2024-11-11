#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string a, b, c;
    cin >> a >> b >> c;
    bool flag = 0;
    for (int i = 0; i < a.size(); i++) {
      if (!((a[i] == b[i] && b[i] == c[i]) ||
            (((a[i] == c[i]) || (b[i] == c[i]))) && (a[i] != b[i]))) {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
