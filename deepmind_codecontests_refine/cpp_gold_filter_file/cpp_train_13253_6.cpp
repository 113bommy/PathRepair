#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long ans = 1;
  if (k == 1 || k > n) {
    for (int i = 1; i <= n; ++i) {
      ans *= m;
      ans %= 1000000007;
    }
  } else if (k == n) {
    for (int i = 1; i <= (n + 1) / 2; ++i) {
      ans *= m;
      ans %= 1000000007;
    }
  } else {
    if (k % 2) {
      ans = m * m;
    } else {
      ans = m;
    }
  }
  cout << (ans % 1000000007) << endl;
  return 0;
}
