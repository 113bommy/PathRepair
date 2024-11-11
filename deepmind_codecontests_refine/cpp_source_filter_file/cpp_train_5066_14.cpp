#include <bits/stdc++.h>
const long long N = 1e5, MOD = 1e9 + 7;
using namespace std;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long n, m, a[N], cnt, ans;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
  for (long long i = 1, x; i <= m; i++) {
    cin >> x;
    long long lb = lower_bound(a + 1, a + n + 1, x) - a;
    cout << lb << ' ' << x - a[lb - 1] << endl;
  }
  return 0;
}
