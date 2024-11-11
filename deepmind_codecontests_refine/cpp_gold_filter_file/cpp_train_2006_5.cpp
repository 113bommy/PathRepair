#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n <= k) {
      cout << k - n << "\n";
    } else if (n % 2 == k % 2) {
      cout << "0\n";
    } else {
      cout << "1\n";
    }
  }
  return 0;
}
