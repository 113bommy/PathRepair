#include <bits/stdc++.h>
using namespace std;
int n;
int ans[1003];
int arr[1003];
int sum_mask[1000003 * 14];
vector<int> v[2];
vector<int> loop;
void print(bool is_ok) {
  cout << (is_ok ? "YES" : "NO") << '\n';
  if (!is_ok) exit(0);
  cout << ans[0];
  for (int i = 1; i < n; ++i) cout << " " << ans[i];
  cout << '\n';
  exit(0);
}
void input() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    int is_odd = arr[i] & 1;
    v[is_odd].push_back(arr[i]);
  }
}
void solve() {
  sort(arr, arr + n);
  for (int i = 0; i < n - 1; ++i) {
    if (arr[i] == arr[i + 1]) {
      for (int j = 0; j < n; ++j) ans[j] = arr[j];
      ans[i] = 0;
      print(true);
    }
  }
  if (!v[0].empty()) {
    if (v[0].size() >= 3)
      loop = {v[0][0], v[0][1], v[0][2]};
    else if (v[1].size() >= 2)
      loop = {v[0][0], v[1][0], v[1][1]};
    else
      print(false);
    ans[0] = (loop[0] + loop[1] - loop[2]) / 2;
    ans[1] = (loop[1] + loop[2] - loop[0]) / 2;
    ans[2] = (loop[2] + loop[0] - loop[1]) / 2;
    int idx = 3;
    for (int i = 0; i < n; ++i) {
      bool skip = 0;
      for (int j = 0; j < 3; ++j)
        if (arr[i] == loop[j]) {
          skip = 1;
          break;
        }
      if (!skip) ans[idx++] = arr[i] - ans[0];
    }
    print(true);
  }
  int m = min(n, 26);
  int set1 = -1, set2 = -1;
  for (int mask = 0; mask < (1 << m); ++mask)
    if (__builtin_popcount(mask) == m / 2) {
      int tmp_sum = 0;
      for (int j = 0; j < m; ++j)
        if ((mask >> j) & 1) tmp_sum += v[1][j];
      if (sum_mask[tmp_sum]) {
        set1 = sum_mask[tmp_sum];
        set2 = mask;
        break;
      }
      sum_mask[tmp_sum] = mask;
    }
  if (set1 == -1) print(false);
  int common = set1 & set2;
  set1 ^= common;
  set2 ^= common;
  vector<int> sums1, sums2;
  for (int i = 0; i < m; ++i) {
    if ((set1 >> i) & 1) sums1.push_back(v[1][i]);
    if ((set2 >> i) & 1) sums2.push_back(v[1][i]);
  }
  for (int i = 0; i < sums1.size(); ++i) {
    loop.push_back(sums1[i]);
    loop.push_back(sums2[i]);
  }
  ans[0] = 0;
  for (int i = 1; i < loop.size(); ++i) ans[i] = loop[i - 1] - ans[i - 1];
  int idx = loop.size();
  for (int i = 0; i < n; ++i) {
    if (i >= m || !(((set1 | set2) >> i) & 1)) ans[idx++] = v[1][i] - ans[0];
  }
  print(true);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  return 0;
}
