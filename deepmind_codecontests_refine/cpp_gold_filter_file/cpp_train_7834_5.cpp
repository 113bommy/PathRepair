#include <bits/stdc++.h>
using namespace std;
int n, q, a[300005], bit[300005];
vector<vector<int>> queries;
bool cmp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
int query(int x) {
  int sm = 0;
  while (x) {
    sm += bit[x];
    x -= x & -x;
  }
  return sm;
}
void update(int x, int val) {
  while (x < 300005) {
    bit[x] += val;
    x += x & -x;
  }
}
int find_idx(int lo, int hi, int val) {
  int ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (query(mid) >= val) {
      lo = mid + 1;
      ans = mid;
    } else {
      hi = mid - 1;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i], a[i] = i - a[i];
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    queries.push_back({x + 1, n - y, i});
  }
  sort(queries.begin(), queries.end(), cmp);
  vector<int> ans(q);
  int idx = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= 0) {
      int x = find_idx(1, i, a[i]);
      if (query(x) >= a[i] && x > 0) {
        update(1, 1);
        update(x + 1, -1);
      }
    }
    while (idx < q && queries[idx][1] == i) {
      ans[queries[idx][2]] = query(queries[idx][0]);
      idx++;
    }
  }
  for (int i = 0; i < q; i++) cout << ans[i] << '\n';
  return 0;
}
