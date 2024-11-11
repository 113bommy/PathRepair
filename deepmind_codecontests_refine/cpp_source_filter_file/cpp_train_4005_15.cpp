#include <bits/stdc++.h>
using namespace std;
long long dig(long long a) {
  long long ans = 0;
  while (a) {
    ans++;
    a >>= 2;
  }
  return ans;
}
void solve() {
  long long a, b;
  cin >> a >> b;
  if (a > b) {
    swap(a, b);
  }
  long long i;
  for (i = 60; i >= 0; i--) {
    if ((a & (1 << i)) != (b & (1 << i))) {
      break;
    }
  }
  long long ans = (a >> (i + 1)) << (i + 1);
  a = a - ans;
  b = b - ans;
  if (b == (1 << (i + 1)) - 1) {
    cout << b + ans << "\n";
  } else {
    cout << (1 << (i)) - 1 + ans << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
