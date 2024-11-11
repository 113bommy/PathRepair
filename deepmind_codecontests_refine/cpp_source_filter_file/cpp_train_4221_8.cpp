#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long INF64 = 1e18;
const long double PI = acos(-1.0);
const long double EPS = 1e-8;
const int MOD = 1000000007;
const int N = 37;
int main() {
  int n;
  cin >> n;
  int ans = 0;
  while (n) {
    if (n % 10 == 1) ans++;
    n /= 10;
  }
  cout << ans;
  return 0;
}
