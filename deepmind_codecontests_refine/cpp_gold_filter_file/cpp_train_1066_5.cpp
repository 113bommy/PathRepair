#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n, k, m;
    cin >> n >> k >> m;
    long long int L = k, R = k;
    while (m--) {
      long long int l, r;
      cin >> l >> r;
      if (l <= L && L <= r) {
        L = l;
      }
      if (l <= R && R <= r) {
        R = r;
      }
    }
    cout << R - L + 1 << "\n";
  }
}
