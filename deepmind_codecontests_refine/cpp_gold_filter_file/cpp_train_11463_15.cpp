#include <bits/stdc++.h>
using namespace std;
const long long LINF = 1e18;
const int INF = 1e9 * 2;
const int MOD = 1e9 + 7;
const int mod = 998244353;
const int nax = (1e5 + 10);
int pos[nax];
int dp[nax];
int n, m;
bool check(int mid) { return (1 + mid) * 1ll * mid / 2 <= n + m; }
void solve() {
  cin >> n >> m;
  int l = 0;
  int r = INF;
  for (int i = (0); i < (50); i++) {
    int mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  vector<int> vec1, vec2;
  long long sum_vec1 = n;
  long long sum_vec2 = n;
  for (int i = (l + 1) - 1; i >= (1); i--) {
    if (sum_vec1 >= i) {
      sum_vec1 -= i;
      vec1.push_back(i);
    } else {
      sum_vec2 -= i;
      vec2.push_back(i);
    }
  }
  cout << vec1.size() << '\n';
  for (int x : vec1) cout << x << ' ';
  cout << '\n';
  cout << vec2.size() << '\n';
  for (int x : vec2) cout << x << ' ';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int test_case;
  test_case = 1;
  for (; test_case > 0; test_case--) {
    solve();
  }
}
