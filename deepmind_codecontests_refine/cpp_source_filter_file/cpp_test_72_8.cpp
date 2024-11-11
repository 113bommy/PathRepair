#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long N = 1e9;
long long query(long long x, long long y) {
  cout << "? " << x << " " << y << endl;
  long long o;
  cin >> o;
  return o;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long p = query(1, 1);
  long long l = 2, r = N;
  long long ans = 0;
  while (l <= r) {
    long long m = (l + r) / 2;
    if (query(1, m) == p - m + 1) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  long long fx = ans, fy = p - ans + 2;
  long long q = query(1, N);
  long long sx = N - (q - fy + 1), ss = fy;
  long long lp = query(N, N);
  long long tx = sx, ty = 2 * N - (lp + tx);
  cout << "! " << fx << " " << fy << " " << tx << " " << ty << endl;
  return 0;
}
