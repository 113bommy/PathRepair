#include <bits/stdc++.h>
using namespace std;
long long t, n, a, b, c, k, sum, nr, q[200005];
string s, z;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    long long sum = 1;
    long long ans = 1;
    long long kek = 1;
    while (sum < n) {
      kek = kek * 2 + 1;
      sum = (kek * (kek + 1)) / 2;
      if (sum < n) ans++;
    }
    cout << ans << endl;
  }
}
