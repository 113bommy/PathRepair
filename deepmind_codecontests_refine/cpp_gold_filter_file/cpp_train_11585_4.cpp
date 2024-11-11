#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  long long a, b;
  while (T--) {
    cin >> a >> b;
    if (abs(a - b) % 10 == 0) {
      cout << abs(a - b) / 10 << '\n';
    } else {
      cout << abs(a - b) / 10 + 1 << '\n';
    }
  }
  return 0;
}
