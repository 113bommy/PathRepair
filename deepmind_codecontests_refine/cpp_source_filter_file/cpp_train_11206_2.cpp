#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, i, j;
  cin >> n >> k;
  n += 1;
  for (i = 1; i <= k; i++) {
    if (n % k != 0 || k > n) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
