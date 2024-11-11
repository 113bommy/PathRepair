#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e12;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long l = 1;
    long long r = 1e9;
    while (r - l > 1) {
      long long m = (l + r) / 2;
      vector<long long> b(a);
      vector<long long> add(n);
      for (long long i = n - 1; i >= 2; i--) {
        long long d1 = b[i] / 3;
        long long d2 = (b[i] + add[i] - m) / 3;
        long long d = max(0ll, min(d1, d2));
        b[i] -= 3 * d;
        add[i - 1] += d;
        add[i - 2] += 2 * d;
      }
      bool fl = true;
      for (long long i = 0; i < n; i++) {
        if (b[i] + add[i] < m) {
          fl = false;
        }
      }
      if (fl) {
        l = m;
      } else {
        r = m;
      }
    }
    cout << l << "\n";
  }
}
