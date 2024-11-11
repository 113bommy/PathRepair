#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int ans_i;
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << n << endl;
    for (int i = 0; i < n; i++) cout << 1 + i << " ";
    cout << endl;
    return 0;
  }
  if (2 * k + 1 >= n) {
    cout << 1 << endl << (n + 1) / 2 << endl;
    return 0;
  }
  for (int i = 0; i <= k; i++) {
    int cur = i + k + 1;
    if ((n - cur) % (2 * k + 1) == 0) {
      ans_i = i;
      break;
    } else if ((n - cur) % (2 * k + 1) >= k + 1) {
      ans_i = i;
      break;
    }
  }
  int pos = ans_i + 1;
  while (pos < n) {
    ans.push_back(pos);
    pos += 2 * k + 1;
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
