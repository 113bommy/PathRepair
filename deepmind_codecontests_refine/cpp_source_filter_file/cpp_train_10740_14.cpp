#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) { return a + b - max(a, b); }
long long mulmod(long long a, long long b, long long mod) {
  return ((a % 1000000007) * (b % 1000000007) % 1000000007);
}
long long mod(long long a, long long b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void next(long long x1, long long y1, long long ctr) {
  cout << x1 << " " << y1 + 1 << "\n";
  if (ctr >= 1) cout << x1 + 1 << " " << y1 << "\n";
  if (ctr >= 2) cout << x1 - 1 << " " << y1 << "\n";
}
void solve(long long x, long long y) {
  if (max(x, y) - 1 > 3 * (min(x, y))) {
    cout << "NO\n";
    return;
  } else {
    cout << "YES\n";
    if (x == y) {
      long long x1 = 1000000;
      long long y1 = x1;
      for (long long i = 0; i < 2 * x; i++) {
        cout << x1 << " " << y1 + i << "\n";
      }
      return;
    } else if (x > y) {
      vector<long long> vec(y);
      for (long long i = 0; i < y; i++) vec[i] = 2;
      long long diff = 2 * y + 1;
      long long req = x - y;
      long long x1 = 1000000;
      long long y1 = x1 + 1;
      if (diff == req) {
        cout << x1 << " " << y1 - 1 << "\n";
      }
      diff--;
      for (long long i = 0; i < y; i++) {
        if (diff == req) break;
        if (diff - req >= 2) {
          vec[i] -= 2;
          diff -= 2;
        } else if (diff - req >= 1) {
          vec[i] -= 1;
          diff--;
        }
      }
      for (long long i = 0; i < y; i++) {
        cout << x1 << " " << y1 << "\n";
        next(x1, y1, vec[i]);
        y1 += 2;
      }
    } else {
      vector<long long> vec(x);
      for (long long i = 0; i < x; i++) vec[i] = 2;
      long long diff = 2 * x + 1;
      long long req = y - x;
      long long x1 = 1000000;
      long long y1 = x1;
      if (diff == req) {
        cout << x1 << " " << y1 - 1 << "\n";
      }
      diff--;
      for (long long i = 0; i < x; i++) {
        if (diff == req) break;
        if (diff - req >= 2) {
          vec[i] -= 2;
          diff -= 2;
        } else if (diff - req >= 1) {
          vec[i] -= 1;
          diff--;
        }
      }
      for (long long i = 0; i < x; i++) {
        cout << x1 << " " << y1 << "\n";
        next(x1, y1, vec[i]);
        y1 += 2;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long q;
  cin >> q;
  while (q--) {
    long long x, y;
    cin >> x >> y;
    solve(x, y);
  }
}
