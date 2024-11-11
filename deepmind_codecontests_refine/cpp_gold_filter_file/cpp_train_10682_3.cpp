#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, k, t;
  cin >> n >> k >> t;
  if (t < k) {
    cout << t;
  } else if (t >= k && t <= n) {
    cout << k;
  } else {
    cout << (n + k) - t;
  }
  cout << '\n';
  return 0;
}
