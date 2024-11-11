#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if ((b > a && c > 0 && !((b - a) % c)) ||
      (b < a && c < 0 && !((b - a) % c)) || (a == b)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
