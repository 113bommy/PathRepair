#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long int rvsr(long long int n) {
  string s = to_string(n);
  reverse(s.begin(), s.end());
  stringstream obj(s);
  obj >> n;
  return n;
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long int logtwo(long long int n) {
  if (n == 1) return 0;
  return logtwo(n / 2) + 1;
}
long long int isprime(long long int n) {
  for (long long int c1 = 2; c1 * c1 <= n; c1++) {
    if (n % c1 == 0) {
      return 0;
    }
  }
  return 1;
}
long long int twop(long long int n) {
  long long int x = 0;
  while (n % 2 == 0) {
    n /= 2;
    x++;
  }
  return x;
}
long long int n, t, mina;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int a[n];
    {
      for (long long int ii = 0; ii < n; ii++) cin >> a[ii];
    };
    long long int f = 1;
    for (long long int i = 0; i < n - 1 && f; i++) {
      if (a[i] > a[i + 1]) f = 0;
    }
    if (f == 1) {
      cout << "YES"
           << "\n";
      continue;
    }
    f = 1;
    std::vector<long long int> v;
    mina = *min_element(a, a + n);
    for (long long int i = 0; i < n; i++) {
      if (a[i] % mina == 0) v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    long long int p = 0;
    for (long long int i = 0; i < n; i++) {
      if (a[i] % mina == 0) {
        a[i] = v[p++];
      }
    }
    for (long long int i = 0; i < n - 1 && f; i++) {
      if (a[i] > a[i + 1])
        cout << "NO"
             << "\n",
            f = 0;
    }
    if (f)
      cout << "YES"
           << "\n";
  }
}
