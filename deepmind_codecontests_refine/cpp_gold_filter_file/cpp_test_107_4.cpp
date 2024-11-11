#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
const long long MM = 998244353;
const long long INF = 9e18;
long long expm(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res % M * a % M) % M;
    a = (a % M * a % M) % M;
    b >>= 1;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
  auto start = chrono::high_resolution_clock::now();
  long long tt = 1;
  cin >> tt;
  for (long long test = 1; test <= tt; test++) {
    long long n, a, b;
    cin >> n >> a >> b;
    long long x = abs(a - b);
    if (x > 1 || max(a, b) > n / 2 || (a + b) >= n - 1) {
      cout << -1 << "\n";
      continue;
    }
    if (a == b) {
      long long p = 1, q = n;
      for (long long i = 1; i <= a; i++) {
        cout << p << " " << q << " ";
        p++;
        q--;
      }
      while (p <= q) {
        cout << p << " ";
        p++;
      }
      cout << "\n";
    } else if (a > b) {
      long long p = 1, q = n;
      for (long long i = 1; i <= a; i++) {
        cout << p << " " << q << " ";
        p++;
        q--;
      }
      while (q >= p) {
        cout << q << " ";
        q--;
      }
      cout << "\n";
    } else {
      long long p = 1, q = n;
      for (long long i = 1; i <= b; i++) {
        cout << q << " " << p << " ";
        p++;
        q--;
      }
      while (p <= q) {
        cout << p << " ";
        p++;
      }
      cout << "\n";
    }
  }
  cout << "\n";
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
  cerr << duration.count() / 1000.0 << " ms\n";
  return 0;
}
