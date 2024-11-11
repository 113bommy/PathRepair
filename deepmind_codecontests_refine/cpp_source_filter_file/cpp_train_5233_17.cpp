#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    if (m >= 2 * n) {
      cout << n << " " << 2 * n << endl;
    } else {
      cout << "-1"
           << "-1" << endl;
    }
  }
  return 0;
}
