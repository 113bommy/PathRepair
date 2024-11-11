#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 1000000007;
double eps = 1e-12;
long long getSum(string str) {
  long long sum = 0;
  for (int i = 0; i < str.length(); i++) {
    sum = sum + str[i] - 48;
  }
  return sum;
}
double round_up(double value, int decimal_places) {
  const double multiplier = std::pow(10.0, decimal_places);
  return std::ceil(value * multiplier) / multiplier;
}
bool isSquare(long long n) {
  long long res = sqrt(n);
  return res * res == n;
}
void solve() {
  long long n, s;
  cin >> n >> s;
  if (n == 1) {
    cout << 0 << "\n";
  } else if (n == 2)
    cout << s << "\n";
  else
    cout << n + s << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
