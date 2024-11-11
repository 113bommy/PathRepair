#include <bits/stdc++.h>
using namespace std;
const int N = (int)5 * 10e3 + 1;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (c == 0) {
    cout << ((a == b) ? "YES" : "NO");
    return 0;
  }
  int x = (b - a) / c;
  if (x >= 0 && ((b - a) % c) == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
