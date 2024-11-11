#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int have = 0;
  vector<int> ans = {0};
  for (int i = 1; i <= n; ++i) {
    int add = (i - 1) / 2;
    if (have + add > m) break;
    ans.push_back(i);
    have += add;
  }
  if (ans.back() == n and m != have) {
    cout << -1;
    return 0;
  }
  int rem = m - have;
  if (rem) {
    int k = ans.back();
    ans.push_back(k + k - 2 * rem + 1);
  }
  while (ans.size() < n + 1) {
    ans.push_back(100000000 + ans.size() * 6000);
  }
  for (int i = 1; i < ans.size(); ++i) cout << ans[i] << ' ';
}
