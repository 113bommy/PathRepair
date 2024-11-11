#include <bits/stdc++.h>
using namespace std;
long long int mod1 = pow(10, 9) + 7;
int mod2 = 998244353;
long long int power(long long int x, long long int y, long long int pp) {
  long long int res = 1;
  x = x % pp;
  while (y > 0) {
    if (y & 1) res = (res * x) % pp;
    y = y >> 1;
    x = (x * x) % pp;
  }
  return res;
}
long long int modInverse(long long int n, long long int pp) {
  return power(n, pp - 2, pp);
}
long long int fun(long long int n) {
  if (n == 1)
    return 2;
  else
    return n - 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a, b, c;
  long long int x;
  cin >> a >> b >> c;
  map<long long int, long long int> m;
  m[1] = a;
  m[2] = b;
  m[3] = c;
  long long int r = max(a, max(b, c));
  long long int p = min(a, min(b, c));
  long long int q = (a + b + c) - (r + p);
  cout << "First" << endl;
  cout << 2 * r - p - q << endl;
  cin >> x;
  if (m[x] == p) {
    cout << r - q << endl;
    cin >> x;
    return 0;
  } else if (m[x] == q) {
    cout << r - p << endl;
    cin >> x;
    return 0;
  } else {
    r += 2 * r - p - q;
    cout << 2 * r - p - q << endl;
    cin >> x;
    if (m[x] == p) {
      cout << r - q << endl;
      cin >> x;
      return 0;
    } else {
      cout << r - p << endl;
      cin >> x;
      return 0;
    }
  }
}
