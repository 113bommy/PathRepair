#include <bits/stdc++.h>
using namespace std;
long long prime(long long p) {
  if (p <= 1) {
    return 0;
  }
  for (long long i = 2; i < sqrt(p); ++i) {
    if (p % i == 0) {
      return 0;
    }
  }
  return 1;
}
void algo() {
  long long n = 0;
  cin >> n;
  vector<long long> v(n, 0);
  long long sum = 0;
  long long odd = -1;
  for (long long i = 0; i < n; ++i) {
    cin >> v[i];
    sum += v[i];
    if (v[i] % 2 != 0) {
      odd = i;
    }
  }
  if (!prime(sum)) {
    cout << n << endl;
    for (long long j = 0; j < n; ++j) {
      cout << j + 1 << " ";
    }
  } else {
    cout << n - 1 << endl;
    for (long long j = 0; j < n; ++j) {
      if (j != odd) {
        cout << j + 1 << " ";
      }
    }
  }
  cout << endl;
}
signed main() {
  long long t = 0;
  cin >> t;
  while (t--) {
    algo();
  }
  return 0;
}
