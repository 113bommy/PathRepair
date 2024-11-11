#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
const long long LLINF = numeric_limits<long long>::max();
const unsigned long long ULLINF = numeric_limits<unsigned long long>::max();
const double PI = acos(-1.0);
long long n, a, b, t;
bool orie[500010];
string s[2];
long long ans = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> a >> b >> t;
  cin >> s[0];
  for (int i = 1; i < n; i++) s[1].push_back(s[0][i]);
  s[1].push_back(s[0][0]);
  reverse((s[1]).begin(), (s[1]).end());
  for (int tt = 0; tt < 2; tt++) {
    for (int i = 0; i < n; i++) orie[i] = (s[tt][i] == 'w');
    vector<long long> cp(n), cs(n);
    cp[1] = 1 + a + orie[1] * b;
    for (int i = 2; i < n; i++) cp[i] = cp[i - 1] + a + 1 + orie[i] * b;
    cs[n - 1] = 1 + orie[0] * b;
    for (int i = n - 2; i >= 0; i--)
      cs[i] = cs[i + 1] + 1 + a + orie[i + 1] * b;
    for (int i = n - 1; i >= 0; i--) {
      long long moved = n - i - 1;
      if (cs[i] <= t) ans = max(ans, moved + 1);
      if (t > cs[i] + moved * a) {
        auto k = upper_bound((cp).begin(), (cp).end(), t - cs[i] - moved * a) -
                 cp.begin() - 1;
        ans = max(ans, min(k + moved + 1, n));
      }
    }
  }
  cout << ans;
  return 0;
}
