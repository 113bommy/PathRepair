#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int N = 200100;
long long m;
long long nr(long long x) {
  long long nr = 0;
  for (int i = 2; i <= 100001; ++i) {
    nr += x / (1LL * i * i * i);
    if (1LL * i * i * i > x) {
      break;
    }
    if (nr > m) {
      return nr;
    }
  }
  return nr;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> m;
  long long st = 1;
  long long dr = m * 8;
  long long sol = -1;
  while (st <= dr) {
    long long mij = (st + dr) >> 1;
    if (nr(mij) > m) {
      dr = mij - 1;
    } else if (nr(mij) < m) {
      st = mij + 1;
    } else if (nr(mij) == m) {
      sol = mij;
      dr = mij - 1;
    }
  }
  cout << sol;
  return 0;
}
