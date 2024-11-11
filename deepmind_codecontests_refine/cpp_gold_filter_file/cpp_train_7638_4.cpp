#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> v(n * m, 0);
  for (int i = 0; i < n * m; i++) cin >> v[i];
  int ans = INT_MAX;
  for (int i = 0; i < n * m; i++) {
    int temp_ans = 0;
    for (int j = 0; j < n * m; j++) {
      if (abs(v[j] - v[i]) % d != 0) {
        temp_ans = -1;
        break;
      } else {
        temp_ans += abs(v[j] - v[i]) / d;
      }
    }
    ans = min(temp_ans, ans);
    if (ans == -1) break;
  }
  cout << ans;
  return 0;
}
