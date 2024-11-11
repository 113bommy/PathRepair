#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long k = n / 2;
    if (k % 2 == 0) {
      vector<long long> v(n, 0);
      for (long long i = 0; i < k; i++) {
        v[i] = 2 * (i + 1);
        v[n - i - 1] = 2 * i + 1;
      }
      v[k] += k;
      cout << "YES\n";
      for (long long i = 0; i < n; i++) {
        cout << v[i] << " ";
      }
      cout << "\n";
    } else {
      cout << "NO\n";
    }
  }
}
