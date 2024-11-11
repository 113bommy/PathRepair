#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  while (k > 0) {
    if (n % 10 != 0 && k >= n % 10) {
      k -= n % 10;
      n -= n % 10;
    } else if (n % 10 != 0 && k < n % 10) {
      k -= k;
      n -= k;
    } else if (n % 10 == 0) {
      n = n / 10;
      k--;
    }
  }
  cout << n << endl;
  return 0;
}
