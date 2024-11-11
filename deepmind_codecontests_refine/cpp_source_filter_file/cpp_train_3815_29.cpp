#include <bits/stdc++.h>
using namespace std;
long long p[100010], ans;
const int mod = 1e9 + 9;
long long n, m;
void sredi(long long& a) {
  a %= mod;
  if (a < 0) a += mod;
}
long long findp(long long x) {
  if (x == p[x]) return p[x];
  p[x] = findp(p[x]);
  return p[x];
}
bool spoji(long long x, long long y) {
  x = findp(x);
  y = findp(y);
  if (x == y) return 0;
  p[min(x, y)] = max(x, y);
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) p[i] = i;
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    if (!spoji(u, v)) {
      ans *= 2;
      sredi(ans);
      ans++;
      sredi(ans);
    }
    cout << ans;
  }
  return 0;
}
