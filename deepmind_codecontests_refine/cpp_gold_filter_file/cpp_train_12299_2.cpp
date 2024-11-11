#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
using ll = long long;
int n;
ll c, d, t[N];
char p[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> c >> d;
  for (int i = 1; i <= n; i++) cin >> t[i] >> p[i];
  cin >> t[n + 1];
  ll ans = d * n, s = 0, lst = -1;
  for (int i = n; i > 0; --i) {
    if (p[i] == p[i + 1])
      s += min(d, (lst - t[i + 1]) * c);
    else
      lst = t[i + 1];
    ans = min(ans, (i - 1) * d + s + (t[n + 1] - t[i]) * c);
  }
  cout << ans << endl;
  return 0;
}
