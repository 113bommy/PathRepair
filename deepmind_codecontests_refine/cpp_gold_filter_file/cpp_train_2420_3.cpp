#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int sum1 = 1 << n, sum2 = 0;
    for (int i = 1; i < n / 2; i++) {
      sum1 += 1 << i;
    }
    for (int i = n / 2; i < n; i++) {
      sum2 += 1 << i;
    }
    cout << sum1 - sum2 << endl;
  }
}
