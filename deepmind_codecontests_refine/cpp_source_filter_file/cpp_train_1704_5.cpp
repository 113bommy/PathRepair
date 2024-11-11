#include <bits/stdc++.h>
using namespace std;
const int MAXBIT = 5;
int n;
int a[100005];
int tree[20][400000];
int buff[20][400000];
int nn;
int m;
void update(int l, int r, int ll, int rr, int idx, int b) {
  if (buff[b][idx] == 1) {
    tree[b][idx] = (rr - ll + 1) - tree[b][idx];
    buff[b][idx] = 0;
    if (ll != rr) {
      buff[b][2 * idx] = 1 - buff[b][2 * idx];
      buff[b][2 * idx + 1] = 1 - buff[b][2 * idx + 1];
    }
  }
  if (l <= ll && rr <= r) {
    tree[b][idx] = (rr - ll + 1) - tree[b][idx];
    if (ll != rr) {
      buff[b][2 * idx] = 1 - buff[b][2 * idx];
      buff[b][2 * idx + 1] = 1 - buff[b][2 * idx + 1];
    }
    return;
  }
  if (r < ll || rr < l) return;
  int mid = (ll + rr) >> 1;
  update(l, r, ll, mid, 2 * idx, b);
  update(l, r, mid + 1, rr, 2 * idx + 1, b);
  tree[b][idx] = tree[b][2 * idx] + tree[b][2 * idx + 1];
}
long long query(int l, int r, int ll, int rr, int idx, int b) {
  if (buff[b][idx] == 1) {
    tree[b][idx] = (rr - ll + 1) - tree[b][idx];
    buff[b][idx] = 0;
    if (ll != rr) {
      buff[b][2 * idx] ^= 1;
      buff[b][2 * idx + 1] ^= 1;
    }
  }
  if (l <= ll && rr <= r) return tree[b][idx];
  if (r < ll || rr < l) return 0;
  int mid = (ll + rr) >> 1;
  return query(l, r, ll, mid, 2 * idx, b) +
         query(l, r, mid + 1, rr, 2 * idx + 1, b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (nn = 1; nn <= n; nn <<= 1)
    ;
  memset(tree, 0, sizeof(tree));
  memset(buff, 0, sizeof(buff));
  for (int b = 0; b <= MAXBIT; b++) {
    for (int i = nn; i <= nn + n - 1; i++)
      tree[b][i] = ((a[i - nn + 1] & (1 << b)) != 0);
    for (int i = nn - 1; i >= 1; i--)
      tree[b][i] = tree[b][2 * i] + tree[b][2 * i + 1];
  }
  cin >> m;
  for (int q = 1; q <= m; q++) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      long long ans = 0;
      for (int b = 0; b <= MAXBIT; b++)
        ans += query(l, r, 1, nn, 1, b) * ((1 << b));
      cout << ans << endl;
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      for (int b = 0; b <= MAXBIT; b++) {
        if ((x & (1 << b)) == 0) continue;
        update(l, r, 1, nn, 1, b);
      }
    }
  }
  return 0;
}
