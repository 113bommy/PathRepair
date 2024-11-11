#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
signed main() {
  long long n, l, r;
  cin >> n >> l >> r;
  long long mn = 0, mx = 0;
  for (long long i = 0; i < r; i++) mx += (1 << i);
  for (long long i = r; i < n; i++) mx += (1 << (l - 1));
  for (long long i = 0; i < l; i++) mn += (1 << i);
  for (long long i = l; i < n; i++) mn += 1;
  cout << mn << " " << mx << endl;
  return 0;
}
