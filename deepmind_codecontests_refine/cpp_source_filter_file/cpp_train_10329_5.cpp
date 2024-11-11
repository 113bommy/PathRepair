#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long mx = 3e5 + 10;
int posx[] = {1, -1, 0, 0};
int posy[] = {0, 0, 1, -1};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1, n, k, m, a, b, c, d;
  while (t--) {
    cin >> n >> m;
    int ans = 0, fact[n + 1];
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (1ll * i * fact[i - 1]) % m;
    for (int i = 1; i <= n; i++) {
      int x = ((n - i + 1) * (n - i + 1)) % m;
      int y = (1ll * fact[i] * fact[n - i]) % m;
      ans = (ans + 1ll * x * y) % m;
    }
    cout << ans << endl;
  }
  return 0;
}
