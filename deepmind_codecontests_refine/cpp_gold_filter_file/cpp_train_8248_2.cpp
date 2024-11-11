#include <bits/stdc++.h>
using namespace std;
long long h[1025];
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    memset(h, 0, sizeof(h));
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      h[a[i]] = 1;
    }
    long long f = 0;
    set<long long> s;
    for (long long i = 1; i < 1024; i++) {
      f = 0;
      for (long long j = 0; j < n; j++) {
        long long num = a[j] ^ i;
        if (!h[num]) {
          break;
        }
        s.insert(num);
      }
      if (s.size() == n) {
        cout << i << "\n";
        f = 1;
        break;
      }
      s.clear();
    }
    if (!f) {
      cout << -1 << "\n";
    }
  }
}
