#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (2 * k > n) {
    cout << -1 << '\n';
    return 0;
  }
  cout << n * k << '\n';
  for (int i = 0; i < n; ++i)
    for (int j = 1; j <= k; ++j)
      cout << i + 1 << " " << (i + j) % n + 1 << '\n';
  return 0;
}
