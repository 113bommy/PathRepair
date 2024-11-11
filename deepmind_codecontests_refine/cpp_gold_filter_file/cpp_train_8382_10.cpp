#include <bits/stdc++.h>
using namespace std;
long double const PI = acosl(-1);
const int INF = 1E9;
const int MAXN = 3e5 + 123;
const long double EPS = 3e-16;
const long long N = 2e5 + 5;
const long long mod = 1e9 + 7;
bool flag;
int a[MAXN];
int used[MAXN];
void solve() {
  int n, m, x, y;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    a[x] = i;
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    x = a[x];
    y = a[y];
    if (x > y) swap(x, y);
    used[y] = max(used[y], x + 1);
  }
  x = 1;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    x = max(x, used[i]);
    ans += i - x + 1;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q = 1;
  while (q--) {
    solve();
  }
  return 0;
}
