#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, s, x;
  cin >> t >> s >> x;
  if (t == x) {
    cout << "YES";
    return 0;
  }
  if (t > x) {
    cout << "NO";
    return 0;
  } else {
    x -= t;
    x %= s;
    x == 0 || x == 1 ? cout << "YES" : cout << "NO";
  }
}
