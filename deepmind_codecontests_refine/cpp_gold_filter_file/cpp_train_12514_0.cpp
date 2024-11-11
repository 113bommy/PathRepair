#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 5];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    map<long long, long long> m;
    for (long long i = 0; i < n; i++) {
      for (long long j = 29; j >= 1; j--) {
        if ((a[i] % (1 << j)) == 0) {
          m[a[i] / (1 << j)] = max(m[a[i] / (1 << j)], j);
          break;
        }
      }
    }
    long long ans = 0;
    for (auto it : m) {
      ans += it.second;
    }
    cout << ans << endl;
  }
  return 0;
}
