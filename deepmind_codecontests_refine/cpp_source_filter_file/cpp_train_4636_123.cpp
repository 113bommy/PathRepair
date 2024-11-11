#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;
const long double eps = 1e-9;
inline void add(long long &a, long long b) {
  a += b;
  a %= mod;
}
inline void sub(long long &a, long long b) { a = (a - b + mod) % mod; }
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n;
  cin >> n;
  if (n % 2 == 1)
    cout << 1;
  else
    cout << 2;
  return 0;
}
