#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, m, i, result = 1;
  cin >> n >> m;
  int x = 2;
  while (m > 0) {
    if (m % 2 == 1) {
      result = ((result % 1000000007) * (x % 1000000007)) % 1000000007;
    }
    x = ((x % 1000000007) * (x % 1000000007)) % 1000000007;
    m = m / 2;
  }
  result -= 1;
  int64_t fresult = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      fresult = ((fresult % 1000000007) * (result % 1000000007)) % 1000000007;
    }
    result = ((result % 1000000007) * (result % 1000000007)) % 1000000007;
    n = n / 2;
  }
  cout << fresult << endl;
  return 0;
}
