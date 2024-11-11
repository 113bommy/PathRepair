#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a, s = 0;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    s += a;
  }
  cout << max(2 * (n * k - s) - n, 0);
  return 0;
}
