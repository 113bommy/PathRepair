#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> A(n);
  for (long long i = 0; i < n; i++) cin >> A[i];
  vector<pair<long long, long long>> nums;
  for (long long i = 0; i < n; i++) {
    nums.push_back({A[i], i});
  }
  sort(nums.begin(), nums.end());
  vector<long long> a1, a2;
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0) {
      a1.push_back(nums[i].second);
    } else {
      a2.push_back(nums[i].second);
    }
  }
  cout << a1.size() << '\n';
  for (auto x : a1) cout << x << ' ';
  cout << '\n';
  cout << a2.size() << '\n';
  for (auto x : a2) cout << x << ' ';
  cout << '\n';
}
