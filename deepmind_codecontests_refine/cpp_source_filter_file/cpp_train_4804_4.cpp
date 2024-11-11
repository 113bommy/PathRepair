#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int k;
  cin >> k;
  for (int i = 1; i < 2000; i++) {
    int n = i + 1;
    long long int total = n + k;
    long long int x = (total + n - 1) / n;
    if (x <= 1000000L && x >= 0) {
      cout << n << endl;
      cout << "-1 ";
      for (int j = 2; j < n; j++) {
        cout << x << " ";
        total -= x;
      }
      cout << total << endl;
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}
