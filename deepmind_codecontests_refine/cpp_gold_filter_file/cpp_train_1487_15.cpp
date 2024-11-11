#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long ar[n + 1];
    long long b[n + 1];
    ar[0] = 1000000000;
    b[0] = 1000000000;
    for (long long i = 1; i <= n; i++) {
      cin >> ar[i];
      b[i] = -1;
    }
    map<long long, long long> m;
    map<long long, long long> mx1;
    for (long long i = 1; i <= n; i++) {
      if (m[ar[i]] != 0) {
        long long d = abs(i - m[ar[i]]);
        mx1[ar[i]] = max(d, mx1[ar[i]]);
      } else {
        mx1[ar[i]] = i;
      }
      m[ar[i]] = i;
    }
    for (long long i = 1; i <= n; i++) {
      long long d = abs(n + 1 - m[ar[i]]);
      mx1[ar[i]] = max(d, mx1[ar[i]]);
    }
    long long p = n + 1;
    sort(ar, ar + p);
    for (long long i = 0; i < n; i++) {
      long long x = mx1[ar[i]];
      if (b[x] == -1) {
        b[x] = ar[i];
      }
    }
    for (long long i = 2; i <= n; i++) {
      if (b[i - 1] < b[i] && b[i - 1] != -1) {
        b[i] = b[i - 1];
      } else if (b[i] == -1 && b[i - 1] != -1) {
        b[i] = b[i - 1];
      }
    }
    for (long long i = 1; i <= n; i++) {
      cout << b[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
