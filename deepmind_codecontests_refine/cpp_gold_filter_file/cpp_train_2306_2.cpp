#include <bits/stdc++.h>
const double pi = 4.0 * atan(1.0);
const double e = exp(1.0);
const int maxn = 2e6 + 8;
const long long mod = 998244353;
using namespace std;
int a[15];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int x = a[3];
  sort(a + 1, a + 1 + n);
  cout << 2 + (a[1] ^ x) << endl;
}
