#include <bits/stdc++.h>
using namespace std;
int n;
void update(int arr[], int i, int x) {
  while (i <= n) {
    arr[i] += x;
    i = (i | (i - 1)) + 1;
  }
}
int fe(int arr[], int i) {
  if (i < 0) return 0;
  int ans = 0;
  while (i) {
    ans += arr[i];
    i = (i & (i - 1));
  }
  return ans;
}
int query(int arr[], int l, int r) {
  if (l > r) return 0;
  return fe(arr, r) - fe(arr, l - 1);
}
void solve() {
  int k, a, b, q;
  cin >> n >> k >> a >> b >> q;
  int atree[n + 1], btree[n + 1], aa[n + 1], bb[n + 1];
  memset(atree, 0, sizeof(atree));
  memset(btree, 0, sizeof(btree));
  memset(aa, 0, sizeof(aa));
  memset(bb, 0, sizeof(bb));
  while (q--) {
    int ty;
    cin >> ty;
    if (ty == 1) {
      int di, ai;
      cin >> di >> ai;
      int oldA = aa[di];
      int oldB = bb[di];
      aa[di] = min(a, oldA + ai);
      bb[di] = min(b, oldB + ai);
      update(atree, di, aa[di] - oldA);
      update(btree, di, bb[di] - oldA);
    } else {
      int x;
      cin >> x;
      cout << query(btree, 1, x - 1) + query(atree, x + k, n) << "\n";
    }
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  solve();
  return 0;
}
