#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    int count = 0;
    cin >> a >> b >> c;
    while (b >= 1 and c >= 2) {
      count += 3;
      b = b - 1;
      c = c - 2;
    }
    while (a >= 1 and b >= 2) {
      count += 3;
      a = a - 1;
      b = b - 2;
    }
    cout << count << endl;
  }
  return 0;
}
