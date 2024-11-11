#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
using namespace std;
long long power(long long a, long long b) {
  long long res = 1;
  a = a % 998244353;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 998244353;
    }
    a = (a * a) % 998244353;
    b >>= 1;
  }
  return res;
}
long long fermat_inv(long long y) { return power(y, 998244353 - 2); }
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
void solve() {
  long long maxi = 1LL < 32;
  long long n;
  cin >> n;
  stack<long long> st;
  st.push(1LL);
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s == "for") {
      long long x;
      cin >> x;
      st.push(min(maxi, st.top() * x));
    } else if (s == "end") {
      st.pop();
    } else {
      ans += st.top();
    }
  }
  if (ans >= maxi)
    cout << "OVERFLOW!!!";
  else
    cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
