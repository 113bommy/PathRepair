#include <bits/stdc++.h>
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int& n, int b) { n |= two(b); }
inline void unset_bit(int& n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) {
  int res = 0;
  while (n && ++res) n -= n & (-n);
  return res;
}
long long int gcd(long long int a, long long int b) {
  return (a ? gcd(b % a, a) : b);
}
long long int modPow(long long int a, long long int b, long long int MOD) {
  long long int x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % MOD;
    }
    b /= 2;
    y = (y * y) % MOD;
  }
  return x;
}
long long int modInverse(long long int a, long long int p) {
  return modPow(a, p - 2, p);
}
using namespace std;
string str;
vector<int> v;
map<int, int> mymap;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, i, j, k, diff;
  cin >> n;
  cin >> str;
  for (diff = 1; diff <= n; diff++) {
    for (j = 0; j < n; j++) {
      long long int ctr = 0;
      for (k = j; k < n; k += diff) {
        if (str[k] == '.')
          break;
        else {
          ctr++;
          if (ctr == 5) {
            cout << "yes";
            return 0;
          }
        }
      }
    }
  }
  cout << "no";
  return 0;
}
