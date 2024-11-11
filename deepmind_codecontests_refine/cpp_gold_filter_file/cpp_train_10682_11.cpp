#include <bits/stdc++.h>
using namespace std;
long long n = 0, k = 0, t = 0;
int main() {
  cin >> n >> k >> t;
  if (t <= n && t >= k) {
    cout << k;
  }
  if (t < k) {
    cout << t;
  }
  if (t > n) {
    cout << n + k - t;
  }
  return 0;
}
