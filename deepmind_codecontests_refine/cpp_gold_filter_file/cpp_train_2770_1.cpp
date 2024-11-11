#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> nums;
vector<int> last;
vector<int> ans;
int n, k, m, a;
bool cmp(pair<int, int> &a, pair<int, int> &b) {
  if (a.first == b.first) {
    return (last[a.second] < last[b.second]);
  }
  return (a.first > b.first);
}
bool check2(int nomber) {
  if (!(nums[nomber].first + m)) return 0;
  if (nomber <= k) return 1;
  if (nums[nomber].first + m > nums[k].first) return 1;
  return 0;
}
bool check1(int nomber) {
  vector<int> num;
  int _m = m;
  bool pp = 1;
  if (nomber > k || nums[nomber].first == 0) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    num.push_back(nums[i].first);
  }
  int cnt = 0;
  for (int i = nomber + 1; i < n; ++i) {
    int r = num[nomber] - num[i] + 1;
    if (_m < r) {
      break;
    }
    _m -= r;
    ++cnt;
  }
  return (cnt + nomber <= k);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k >> m >> a;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  m -= a;
  k--;
  ans.resize(n);
  nums.resize(n, make_pair(0, 0));
  last.resize(n, 100000);
  for (int i = 0; i < n; ++i) {
    nums[i].second = i;
  }
  for (int i = 0; i < a; ++i) {
    int t;
    cin >> t;
    --t;
    last[t] = i;
    ++nums[t].first;
  }
  sort(nums.begin(), nums.end(), cmp);
  for (int i = 0; i < n; ++i) {
    int idx = nums[i].second;
    if (!check2(i)) {
      ans[idx] = 3;
    } else if (check1(i)) {
      ans[idx] = 1;
    } else {
      ans[idx] = 2;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
}
