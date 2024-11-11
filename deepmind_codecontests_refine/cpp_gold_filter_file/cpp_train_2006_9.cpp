#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long int n, k;
    cin >> n >> k;
    if (n > k && ((n % 2 == 0 && k % 2 == 0) || (n % 2 != 0 && k % 2 != 0)))
      cout << "0" << endl;
    else if (n > k)
      cout << "1" << endl;
    else
      cout << abs(n - k) << endl;
  }
  return 0;
}
