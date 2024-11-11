#include <bits/stdc++.h>
using namespace std;
long long a, b;
int main() {
  cin >> a >> b;
  if (b > 2 * a - 1) {
    cout << 0;
    return 0;
  }
  if (b > a + 1)
    cout << (2 * a - b + 1) / 2;
  else
    cout << b / 2;
  return 0;
}
