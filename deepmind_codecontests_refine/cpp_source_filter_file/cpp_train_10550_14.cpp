#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int mx = 1e5 + 10;
long long int binpow(long long int base, long long int exp) {
  long long int res = 1;
  while (1) {
    if (exp & 1) res *= base;
    exp >>= 1;
    if (!exp) break;
    base *= base;
  }
  return res;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int n;
  cin >> n;
  vector<long long int> v;
  string ans = "NO\n";
  for (long long int i = 0; ((i * (i + 1)) / 2) <= n; ++i) {
    long long int k = (i * (i + 1)) / 2;
    v.push_back(k);
  }
  for (long long int i = 1; ((i * (i + 1)) / 2) <= n; ++i) {
    long long int k = (i * (i + 1)) / 2;
    long long int baki = n - k;
    if (binary_search(v.begin(), v.end(), baki)) {
      ans = "YES\n";
      break;
    }
  }
  cout << ans;
  return 0;
}
