#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t;
  cin >> n >> k >> t;
  t *= n * k / 100;
  for (int i = 1; i < n + 1; i++) {
    if (i <= t / k) {
      cout << k << " ";
    } else if (i == t / k + 1) {
      cout << t % k << " ";
    } else {
      cout << 0 << " ";
    }
  }
  return 0;
}
