#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, l, r;
  std ::cin >> a >> b;
  if (a == 0 || b == 0) {
    std ::cout << "NO" << std ::endl;
  } else if (((a + b) % 2 == 1 && ((a - b == 1) || (b - a) == 1)) || a == b) {
    std ::cout << "YES" << std ::endl;
  } else {
    std ::cout << "NO" << std ::endl;
  }
  return 0;
}
