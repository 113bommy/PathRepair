#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  if (n * (n - 1) / 2 < k) {
    cout << "no solution\n";
  } else {
    for (int i = 0; i < n; i++) {
      cout << 0 << ' ' << i << '\n';
    }
  }
  return 0;
}
