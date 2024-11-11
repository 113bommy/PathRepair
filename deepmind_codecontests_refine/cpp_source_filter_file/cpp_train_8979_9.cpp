#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
int a[N], b[N];
int dp[N];
int main() {
  int n, m, q, k;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> n;
    n <<= 1;
    for (int i = 1; i <= n; i++) cin >> a[i], dp[i] = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      int cnt = 1;
      for (int j = i + 1; j <= n; j++)
        if (a[i] > a[j])
          ++cnt;
        else
          break;
      v.push_back(cnt);
      i += cnt - 1;
    }
    dp[0] = 1;
    for (auto x : v) {
      for (int j = n; j >= 1; j--) dp[j] |= dp[j - x];
    }
    cout << (dp[n / 2] ? "YES" : "NO");
    cout << '\n';
  }
}
