#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int k, n, a, b;
    cin >> k >> n >> a >> b;
    k--;
    k -= n * b;
    if (k < 0)
      cout << -1 << "\n";
    else
      cout << min(n, k / (a - b)) << "\n";
  }
  return 0;
}
