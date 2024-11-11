#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 1e6 + 5;
long long n, pw[N];
int t = 3;
void Solve() {
  pw[n + 1] = 1;
  for (long long i = n; i >= 3; i--) pw[i] = (pw[i + 1] * i) % mod;
  long long res = 0;
  res = (pw[3] * (n - 1)) % mod;
  for (long long i = n - 2; i >= 1; i--) {
    res = res + (pw[t + 1] * (t - 1) * i) % mod;
    t++;
  }
  cout << (res + 1) % mod << '\n';
}
int main() {
  cin >> n;
  Solve();
  return 0;
}
