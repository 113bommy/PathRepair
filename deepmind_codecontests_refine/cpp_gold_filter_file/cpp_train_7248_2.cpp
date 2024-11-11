#include <bits/stdc++.h>
using namespace std;
bool ok(vector<int>& v) {
  bool ans = true;
  for (int i = 1; i < v.size() && ans; i++) {
    ans &= v[i - 1] <= v[i] && v[i] != -1;
  }
  return ans && v[0] != -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> cur(n, -1);
  for (int i = 0; !ok(cur) || i < n; i++) {
    int val;
    cin >> val;
    if (val * 2 > c) {
      for (int i = n - 1; i >= 0; i--) {
        if (cur[i] == -1 || cur[i] < val || i == 0) {
          cout << i + 1 << endl;
          cur[i] = val;
          break;
        }
      }
    } else {
      for (int i = 0; i < n; i++) {
        if (cur[i] == -1 || cur[i] > val || i == n - 1) {
          cur[i] = val;
          cout << i + 1 << endl;
          break;
        }
      }
    }
  }
  return 0;
}
