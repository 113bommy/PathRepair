#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, t;
  cin >> n >> k >> t;
  if (t >= n + k) {
    cout << 0;
    return 0;
  }
  if (t <= k) {
    cout << k;
    return 0;
  }
  if (t >= n) {
    cout << k - (n - t);
    return 0;
  }
  cout << k;
  return 0;
}
