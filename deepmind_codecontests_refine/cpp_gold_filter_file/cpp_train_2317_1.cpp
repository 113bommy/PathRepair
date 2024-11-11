#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long min(long long a, long long b) { return (a < b) ? a : b; }
long long max(long long a, long long b) { return (a > b) ? a : b; }
long long fp(long long a, long long b) {
  if (b == 0) return 1;
  long long x = fp(a, b / 2);
  x = (x * x) % mod;
  if (b & 1) x = (x * a) % mod;
  return x;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[2 * n + 1];
    vector<long long> e, o;
    for (long long i = 1; i <= 2 * n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0) {
        e.push_back(i);
      } else {
        o.push_back(i);
      }
    }
    if (o.size() % 2) {
      o.pop_back();
      e.pop_back();
    } else {
      if (e.size() > 2) {
        e.pop_back();
        e.pop_back();
      } else {
        o.pop_back();
        o.pop_back();
      }
    }
    for (long long i = 1; i < n; i++) {
      if (e.size() > 0) {
        cout << e.back() << " ";
        e.pop_back();
        cout << e.back() << "\n";
        e.pop_back();
      } else {
        cout << o.back() << " ";
        o.pop_back();
        cout << o.back() << "\n";
        o.pop_back();
      }
    }
  }
}
