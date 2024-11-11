#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
int main() {
  int l, r, t;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    if (l * 2 >= r)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
