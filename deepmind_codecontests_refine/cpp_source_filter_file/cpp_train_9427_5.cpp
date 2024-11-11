#include <bits/stdc++.h>
using namespace std;
string s;
signed main() {
  long long n, k, a[110], x, y;
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    a[i] = s.length();
  }
  cin >> s;
  sort(a, a + n);
  x = lower_bound(a, a + n, s.length()) - a;
  y = upper_bound(a, a + n, s.length()) - a;
  cout << x + x / k * 5 + 1 << ' ' << y + y / k * 5;
}
