#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long mod = 1e9 + 7;
const long long N = 500 + 5, K = 105;
const int si = (1 << 20);
const long long add = 1e4;
const long long M = 1000 + 5;
const double INFdb = 1e10;
const long long oo = 1e18;
int n, m;
int w[N];
int b[M];
bool used[N];
int ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  for (int i = 1; i <= m; ++i) cin >> b[i];
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) used[j] = 0;
    int res = 0;
    for (int j = i - 1; j >= 1; --j) {
      if (b[i] == b[j]) break;
      if (used[b[j]]) continue;
      used[b[j]] = 1;
      res += w[b[j]];
    }
    ans += res;
  }
  cout << ans;
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
