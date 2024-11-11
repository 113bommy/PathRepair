#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1000000000000000000LL;
int T;
long long L, R;
int cur[18];
vector<long long> nums;
long long get_num() {
  long long ret = 0;
  for (int i = 0; i < 18; i++) ret = 10 * ret + cur[i];
  return ret;
}
void go(int idx, int prv, int maxIdx) {
  if (idx == maxIdx) {
    nums.push_back(get_num());
    return;
  }
  for (int i = prv + 1; i < 18; i++)
    for (int j = 1; j <= 9; j++) {
      cur[i] = j;
      go(idx + 1, i, maxIdx);
      cur[i] = 0;
    }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> T;
  for (int i = 0; i < 3; i++) go(0, -1, i);
  sort(nums.begin(), nums.end());
  for (int i = 0; i < T; i++) {
    cin >> L >> R;
    int left = lower_bound(nums.begin(), nums.end(), L) - nums.begin();
    int right = upper_bound(nums.begin(), nums.end(), R) - nums.begin() - 1;
    int ans = right - left + 1;
    ans += (R == MAX);
    cout << ans << "\n";
  }
  return 0;
}
