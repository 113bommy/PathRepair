#include <bits/stdc++.h>
using namespace std;
long long n;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  if (n < 3) return cout << "-1", 0;
  for (long long i = 0; i < n; ++i) cout << i << " ";
  cout << endl;
  for (long long i = 1; i < n; ++i) cout << i << " ";
  cout << 0 << endl;
  for (long long i = 0; i < n; ++i) cout << (2 * i + 1) % n << " ";
  return 0;
}
