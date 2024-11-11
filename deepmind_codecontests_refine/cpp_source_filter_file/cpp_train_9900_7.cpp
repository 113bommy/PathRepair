#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long ans;
  if (k > n) {
    long long p = k - n;
    if (p >= n) {
      ans = 0;
    } else {
      ans = (n - p + 1) / 2;
    }
  } else if (n == k) {
    ans = n - 1 / 2;
  } else if (k < n) {
    ans = k / 2;
  }
  cout << ans << endl;
  return 0;
}
