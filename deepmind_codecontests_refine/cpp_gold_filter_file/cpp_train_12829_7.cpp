#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5 + 10;
int tree[210][MX];
int query(int val, int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += (tree[val][idx]);
    idx -= idx & (-idx);
  }
  return sum;
}
void update(int val, int idx, int x, int n) {
  while (idx <= n) {
    tree[val][idx] += x;
    idx += idx & (-idx);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, l, r, i, j, n, cnt, mx, x, ans;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (j = 1; j <= 205; j++) {
      for (i = 0; i <= n; i++) tree[j][i] = 0;
    }
    vector<int> v[210];
    for (i = 0; i < n; i++) {
      scanf("%d", &x);
      v[x].emplace_back(i + 1);
      update(x, i + 1, 1, n);
    }
    ans = 1;
    for (i = 1; i <= 200; i++) {
      if (v[i].size() > 1) {
        l = 0, r = v[i].size() - 1, cnt = 0;
        while (l < r) {
          mx = 0;
          for (j = 1; j <= 200; j++) {
            mx = max(mx, query(j, v[i][r] - 1) - query(j, v[i][l]));
          }
          cnt += 2;
          ans = max(cnt + mx, ans);
          l++, r--;
        }
      }
    }
    printf("%d\n", ans);
  }
}
