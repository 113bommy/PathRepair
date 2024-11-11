#include <bits/stdc++.h>
using namespace std;
long long M[25];
int main() {
  long long n, x, s = 0, k = 0, c = 0;
  cin >> n >> x;
  long long xx = x;
  if (n == 2 and x == 0) {
    cout << "NO";
    return 0;
  } else if (n == 2) {
    cout << "YES\n";
    cout << "0 " << x;
    return 0;
  }
  cout << "YES\n";
  if (n == 1) {
    cout << x;
    return 0;
  }
  long long r = 0, ok = 1;
  for (long long i = 0; i < n - 3; i++) {
    x = (x ^ i + 1);
    r = (r ^ (i + 1));
    cout << i + 1 << " ";
  }
  long long m = 137005;
  if (m == (x ^ m)) {
    x = (x ^ n - 2);
    r = (r ^ (n - 2));
    ok = 0;
    cout << n - 2 << " ";
  }
  cout << m << " ";
  r = r ^ m;
  cout << (x ^ m) << " ";
  r = r ^ (x ^ m);
  if (ok) cout << "0 ";
}
