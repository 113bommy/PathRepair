#include <bits/stdc++.h>
using namespace std;
struct _ {
  ios_base::Init i;
  _() {
    cin.sync_with_stdio(0);
    cin.tie(0);
  }
} _;
int main() {
  int n, k;
  cin >> n >> k;
  if (k >= n) {
    cout << "-1\n";
    return 0;
  }
  cout << n * k << '\n';
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= k; ++j) {
      int nxt = (i + j) % n;
      if (nxt == 0) nxt = n;
      cout << i << ' ' << nxt << '\n';
    }
  return 0;
}
