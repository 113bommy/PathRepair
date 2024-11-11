#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int i, j, z;
  for (i = 0; i <= t - 1; i++) {
    int n, k;
    cin >> n >> k;
    int sum = 0;
    int a;
    int x;
    if (n % 2 == 0)
      x = n / 2 - 1;
    else if (n % 2 != 0)
      x = n / 2;
    int K = k;
    for (j = 0; j <= n * k - 1; j++) {
      cin >> a;
      if (j == n * k - (n - x) * K) {
        sum += a;
        K--;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
