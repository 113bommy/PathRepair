#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
const long double eps = 0.0000000001;
const long long INF = 0x3fffffffffffffff;
long long n, a[55], ans;
signed main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (long long i = 1; i <= n; ++i) {
    if (a[i] != a[1]) {
      ++ans;
    }
  }
  cout << (ans < n / 2 ? "Bob" : "Alice") << endl;
  return 0;
}
