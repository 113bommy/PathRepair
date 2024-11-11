#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int MAX = 2 * 1000 * 1000 + 10;
const long long INF = 1e18;
const int MOD = 1e9 + 7;
int ar[MAX], r[MAX], l[MAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, ans(0);
  cin >> n;
  if (n == 1) return cout << 1, 0;
  for (int i = 1; i <= n; i++) cin >> ar[i];
  ar[n + 1] = MOD;
  l[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (ar[i] > ar[i - 1])
      l[i] = l[i - 1] + 1;
    else
      l[i] = 1;
  }
  r[n + 1] = r[n] = 1;
  for (int i = n - 1; i > 0; i--) {
    if (ar[i] < ar[i + 1])
      r[i] = r[i + 1] + 1;
    else
      r[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    ans = max({ans, l[i - 1] + 1, r[i + 1] + 1});
    if (i < n and ar[i + 1] - ar[i - 1] > 1) {
      ans = max(ans, l[i - 1] + r[i + 1] + 1);
    }
  }
  cout << ans << '\n';
}
