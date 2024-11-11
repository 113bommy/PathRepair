#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, c, x;
    cin >> n;
    c = 1;
    for (int k = 2; k <= 32; k++) {
      if (n % (long long)(pow(2, k) - 1) == 0) {
        x = n / (long long)((pow(2, (k))) - 1);
        break;
      }
    }
    cout << x << endl;
  }
  return 0;
}
