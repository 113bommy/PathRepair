#include <bits/stdc++.h>
const int mod = 1000000007;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int c, v0, v1, a, l;
  int ans = 1;
  cin >> c >> v0 >> v1 >> a >> l;
  c = c - v0;
  v0 = v0 + a;
  while (c > 0 && v0 <= v1) {
    ans++;
    c = c - v0 + l;
    v0 = v0 + a;
  }
  v1 = v1 - l;
  while (c > 0) {
    ans++;
    c = c - v1;
  }
  cout << ans << '\n';
  return 0;
}
