#include <bits/stdc++.h>
using namespace std;
const int mxN = 5e4;
int n, chu[mxN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> chu[i];
    if (chu[0] + chu[1] < chu[n - 1])
      cout << 1 << " " << 2 << " " << n << "\n";
    else
      cout << -1 << "\n";
  }
}
