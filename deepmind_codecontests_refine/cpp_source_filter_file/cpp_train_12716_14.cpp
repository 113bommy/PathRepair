#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << 1 + 2 * c + 2 * min(a, b) + (a > b);
  return 0;
}
