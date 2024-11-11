#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10, inf = 1e9 + 10, P = 53, MOD = 1e9 + 7;
vector<int> a, b;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, x, t = 0;
  long long ans = 1;
  cin >> n >> x;
  for (int i = 0; i < 42; i++)
    if ((1ll << i) & x) {
      ans *= 2;
      n -= (1ll << i);
      t++;
    }
  if (n < 0 || (n == 0 && t == 1)) {
    cout << 0;
    return 0;
  }
  if (n == 0) {
    cout << ans - 2;
    return 0;
  }
  for (int i = 0; i < 42; i++)
    if (!((1ll << i) & x))
      if ((1ll << (i + 1)) & n) n -= (1ll << (i + 1));
  if (n == 0)
    cout << ans;
  else
    cout << 0;
  return 0;
}
