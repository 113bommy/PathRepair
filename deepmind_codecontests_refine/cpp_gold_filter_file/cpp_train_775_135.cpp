#include <bits/stdc++.h>
using namespace std;
int main() {
  int n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;
  bool first = true, second = false;
  while (true) {
    if (first) {
      n1 -= 1;
      if (n1 < 0) {
        cout << "Second";
        return 0;
      }
      first = false;
      second = true;
    } else if (second) {
      n2 -= 1;
      if (n2 < 0) {
        cout << "First";
        return 0;
      }
      first = true;
      second = false;
    }
  }
  return 0;
}
