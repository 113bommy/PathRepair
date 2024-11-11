#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  unordered_map<long long, long long> opt;
  long long n, m, ans = 0;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    opt[a] += c;
    opt[b] -= c;
  }
  if (!opt.size()) {
    cout << 0 << '\n';
    return 0;
  }
  for (auto& x : opt)
    if (x.second > 0) ans += x.second;
  cout << ans << '\n';
  return 0;
}
