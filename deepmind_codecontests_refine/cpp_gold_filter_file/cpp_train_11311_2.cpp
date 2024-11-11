#include <bits/stdc++.h>
using namespace std;
long long a, b;
int main() {
  cin >> a >> b;
  while (1) {
    if (a == 0 || b == 0) break;
    if (a >= 2 * b) a %= 2 * b;
    if (a == 0 || b == 0) break;
    if (b >= 2 * a) b %= 2 * a;
    if (!(a >= 2 * b || b >= 2 * a)) break;
  }
  cout << a << " " << b;
  return 0;
}
