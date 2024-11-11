#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long n, k, t;
  cin >> n >> k >> t;
  if (t <= k) {
    cout << k;
    return 0;
  } else if (t >= n) {
    cout << (k - (t - n));
    return 0;
  } else {
    cout << k;
  }
  return 0;
}
