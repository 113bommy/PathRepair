#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int inf = 1e9 + 10;
const ll llinf = 1e18 + 10;
const int mod = 1e9 + 7;
ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
}
