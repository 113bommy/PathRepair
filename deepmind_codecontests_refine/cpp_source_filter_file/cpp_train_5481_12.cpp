#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int arr[2000];
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  int sum2 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (arr[i] == 2) {
      ++sum2;
    }
  }
  int ans = 0;
  for (int i = 0, cnt1 = 0, cnt2 = 0; i < n; ++i) {
    if (arr[i] == 1) {
      ++cnt1;
    } else {
      ++cnt2;
    }
    ans = max(ans, cnt1 + sum2 - cnt2);
  }
  for (int l = 0, pre1 = 0, pre2 = 0; l < n; ++l) {
    if (arr[l] == 1) {
      ++pre1;
      continue;
    }
    for (int r = l + 1, cur = 0, cnt2 = 0; r < n; ++r) {
      if (arr[r] == 2) {
        ++cnt2;
        continue;
      }
      cur = max(cur, cnt2) + 1;
      ans = max(ans, pre1 + cur + sum2 - pre2 - cnt2);
    }
    ++pre2;
  }
  cout << ans << "\n";
  return 0;
}
