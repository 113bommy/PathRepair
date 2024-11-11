#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int k = 1, l = 1;
    while (l < n) {
      k *= 2;
      l += k;
    }
    n = (n * (n + 1)) / 2;
    if (k > n) {
      l -= k;
    }
    cout << n - 2 * l << endl;
  }
}
