#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  string a;
  cin >> a;
  int d = 1;
  while (true) {
    int pas = 0;
    bool usu = false;
    for (int i = 0; i < d; ++i)
      if (a[i] == a[i + d]) ++pas;
    for (int i = 0; true; ++i) {
      if (pas == d) {
        a.erase(i, d);
        usu = true;
        break;
      }
      if (i + 1 + 2 * d < a.size()) {
        if (a[i] == a[i + d]) --pas;
        if (a[i + d] == a[i + 2 * d]) ++pas;
      } else
        break;
    }
    if (usu)
      d = max(1, d / 2);
    else
      ++d;
    if (2 * d > a.size()) break;
  }
  cout << a;
  return 0;
}
