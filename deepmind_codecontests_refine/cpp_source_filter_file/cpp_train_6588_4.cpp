#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n), b(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (long long i = 0; i < n; i++) {
      cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<long long> mark(n);
    long long f1 = 1;
    for (long long i = 0; i < n; i++) {
      long long val = a[i];
      long long fl = 0;
      for (long long j = n - 1; j >= 0; j--) {
        if (mark[i] == 0 && (a[i] + b[j]) <= x) {
          mark[i] = 1;
          fl = 1;
          break;
        }
      }
      if (!fl) {
        f1 = 0;
        break;
      }
    }
    if (!f1) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
  return 0;
}
