#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max((abs(a - b) + abs(b - c) + abs(c - a) - 4), 0) << endl;
  }
  return 0;
}
