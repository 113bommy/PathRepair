#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n;
  map<int, int> M1, M2;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a == b) {
      M1[a]++;
    } else {
      M1[a]++;
      M2[b]++;
    }
  }
  int ans = INT_MAX;
  for (auto it : M1) {
    if (it.second >= (n + 1) / 2) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (auto it : M2) {
    if (it.second + M1[it.first] == (n + 1) / 2) {
      ans = min(ans, it.second);
    } else if (it.second + M1[it.first] > (n + 1) / 2) {
      ans = min(ans, (n + 1) / 2 - it.first);
    }
  }
  if (ans == INT_MAX) {
    cout << -1 << endl;
  } else
    cout << ans << endl;
}
