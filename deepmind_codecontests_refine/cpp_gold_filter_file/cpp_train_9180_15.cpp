#include <bits/stdc++.h>
using namespace std;
pair<long long, pair<long long, long long>> sl0(vector<long long> nums) {
  long long n = nums.size();
  long long v = -1;
  long long ck = 0;
  for (long long i = 0; i < n; ++i) {
    if (nums[i] == 0) {
      v = i;
      ck++;
    }
  }
  vector<long long> nums2;
  for (long long i = v; i < n; ++i) {
    nums2.push_back(nums[i]);
  }
  for (long long i = 0; i < v; ++i) {
    nums2.push_back(nums[i]);
  }
  long long l = -1;
  long long cnt = 0;
  pair<long long, pair<long long, long long>> ans = {ck, {0, 0}};
  for (long long i = 0; i < n; ++i) {
    if (nums2[i] == 0) {
      l = -1;
      cnt = 0;
    }
    if (nums2[i] == 2 and l != -1) {
      cnt++;
    }
    if (nums2[i] == 1) {
      if (l == -1)
        l = i;
      else {
        if (ans.first < ck + cnt) {
          ans = {ck + cnt, {(l + v) % n, (i - 1 + v) % n}};
        }
        cnt = 0;
        l = i;
      }
    }
  }
  return ans;
}
pair<long long, pair<long long, long long>> sl1(vector<long long> nums) {
  long long n = nums.size();
  long long ck = 0;
  for (long long i = 0; i < n; ++i) {
    nums[i]--;
    if (nums[i] == 0) {
      ck++;
    }
  }
  long long l = -1;
  long long cnt = 0;
  pair<long long, pair<long long, long long>> ans = {-1, {0, 0}};
  for (long long i = 0; i < 2 * n; ++i) {
    if (nums[i % n] == 0) {
      cnt++;
      if (l == -1) l = i % n;
      if (ans.first < cnt) {
        ans = {cnt, {(l + n - 1) % n, i % n}};
      }
    }
    if (nums[i % n] == -1) {
      l = -1;
      cnt = 0;
    }
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  vector<long long> nums(n + 1);
  long long v = 0;
  long long k = 0;
  for (long long i = 0; i < n; ++i) {
    if (s[i] == '(')
      nums[i + 1] = nums[i] + 1;
    else
      nums[i + 1] = nums[i] - 1;
    k = min(nums[i + 1], k);
  }
  for (auto &i : nums) {
    i -= k;
  }
  if (nums[0] != nums[n]) {
    cout << "0\n1 1";
    return 0;
  }
  nums.pop_back();
  auto ans = max(sl1(nums), sl0(nums));
  cout << ans.first << '\n'
       << ans.second.first + 1 << ' ' << ans.second.second + 1;
}
