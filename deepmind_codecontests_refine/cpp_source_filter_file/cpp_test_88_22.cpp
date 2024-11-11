#include <bits/stdc++.h>
const double PI = 3.14159265358979323846;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    if (n % 2 == 0) {
      cout << "YES" << endl;
    } else {
      long long ch = a[0], f = 0, idx1 = -1, idx2 = -1;
      for (long long i = 0; i + 1 < n; i++) {
        if (a[i] > a[i + 1]) {
          f = 1;
          break;
        }
      }
      if (f == 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
