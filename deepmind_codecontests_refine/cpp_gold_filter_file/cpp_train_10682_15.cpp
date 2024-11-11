#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, k;
  cin >> n >> k >> t;
  if (t <= k) {
    cout << t;
    return 0;
  }
  if (t > k && t <= n) {
    cout << k;
    return 0;
  }
  if (t < n + k && t > n) {
    cout << k - t + n;
    return 0;
  }
  if (t >= n + k) {
    cout << 0;
    return 0;
  }
}
