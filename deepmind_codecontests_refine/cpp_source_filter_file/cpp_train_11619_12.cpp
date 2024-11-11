#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long SIZE = 100000;
const int INF = 0x3f3f3f3f;
const long long ll_INF = 0x3f3f3f3f3f3f3f3f;
const long double PI = acos(-1);
const long long MAXN = numeric_limits<long long>::max();
const long long MAX = 2000000;
void disp(vector<long long> v) {
  for (auto u : v) cout << u << " ";
  cout << '\n';
}
void solve() {
  long long n, m, y{};
  cin >> n >> m;
  vector<long long> p(n), l(m), r(m), x(m);
  for (long long i = 0; i < n; i++) cin >> p[i];
  for (long long i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> x[i];
    y = 0;
    for (long long j = l[i] - 1; j < r[i]; j++) {
      if (p[j] < p[x[i] - 1]) y++;
    }
    if (l[i] + y == x[i])
      cout << "Yes\n";
    else
      cout << "no\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
