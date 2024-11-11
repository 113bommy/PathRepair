#include <bits/stdc++.h>
using namespace std;
int ans[1010][1010];
int main() {
  ios_base::sync_with_stdio(0);
  int n, k, d;
  cin >> n >> k >> d;
  long long tmp = 1;
  bool check = false;
  for (int i = 0; i < d; i++) {
    tmp *= k;
    if (tmp >= n) {
      check = 1;
      break;
    }
  }
  if (!check) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < d; j++) {
      ans[i][j] = ans[i - 1][j];
    }
    for (int j = d - 1; j >= 0; j--) {
      ans[i][j] = (ans[i][j] + 1) % k;
      if (ans[i][j]) break;
    }
  }
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[j][i] + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}
