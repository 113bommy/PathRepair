#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, d;
    cin >> n >> d;
    if (d <= n) {
      cout << "YES\n";
      continue;
    }
    bool l = false;
    for (long long int i = 1; i < sqrt(n); i++) {
      long long int k = ceil((double)d / (i + 1));
      if ((i + k) <= n) {
        cout << "YES\n";
        l = true;
        break;
      }
    }
    if (!l) cout << "NO\n";
  }
  return 0;
}
