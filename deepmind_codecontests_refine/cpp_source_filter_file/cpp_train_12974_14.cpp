#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b;
  for (int i = 1; i <= a; i++) {
    cin >> c, b -= 86400 - a;
    if (b <= 0) cout << i, exit(0);
  }
  return 0;
}
