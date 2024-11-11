#include <bits/stdc++.h>
using namespace std;
int n, k, x;
int mp[1002][1002];
void solve(int x) {
  int xc = (k + 1) / 2, yc = (k + 1) / 2;
  int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 1e9;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= (k - x + 1); j++) {
      int sum = 0, u = 1;
      for (int t = j; t < (j + x); t++) {
        if (mp[i][t]) {
          u = 0;
          break;
        }
        sum += abs(t - yc) + abs(i - xc);
      }
      if (u == 1 && sum < ans4) {
        ans4 = sum;
        ans1 = i;
        ans2 = j;
        ans3 = j + x - 1;
      }
    }
  }
  if (ans4 == 1e9)
    cout << "-1";
  else {
    for (int i = ans2; i <= ans3; i++) mp[ans1][i] = 1;
    cout << ans1 << " " << ans2 << " " << ans3 << endl;
  }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> x, solve(x);
  return 0;
}
