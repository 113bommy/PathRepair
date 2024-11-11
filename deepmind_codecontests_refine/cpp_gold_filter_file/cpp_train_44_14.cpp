#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  long long res = 0;
  for (int i = 0; i <= a; ++i) {
    for (int j = 0; j <= b; ++j) {
      if (2 * n - i - 2 * j >= 0 && !((2 * n - i - 2 * j) % 4) &&
          2 * n - i - 2 * j <= 4 * c) {
        ++res;
      }
    }
  }
  cout << res << endl;
  return 0;
}
