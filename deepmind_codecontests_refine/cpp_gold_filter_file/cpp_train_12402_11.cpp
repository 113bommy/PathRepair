#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long MOD = 1e9 + 7;
struct Gauss {
  static const long long bits = 32;
  long long table[bits];
  Gauss() {
    for (long long i = 0; i < bits; i++) table[i] = 0;
  }
  long long size() {
    long long ans = 0;
    for (long long i = 0; i < bits; i++) {
      if (table[i]) ans++;
    }
    return ans;
  }
  bool can(long long x) {
    for (long long i = bits - 1; i >= 0; i--) x = min(x, x ^ table[i]);
    return x == 0;
  }
  void add(long long x) {
    for (long long i = bits - 1; i >= 0 && x; i--) {
      if (table[i] == 0) {
        table[i] = x;
        x = 0;
      } else
        x = min(x, x ^ table[i]);
    }
  }
  long long getBest() {
    long long x = 0;
    for (long long i = bits - 1; i >= 0; i--) x = max(x, x ^ table[i]);
    return x;
  }
};
long long n, q, xorval = 0;
Gauss cur;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    xorval ^= x;
    cur.add(xorval);
  }
  if (xorval == 0)
    cout << "-1";
  else
    cout << cur.size();
}
