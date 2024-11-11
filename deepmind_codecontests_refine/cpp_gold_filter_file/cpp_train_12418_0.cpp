#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main() {
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n * k; i++) {
      cin >> a[i];
    }
    long long sum = 0;
    int c = floor(n / 2), i = n * k - c;
    for (int r = 1; r <= k; r++) {
      sum += a[i];
      i -= c + 1;
    }
    cout << sum << endl;
  }
  return 0;
}
