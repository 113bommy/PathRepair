#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum = 0, k, n;
  cin >> k >> n;
  while (n > 1) {
    if (n % k != 0) {
      cout << "NO";
      return 0;
    }
    n /= k;
    sum++;
  }
  cout << "YES" << endl << sum;
  return 0;
}
