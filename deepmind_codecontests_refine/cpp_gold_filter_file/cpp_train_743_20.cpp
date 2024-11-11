#include <bits/stdc++.h>
using namespace std;
long long po(long long n, long long exp) {
  long long prod = 1;
  for (long long i = 0; i < exp; i++) prod *= n;
  return prod;
}
long long mnx = INT_MAX, mny = INT_MAX, mxx = INT_MIN, mxy = INT_MIN;
bool bound(long long x, long long y) {
  if (x == mnx && y >= mny && y <= mxy) return 1;
  if (x == mxx && y >= mny && y <= mxy) return 1;
  if (y == mny && x >= mnx && x <= mxx) return 1;
  if (y == mxy && x >= mnx && x <= mxx) return 1;
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  long long TESTS = 1;
  while (TESTS--) {
    long long n, k, m, t;
    cin >> n >> k >> m >> t;
    long long curl = n;
    long long curk = k;
    for (long long i = 0; i < t; i++) {
      long long type;
      cin >> type;
      if (type == 0) {
        long long l;
        cin >> l;
        if (l < curk) {
          curk -= l;
          curl -= l;
        } else {
          curl = l;
        }
      } else {
        long long l;
        cin >> l;
        curl++;
        if (curk >= l) curk++;
      }
      cout << curl << " " << curk << '\n';
    }
  }
}
