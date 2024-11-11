#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 1, n, m, res = 1;
  cin >> n >> m;
  if (n >= m) {
    res += 6 - n;
    if (6 % res == 0) {
      cout << 1 << "/" << 6 / res << endl;
    } else {
      if (res % 2 == 0)
        cout << res / 2 << "/" << 6 / 2 << endl;
      else
        cout << res << "/" << 6 << endl;
    }
  } else {
    res += 6 - m;
    if (6 % res == 0) {
      cout << 1 << "/" << 6 % res << endl;
    } else {
      if (res % 2 == 0)
        cout << res / 2 << "/" << 6 / 2 << endl;
      else
        cout << res << "/" << 6 << endl;
    }
  }
  return 0;
}
