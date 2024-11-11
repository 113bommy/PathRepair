#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
int n, a;
vector<pair<int, int>> nums;
set<pair<int, int>> second;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    nums.push_back({a, i});
  }
  int ans = 0;
  sort(begin(nums), end(nums));
  reverse(begin(nums), end(nums));
  for (int i = 0; i <= (int)nums.size() - 1; i++) {
    int x = nums[i].first;
    int pos = nums[i].second;
    if (!second.empty() && second.lower_bound({pos, 0}) != second.end()) {
      ans = max(ans, x ^ (*second.lower_bound({pos, 0})).second);
    }
    if (!second.empty() && second.lower_bound({pos, 0}) != second.begin()) {
      ans = max(ans, x ^ (*prev(second.lower_bound({pos, 0}))).second);
    }
    second.insert({pos, x});
  }
  cout << ans;
}
