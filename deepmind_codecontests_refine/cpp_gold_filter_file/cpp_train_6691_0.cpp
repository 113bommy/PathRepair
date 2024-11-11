#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, seed = 131, MAXN = 0;
struct Move {
  long long i, j, x;
};
void solve() {
  int n;
  cin >> n;
  vector<long long> arr(n + 1);
  vector<Move> ans;
  long long tot = 0;
  for (int i = 1; i <= n; ++i) cin >> arr[i], tot += arr[i];
  if (tot % n != 0) {
    cout << -1 << '\n';
    return;
  }
  long long ave = tot / n;
  for (int i = 2; i <= n; ++i) {
    long long temp = (arr[i] - 1) / i;
    temp++;
    long long temp2 = temp * i - arr[i];
    ans.push_back({1, i, temp2});
    arr[1] -= temp2;
    arr[i] += temp2;
    ans.push_back({i, 1, temp});
    arr[i] -= temp * i;
    arr[1] += temp * i;
  }
  for (int i = 2; i <= n; ++i) {
    long long temp = ave - arr[i];
    ans.push_back({1, i, temp});
    arr[1] -= temp;
    arr[i] += temp;
  }
  cout << ans.size() << '\n';
  for (Move uwu : ans) {
    cout << uwu.i << " " << uwu.j << " " << uwu.x << '\n';
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
