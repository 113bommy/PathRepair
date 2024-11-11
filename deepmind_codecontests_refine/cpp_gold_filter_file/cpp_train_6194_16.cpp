#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c = 0;
  cin >> a;
  while (a--) {
    cin >> b;
    if (b == 1) {
      cout << -1 << endl;
      c++;
      break;
    }
  }
  if (c == 0) cout << 1 << endl;
  return 0;
}
