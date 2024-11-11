#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int L = 5 * (int)1e5;
pair<int, int> solve(const vector<pair<int, int>>& pairs, int k) {
  int x_min = 0, x_max = L;
  int y_min = 0, y_max = L;
  int d_min = -L, d_max = L;
  for (auto pr : pairs) {
    int x = pr.first;
    int y = pr.second;
    x_min = max(x_min, x - k);
    x_max = min(x_max, x + k);
    y_min = max(y_min, y - k);
    y_max = min(y_max, y + k);
    d_min = max(d_min, x - y - k);
    d_max = min(d_max, x - y + k);
  }
  int dx = x_max - x_min;
  int dy = y_max - y_min;
  if (dx < 0 || dy < 0 || d_min > d_max) return {-1, -1};
  int tar_d = x_max - y_max;
  int it_a = max(d_min, tar_d - dx);
  int it_b = min(d_max, tar_d + dy);
  if (it_a > it_b)
    return {-1, -1};
  else if (it_a < tar_d)
    return {x_max - (tar_d - it_a), y_max};
  else
    return {x_max, y_max - (it_a - tar_d)};
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> pairs(n);
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    int c0 = 0;
    for (auto c : str) c0 += (c == 'B');
    pairs[i] = {c0, (int)str.size() - c0};
  }
  int low = 0;
  int high = L;
  while (low != high) {
    int mid = (low + high) >> 1;
    if (solve(pairs, mid).first == -1)
      low = mid + 1;
    else
      high = mid;
  }
  auto pr = solve(pairs, low);
  int m = pr.first + pr.second;
  string res(m, 'B');
  for (int i = pr.first; i < m; ++i) res[i] = 'N';
  cout << low << '\n';
  cout << res << '\n';
}
