#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  long long sum;
  cin >> t;
  while (t--) {
    cin >> n;
    n = n / 2;
    sum = ((n * (n + 1) * (2 * n + 1)) / 6) * 8;
    cout << sum << endl;
  }
}
