#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int d = a + b;
    int sum = 0;
    if (a == b) {
      cout << sum << "\n";
    } else {
      for (int i = 1; i <= 1000; ++i) {
        d += i;
        if (d % 2 == 0 && (d / 2) >= max(a, b)) {
          sum++;
          break;
        }
        sum++;
      }
      cout << sum << "\n";
    }
  }
  return 0;
}
