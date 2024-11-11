#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
int main() {
  cin >> a >> b >> c;
  if (abs(a - b) < 2) {
    cout << a + b + 2 * c;
  } else {
    cout << 2 * c + 2 * min(a, b) + 1;
  }
}
