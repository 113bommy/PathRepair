#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, r;
    cin >> n >> r;
    long long int sum = 0;
    if (n == 1) {
      sum = 1;
    } else if (n <= r) {
      sum = ((n - 1) * (n)) / 2 + 1;
    } else {
      sum = (r * (r + 1)) / 2;
    }
    cout << sum << endl;
  }
}
