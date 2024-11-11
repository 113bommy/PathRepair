#include <bits/stdc++.h>
using namespace std;
bool sortbyfirstandsec(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) return (a.second > b.second);
  return a.first < b.first;
}
long long fact(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return fact(b, a % b);
}
long long int power(long long int a, long long int b) {
  long long int ret = 1;
  long long int mod = 1e9 + 7;
  while (b) {
    if (b % 2) {
      ret = (ret * a) % mod;
    }
    a = (a * a) % mod;
    b /= 2;
  }
  return ret;
}
long long int foo(long long int a, long long int b) {
  long long int mod = 1e9 + 7;
  return (power(2, a + b) - power(2, b) + mod) % mod;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, i, j, k, r = 0, l, l1 = 0, r1 = 0, r2 = 0, m, z = 0;
  cin >> n;
  set<long long int> s;
  long long int a[n], b[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
    r = r + a[i];
  }
  for (i = 0; i < n; i++) {
    k = r - a[i];
    if (k % 2 == 0) {
      if (k / 2 == a[i]) {
        if (s.count(k / 2) > 1) {
          b[l1] = i + 1;
          l1++;
        }
      }
      if (s.count(k / 2) == 1 && (k / 2) != a[i]) {
        b[l1] = i + 1;
        l1++;
      }
    }
  }
  cout << l1 << endl;
  for (i = 0; i < l1; i++) {
    cout << b[i] << " ";
  }
  return 0;
}
