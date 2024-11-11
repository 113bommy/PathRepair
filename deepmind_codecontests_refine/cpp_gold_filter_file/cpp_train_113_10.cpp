#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-ffloat-store")
#pragma GCC optimize("-fno-defer-pop")
long int power(long int a, long int b, long int m) {
  if (b == 0) return 1;
  if (b == 1) return a % m;
  long int t = power(a, b / 2, m) % m;
  t = (t * t) % m;
  if (b & 1) t = ((t % m) * (a % m)) % m;
  return t;
}
long int modInverse(long int a, long int m) { return power(a, m - 2, m); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long int i, j, k, l, n;
  long int a = 0, b = 0;
  cout << "? " << a << " " << b << "\n";
  cout.flush();
  ;
  cin >> k;
  for (i = 29; i >= 0; i--) {
    long int f, s;
    cout << "? " << (a ^ (1ll << i)) << " " << b << "\n";
    cout.flush();
    ;
    cin >> f;
    cout << "? " << a << " " << (b ^ (1ll << i)) << "\n";
    cout.flush();
    ;
    cin >> s;
    if (f == s) {
      if (k == 1)
        a = (a ^ (1ll << i));
      else
        b = (b ^ (1ll << i));
      k = f;
    } else {
      if (f == -1) {
        a = (a ^ (1ll << i));
        b = (b ^ (1ll << i));
      }
    }
  }
  cout << "! " << a << " " << b << "\n";
  return 0;
}
