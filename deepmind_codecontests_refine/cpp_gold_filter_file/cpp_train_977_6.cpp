#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, arr[200005], dp[200005];
int b_search(int h, int l, int b) {
  int mid;
  while (l < h) {
    mid = (l + h) / 2;
    if (b > dp[mid]) {
      l = mid + 1;
    } else
      h = mid;
  }
  return h;
}
int LIS(int x) {
  int len = 1;
  dp[0] = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < dp[0]) {
      dp[0] = arr[i];
    } else if (arr[i] > dp[len - 1]) {
      dp[len++] = arr[i];
    } else {
      int p = b_search(len - 1, 0, arr[i]);
      dp[p] = arr[i];
    }
  }
  return len;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  int ans = LIS(n);
  cout << ans << endl;
  return 0;
}
