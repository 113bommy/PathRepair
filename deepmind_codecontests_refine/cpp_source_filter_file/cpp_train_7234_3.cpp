#include <bits/stdc++.h>
using namespace std;
int dp1[101010] = {0}, dp2[101010] = {0};
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int h[101010];
  for (int i = 0; i < n; i++) cin >> h[i];
  dp1[0] = 1;
  for (int i = 1; i < n - 1; i++) {
    dp1[i] = dp1[i - 1] + 1;
    dp1[i] = min(h[i], dp1[i]);
    if (h[i] > h[i - 1]) {
      dp1[i] = min(dp1[i], h[i - 1] + 1);
    }
    if (h[i] > h[i + 1]) {
      dp1[i] = min(dp1[i], h[i + 1] + 1);
    }
  }
  dp2[n - 1] = 1;
  for (int i = n - 2; i >= 1; i--) {
    dp2[i] = dp2[i + 1] + 1;
    dp2[i] = min(h[i], dp2[i]);
    if (h[i] > h[i - 1]) {
      dp2[i] = min(dp2[i], h[i - 1] + 1);
    }
    if (h[i] > h[i + 1]) {
      dp2[i] = min(dp2[i], h[i + 1] + 1);
    }
  }
  int ma = 0;
  for (int i = 0; i < n; i++) {
    ma = max(ma, min(dp1[i], dp2[i]));
  }
  cout << ma << endl;
  return 0;
}
