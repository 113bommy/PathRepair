#include <bits/stdc++.h>
const int N = (int)6e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const long long linf = (long long)1e18 + 7;
const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
using namespace std;
int n;
long long a[N], b[N];
long long second[N];
void solve() {
  cin >> n;
  for (int i = (1); i <= (n); i++) {
    cin >> a[i] >> b[i];
    a[i + n] = a[i];
    b[i + n] = b[i];
  }
  for (int i = (1); i <= (n + n); i++) {
    second[i] = second[i - 1];
    second[i] += max(0ll, a[i] - b[i - 1]);
  }
  long long ans = linf;
  for (int i = (1); i <= (n); i++) {
    ans = min(ans, second[i + n - 1] - second[i] + a[i]);
  }
  cout << ans << '\n';
}
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  exit(0);
}
