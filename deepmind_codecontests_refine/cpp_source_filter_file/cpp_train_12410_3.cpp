#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k1, k2;
    cin >> n >> k1 >> k2;
    long long int maxi1 = INT_MIN, maxi2 = INT_MIN;
    long long int j;
    for (long long int i = 0; i < k1; i++) {
      cin >> j;
      maxi1 = max(maxi1, j);
    }
    for (long long int i = 0; i < k1; i++) {
      cin >> j;
      maxi2 = max(maxi2, j);
    }
    if (maxi1 > maxi2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
