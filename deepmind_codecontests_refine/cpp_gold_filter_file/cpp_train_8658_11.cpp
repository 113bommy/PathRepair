#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, l, r;
  cin >> n >> l >> r;
  long long ans = (1 << l) - 1;
  ans += (n - l);
  cout << ans << " ";
  r = min(r, n);
  long long ans2 = (1 << r) - 1;
  ans2 += (n - r) * (1 << (r - 1));
  cout << ans2 << endl;
}
