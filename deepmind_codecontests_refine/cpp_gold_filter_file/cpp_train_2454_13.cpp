#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = a; i >= 0; i--) {
    if (i == 0 && i + i * 2 + i * 4 != 0) {
      cout << "-1";
      return 0;
    }
    if (b >= i * 2 && c >= i * 4) {
      cout << i + i * 2 + i * 4;
      return 0;
    }
  }
  return 0;
}
