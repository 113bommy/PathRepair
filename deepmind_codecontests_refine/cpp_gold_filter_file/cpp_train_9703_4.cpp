#include <bits/stdc++.h>
using namespace std;
queue<int> ans[10005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, cur = 1;
  cin >> n;
  int k = (sqrt(1 + 8 * n) + 1) / 2;
  cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < i; ++j) {
      cout << ans[j].front() << ' ';
      ans[j].pop();
    }
    for (int j = i; j < k - 1; ++j, ++cur) cout << cur << ' ', ans[i].push(cur);
    cout << '\n';
  }
  return 0;
}
