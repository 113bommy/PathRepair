#include <bits/stdc++.h>
using namespace std;
int t, n, x, a, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> x >> a >> b;
    if (a > b) swap(a, b);
    if (a + (n - b) < x)
      cout << (n - 1) << "\n";
    else
      cout << (b - a + x) << "\n";
  }
}
