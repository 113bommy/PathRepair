#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long double PI = acos(-1);
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
const int mod1 = 998244353;
const long long INF = 2e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  {
    int64_t n;
    cin >> n;
    for (int64_t i = 2; i * i <= n; i++) {
      while (n % (i * i) == 0) {
        n /= i;
      }
    }
    cout << n;
  }
  return 0;
}
