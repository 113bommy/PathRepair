#include <bits/stdc++.h>
using namespace std;
const int maxn = 70 + 10;
const int maxm = 1e6 + 10;
const long long INF = 1e8;
const int mod = 10007;
const double eps = 1e-12;
const int base = 5e6;
long long fac(long long n) {
  long long ans = 1;
  for (int i = (1); i <= (n); i++) ans *= i;
  return ans;
}
long long n;
void init() {
  cin >> n;
  cout << fac(n) / (n * n);
}
void solve() {}
int main() {
  int t = 1;
  while (t--) {
    init();
    solve();
  }
  return 0;
}
