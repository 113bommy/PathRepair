#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, ans = 0, mx = 0;
  cin >> n;
  map<int, int> cnt, nums;
  for (int i = 0; i < n; ++i) {
    int el, j = 0;
    cin >> el;
    if (nums.find(cnt[el]) != nums.end()) {
      --nums[cnt[el]];
    }
    ++cnt[el];
    ++nums[cnt[el]];
    mx = max(mx, cnt[el]);
    if ((int)cnt.size() == 1 || (int)cnt.size() == i + 1 ||
        ((mx - 1) * nums[mx - 1] == i - mx + 1 && nums[mx] == 1) ||
        (mx * nums[mx] == i && nums[1] == 1)) {
      ans = i + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
