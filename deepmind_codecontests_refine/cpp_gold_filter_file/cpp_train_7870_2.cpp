#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int MAX = 2e5 + 5;
const int MOD = 1e9 + 7;
const int64_t INF = INT_MAX;
const int64_t _INF = INT_MIN;
int n, q;
vector<int> bit[MAX];
int row[MAX];
int64_t rect[MAX];
void build() {
  for (int i = 1; i <= n; i++) {
    int curr = i & -i;
    bit[i].resize(curr);
    for (int j = 1; j <= curr; j++) bit[i][j - 1] = row[i - curr + j];
    sort(begin(bit[i]), end(bit[i]));
  }
  for (int i = 1; i <= n; i++) rect[i] = (i - 1) + rect[i - 1];
}
int cnt(int r, int c) {
  int ans = 0;
  while (r > 0) {
    ans += upper_bound(begin(bit[r]), end(bit[r]), c) - bit[r].begin();
    r -= r & -r;
  }
  return ans;
}
int64_t get(int r1, int c1, int r2, int c2) {
  int64_t invalid = rect[r1 - 1] + rect[c1 - 1] + rect[n - r2] + rect[n - c2];
  invalid -= rect[cnt(r1 - 1, c1 - 1)] + rect[c1 - 1 - cnt(r2, c1 - 1)] +
             rect[r1 - 1 - cnt(r1 - 1, c2)] + rect[n - c2 - (r2 - cnt(r2, c2))];
  return rect[n] - invalid;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int r;
    cin >> r;
    row[r] = i;
  }
  build();
  while (q--) {
    int r1, c1, r2, c2;
    cin >> c1 >> r1 >> c2 >> r2;
    cout << get(r1, c1, r2, c2) << "\n";
  }
}
