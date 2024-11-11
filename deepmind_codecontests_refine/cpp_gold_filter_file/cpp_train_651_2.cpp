#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cout << 4 * n - 2 * i << " ";
    }
    cout << '\n';
  }
  return 0;
}
