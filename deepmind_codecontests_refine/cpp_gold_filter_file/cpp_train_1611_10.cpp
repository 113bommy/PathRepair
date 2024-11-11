#include <bits/stdc++.h>
using namespace std;
int INT_MAX_VAL = (int)1e20;
int INT_MIN_VAL = (int)-1e20;
long long LONG_MAX_VAL = (long long)1e20;
long long LONG_MIN_VAL = (long long)-1e20;
bool is_pow(long long a, long long b) {
  long long p = a;
  while (p < b) {
    p *= a;
  }
  return p == b;
}
void poly(long long a, long long b, long long t) {
  if (t > a) {
    cout << (a == b) << '\n';
    return;
  }
  int ans = 0;
  if (is_pow(a, b)) ans++;
  long long ap = a, bi = b;
  long long tp = 1;
  long long tr = 0;
  while (bi > 0) {
    long long c = bi % a;
    bi /= a;
    tr += tp * c;
    tp *= t;
  }
  if (tr == a) {
    ans++;
  }
  cout << ans << '\n';
}
int main() {
  long long t, a, b;
  cin >> t >> a >> b;
  if (t == 1) {
    if (a == 1) {
      if (a == b) {
        cout << "inf" << '\n';
      } else {
        cout << 0 << '\n';
      }
    } else {
      poly(a, b, t);
    }
  } else {
    poly(a, b, t);
  }
  return 0;
}
