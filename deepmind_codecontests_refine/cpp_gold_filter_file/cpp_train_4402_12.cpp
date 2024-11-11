#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, LOG = 30;
int n;
long long dp[LOG], cnt[LOG];
vector<pair<int, int>> arr;
vector<int> solve(vector<pair<int, int>> &cur, int val, int h) {
  if (h == -1) {
    vector<int> res;
    for (auto i : cur) {
      res.push_back(i.second);
    }
    sort(res.begin(), res.end());
    return res;
  }
  vector<pair<int, int>> a, b;
  for (auto i : cur) {
    if (i.first < val + (1 << h)) {
      a.push_back(i);
    } else {
      b.push_back(i);
    }
  }
  if (a.empty()) {
    return solve(b, val + (1 << h), h - 1);
  } else if (b.empty()) {
    return solve(a, val, h - 1);
  } else {
    auto res1 = solve(a, val, h - 1);
    auto res2 = solve(b, val + (1 << h), h - 1);
    for (auto i : res1) {
      dp[h] += upper_bound(res2.begin(), res2.end(), i) - res2.begin();
    }
    cnt[h] += ((long long)res1.size()) * ((long long)res2.size());
    vector<int> res;
    int ind1 = 0, ind2 = 0;
    while (ind1 != (int)res1.size() || ind2 != (int)res2.size()) {
      if (ind2 == (int)res2.size() ||
          ((ind1 != (int)res1.size()) && res1[ind1] < res2[ind2])) {
        res.push_back(res1[ind1++]);
      } else {
        res.push_back(res2[ind2++]);
      }
    }
    return res;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int val;
    cin >> val;
    arr.emplace_back(val, i);
  }
  sort(arr.begin(), arr.end());
  solve(arr, 0, 29);
  long long sum = 0;
  for (int i = LOG - 1; i >= 0; --i) {
    sum += min(dp[i], cnt[i] - dp[i]);
  }
  cout << sum << " ";
  int answer = 0;
  for (int i = LOG - 1; i >= 0; --i) {
    answer = answer * 2 + (dp[i] * 2 > cnt[i]);
  }
  cout << answer << "\n";
}
