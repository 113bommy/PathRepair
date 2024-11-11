#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long mi = 1e9;
    for (long long i = 0; i < n; i++) {
      long long co = 0;
      for (long long j = 0; j < n; j++) {
        if (abs(a[i] - a[j]) % 2 == 0) {
          co++;
        }
      }
      mi = min(mi, co);
    }
    cout << mi << "\n";
  }
  return 0;
}
