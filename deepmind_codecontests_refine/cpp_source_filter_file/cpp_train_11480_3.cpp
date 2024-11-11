#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long v = 1;
  while (y > 0) {
    if (y & 1) v = v * x;
    y = y >> 1;
    x = x * x;
  }
  return v;
}
bool isPowerOfTwo(long long x) { return x && (!(x & (x - 1))); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
      ans += max(v[i - 1] - v[i], 0);
    }
    cout << ans << "\n";
  }
  return 0;
}
