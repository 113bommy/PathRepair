#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e9 + 7;
const long long int inf2 = inf * inf;
priority_queue<long long int, vector<long long int>, greater<long long int>>
    mnheap;
long long int gcd(long long int x, long long int y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
int is_prime(long long int x) {
  if (x < 2) return 0;
  for (long long int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}
inline long long int modpw(long long int x, long long int y, long long int z) {
  long long int res = 1;
  x = x % z;
  while (y) {
    if (y & 1) res = (res * x) % z;
    x = (x * x) % z;
    y /= 2;
  }
  return res;
}
inline long long int modinv(long long int x, long long int z) {
  return modpw(x, z - 2, z);
}
long long int lcm(long long int x, long long int y) {
  return (x * y) / gcd(x, y);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    int n;
    cin >> n;
    long long int x;
    vector<long long int> vv;
    for (int i = 0; i < n; i++) {
      cin >> x;
      vv.push_back(x);
    }
    if (n == 1) {
      cout << 1 << " " << 1 << endl;
      cout << -vv[0] << endl;
      cout << 1 << " " << 1 << endl;
      cout << 0 << endl;
      cout << 1 << " " << 1 << endl;
      cout << 0 << endl;
      return 0;
    }
    cout << 1 << " " << n - 1 << endl;
    for (int i = 0; i < n - 1; i++) {
      cout << vv[i] * (n - 1) << " ";
    }
    cout << endl;
    cout << n << " " << n << endl;
    cout << vv[n - 1] * (n - 1) << endl;
    cout << 1 << " " << n << endl;
    for (int i = 0; i < n; i++) {
      cout << -1 * vv[i] * n << " ";
    }
  }
}
