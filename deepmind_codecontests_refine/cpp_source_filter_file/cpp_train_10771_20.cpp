#include <bits/stdc++.h>
using namespace std;
int n, A[2][200005], ANS[3][300005], tree[500005];
void upd(int node, int tl, int tr, int pos, int x) {
  if (tl == tr) {
    tree[node] += x;
    return;
  }
  int mid = (tl + tr) / 2;
  if (pos <= mid)
    upd(node * 2, tl, mid, pos, x);
  else
    upd(node * 2 + 1, mid + 1, tr, pos, x);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int get(int node, int tl, int tr, int x) {
  if (tl > x) return 0;
  if (tr <= x) return tree[node];
  int mid = (tl + tr) / 2;
  int y = get(node * 2, tl, mid, x);
  int z = get(node * 2 + 1, mid + 1, tr, x);
  return z + y;
}
void to_num(int x) {
  for (int i = 0; i < n; i++) upd(1, 0, n - 1, i, 1);
  for (int i = 1; i <= n; i++) {
    ANS[x][i] = get(1, 0, n - 1, A[x][i] - 1);
    upd(1, 0, n - 1, A[x][i], -1);
  }
}
void go() {
  for (int i = 0; i < n; i++) upd(1, 0, n - 1, i, 1);
  for (int i = 1; i <= n; i++) {
    int x = ANS[2][i];
    int l = 0, r = n - 1;
    int ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (get(1, 0, n - 1, mid - 1) <= x) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    cout << ans << " ";
    upd(1, 0, n - 1, ans, -1);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> A[0][i];
  for (int i = 1; i <= n; i++) cin >> A[1][i];
  to_num(0);
  to_num(1);
  for (int i = n; i >= 1; i--) {
    ANS[2][i] += ANS[1][i] + ANS[0][i];
    int x = n - i + 1;
    ANS[2][i - 1] += (ANS[2][i] >= x);
    ANS[2][i] %= x;
  }
  go();
}
