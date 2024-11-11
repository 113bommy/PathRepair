#include <bits/stdc++.h>
using namespace std;
template <class T>
long long size(const T &x) {
  return x.size();
}
const long long INF = ~(1 << 31);
const double pi = acos(-1);
const double EPS = 1e-9;
int main() {
  cin.sync_with_stdio(false);
  long long n;
  cin >> n;
  vector<long long> A(n), B(n);
  for (long long i = (0); i < (n); i++) cin >> A[i];
  for (long long i = (0); i < (n); i++) cin >> B[i];
  long long mx = 0;
  for (long long i = (0); i < (n); i++) {
    for (long long j = (i); j < (n); j++) {
      long long a = 0, b = 0;
      for (long long k = (i); k < (j + 1); k++) a ^= A[k], b ^= B[k];
      mx = max(mx, a + b);
    }
  }
  cout << mx << endl;
  return 0;
}
