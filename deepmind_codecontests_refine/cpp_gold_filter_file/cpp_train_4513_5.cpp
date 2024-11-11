#include <bits/stdc++.h>
const int INF = (int)(1e9);
const long long INFLL = (long long)(1e18);
const double EPS = 1e-13;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> f(n), s(n), a(n + 1);
  for (int i = (0); i < (int)(n); i++) cin >> f[i];
  for (int i = (0); i < (int)(n); i++) cin >> s[i];
  for (int i = (0); i < (int)(n); i++) a[s[i]] = i;
  for (int i = (0); i < (int)(n); i++) f[i] = a[f[i]];
  int best = -1, ans = 0;
  for (int i = (0); i < (int)(n); i++) {
    if (best > f[i]) {
      ans = n - i;
      break;
    }
    best = max(best, f[i]);
  }
  cout << ans << endl;
}
