#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long max = -1e9 - 1, max1 = -1e9 - 1;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > max) {
        max = a[i];
      }
    }
    vector<long long> v(n);
    vector<long long> v1(n);
    for (long long i = 0; i < n; i++) {
      v[i] = max - a[i];
      if (v[i] > max1) {
        max1 = v[i];
      }
    }
    for (long long i = 0; i < n; i++) {
      v1[i] = max1 - v[i];
    }
    if (k % 2 == 0) {
      v = v1;
    }
    for (long long i = 0; i < n; i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  }
}
