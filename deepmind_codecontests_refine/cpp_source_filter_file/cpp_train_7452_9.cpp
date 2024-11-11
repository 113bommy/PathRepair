#include <bits/stdc++.h>
using namespace std;
const int N = int(3e5), mod = int(1e9) + 7;
int n, m, k;
int main() {
  cin >> n >> m >> k;
  if (n & 1) {
    for (int i = 2; i * i <= m; i++) {
      if (m % i == 0) {
        int res = m / i;
        if (res >= k && i > 1) {
          cout << "Timur";
          return 0;
        }
        if (i >= k && m / i > 1) {
          cout << "Timur";
          return 0;
        }
      }
    }
  }
  cout << "Marsel";
  return 0;
}
