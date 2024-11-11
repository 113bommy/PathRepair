#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a;
    cin >> a;
    if (a >= 4) {
      cout << a % 2 << '\n';
    } else {
      cout << 4 - a << '\n';
    }
  }
}
