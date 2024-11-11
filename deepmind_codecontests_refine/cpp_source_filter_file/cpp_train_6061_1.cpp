#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 144, mod = 1e9 + 7, inf = 1e9 + 7;
long long bp(long long x, long long y) {
  x %= mod;
  if (y == 0) return 1;
  if (y & 1) return (x * bp(x, y - 1)) % mod;
  long long z = bp(x, y / 2);
  return (z * z) % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    string st;
    int n;
    cin >> n;
    int k = n / 2;
    for (int i = 1; i <= k; i++) st += '1';
    if (n % 2) {
      st[k - 1] = '7';
    }
    cout << st << "\n";
  }
  return 0;
}
