#include <bits/stdc++.h>
using namespace std;
const long long int P = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> v(n);
    long long int maxa = -1e18;
    for (long long int i = 0; i < n; ++i) {
      cin >> v[i];
      maxa = max(maxa, v[i]);
    }
    if (k % 2 == 0) {
      long long int n_maxa = -1e18;
      for (long long int i = 0; i < 1; ++i) {
        for (auto &x : v) {
          x = maxa - x;
          n_maxa = max(x, n_maxa);
        }
        for (auto &x : v) {
          x = n_maxa - x;
        }
      }
      for (auto &x : v) cout << x << " ";
      cout << "\n";
    } else {
      for (auto &x : v) {
        x = maxa - x;
      }
      for (auto &x : v) cout << x << " ";
      cout << "\n";
    }
  }
  return 0;
}
