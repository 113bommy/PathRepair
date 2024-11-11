#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, M = 1e6 + 5;
long long n, a[N], sum[N], ans, mx, ans1, le_[8 * N][3], ri_[8 * N][3], cur;
pair<long long, long long> tree[8 * N][3];
long long first(long long x, long long k, long long b) { return k * x + b; }
void insert(long long node, long long le, long long ri, long long k,
            long long b, int ty) {
  if (le == ri) {
    if (first(le - M, k, b) >
        first(le - M, tree[node][ty].first, tree[node][ty].second)) {
      tree[node][ty].first = k;
      tree[node][ty].second = b;
    }
    return;
  }
  int mid = (le + ri) / 2;
  if (k < tree[node][ty].first) {
    swap(tree[node][ty].first, k);
    swap(tree[node][ty].second, b);
  }
  if (first(mid - M, k, b) >
      first(mid - M, tree[node][ty].first, tree[node][ty].second)) {
    if (!le_[node][ty]) {
      cur++;
      le_[node][ty] = cur;
      tree[le_[node][ty]][ty] = {-1e10, -1e17};
    }
    insert(le_[node][ty], le, mid, tree[node][ty].first, tree[node][ty].second,
           ty);
    tree[node][ty].first = k;
    tree[node][ty].second = b;
  } else {
    if (!ri_[node][ty]) {
      ri_[node][ty] = cur;
      cur++;
      ri_[node][ty] = cur;
      tree[ri_[node][ty]][ty] = {-1e10, -1e14};
    }
    insert(ri_[node][ty], mid + 1, ri, k, b, ty);
  }
}
long long getans(long long node, long long le, long long ri, long long idx,
                 long long ty) {
  if (le > idx || ri < idx || !node) return -1e17;
  if (le == ri) {
    return first(le - M, tree[node][ty].first, tree[node][ty].second);
  }
  int mid = (le + ri) / 2;
  return max(first(idx - M, tree[node][ty].first, tree[node][ty].second),
             max(getans(le_[node][ty], le, mid, idx, ty),
                 getans(ri_[node][ty], mid + 1, ri, idx, ty)));
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i] + M);
    ans += a[i] * i;
    sum[i] = sum[i - 1] + a[i];
  }
  ans1 = ans;
  cur = 1;
  tree[1][0] = tree[1][1] = {-1e10, -1e17};
  for (int ri = 1; ri <= n; ri++) {
    insert(1, 1, mx, ri, -sum[ri - 1], 0);
    ans = max(ans,
              ans1 + getans(1, 1, mx, a[ri] + M, 0) + sum[ri - 1] - a[ri] * ri);
  }
  cur = 1;
  for (int le = n; le >= 1; le--) {
    insert(1, 1, mx, le, -sum[le], 1);
    ans =
        max(ans, ans1 + getans(1, 1, mx, a[le] + M, 1) + sum[le] - a[le] * le);
  }
  cout << ans << endl;
}
