#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int s, x, t;
  cin >> t >> s >> x;
  if (x < t) {
    cout << "NO\n";
    return 0;
  }
  x -= t;
  if (x != 1 && (x % s == 0 || x % s == 1)) {
    cout << "YES\n";
  } else
    cout << "NO\n";
  return 0;
}
