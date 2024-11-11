#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    if (i * (n / i) == n && n / i <= i) {
      cout << n / i << " " << i;
      return 0;
    }
  }
}
