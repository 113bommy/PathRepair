#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9;
long long n, k;
vector<bool> v(n + 1);
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  if (k == 1) {
    for (long long i = 1; i <= n; i++) cout << i << " ";
    return 0;
  }
  map<long long, bool> m;
  long long t = 1;
  cout << n << " ";
  m[n] = true;
  while (k) {
    if (t % 2) {
      cout << n - k << " ";
      m[n - k] = true;
      n -= k;
    } else {
      cout << n + k << " ";
      m[n + k] = true;
      n += k;
    }
    t++;
    k--;
  }
  for (long long i = n; i >= 1; i--) {
    if (!m[i]) cout << i << " ";
  }
  return 0;
}
