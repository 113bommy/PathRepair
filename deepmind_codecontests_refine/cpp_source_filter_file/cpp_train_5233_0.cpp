#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    if (k - n < 2)
      cout << -1 << " " << -1 << endl;
    else
      cout << n << " " << 2 * n << endl;
  }
  return 0;
}
