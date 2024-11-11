#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1, L = 19;
int n;
long long int profit, d[N], c[N], diff[N], pre[N];
long long int table[N][L];
long long int pre_max[N][L], pre_min[N][L];
void build() {
  int i, j;
  for (i = 0; i < N; i++) {
    table[i][0] = diff[i];
    pre_max[i][0] = pre_min[i][0] = pre[i];
  }
  for (j = 1; j < L; j++) {
    for (i = 0; i + (1 << j) - 1 < N; i++) {
      table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
      pre_max[i][j] =
          max(pre_max[i][j - 1], pre_max[i + (1 << (j - 1))][j - 1]);
      pre_min[i][j] =
          max(pre_min[i][j - 1], pre_min[i + (1 << (j - 1))][j - 1]);
    }
  }
}
long long int find_max_diff(int l, int r) {
  int j = (int)log2(r - l + 1);
  return max(table[l][j], table[r - (1 << j) + 1][j]);
}
long long int find_max_pre(int l, int r) {
  int j = (int)log2(r - l + 1);
  return max(pre_max[l][j], pre_max[r - (1 << j) + 1][j]);
}
long long int find_min_pre(int l, int r) {
  if (l == 0 && r != 0) return min(0ll, find_min_pre(1, r));
  int j = (int)log2(r - l + 1);
  return min(pre_min[l][j], pre_min[r - (1 << j) + 1][j]);
}
int main() {
  long long int ans = 0ll;
  int i, j;
  scanf("%d %lld", &n, &profit);
  d[0] = c[0] = pre[0] = 0ll;
  for (i = 1; i <= n; i++) {
    scanf("%lld %lld", &d[i], &c[i]);
    c[i] = profit - c[i];
    ans = max(ans, c[i]);
    pre[i] = pre[i - 1] + c[i];
  }
  for (i = 0; i < N; i++) diff[i] = 0ll;
  for (i = 1; i < n; i++) diff[i] = d[i + 1] - d[i];
  build();
  int l, r, lower_bound, upper_bound;
  for (i = 2; i <= n; i++) {
    long long int cur_gap = diff[i - 1];
    l = 1;
    r = i - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      long long int mx = find_max_diff(mid, i - 1);
      if (mx <= cur_gap) {
        lower_bound = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    l = i;
    r = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      long long int mx = find_max_diff(i - 1, mid - 1);
      if (mx <= cur_gap) {
        upper_bound = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    long long int mx = find_max_pre(i - 1, upper_bound);
    long long int mn = find_min_pre(lower_bound - 2, i - 2);
    long long int money = mx - mn - cur_gap * cur_gap;
    ans = max(ans, money);
  }
  printf("%lld", ans);
}
