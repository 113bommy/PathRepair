#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x;
  long long ans;
  cin >> n >> k;
  if (n - 2 * k > 1) {
    x = n - 2 * k;
    ans = n * (n - 1) / 2 - x * (x - 1) / 2;
  } else {
    ans = n * (n - 1) / 2;
  }
  cout << ans;
  return 0;
}
