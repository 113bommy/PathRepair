#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 3;
int n, q;
int a[MAXN];
void read() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> q;
}
int tr[MAXN * 4][60];
void merge(int v) {
  for (int i = 0; i <= 59; i++)
    tr[v][i] = tr[v * 2][i] + tr[v * 2 + 1][(i + tr[v * 2][i]) % 60];
}
void build(int v, int l, int r) {
  if (l == r) {
    for (int i = 0; i <= 59; i++) {
      if (i % a[l])
        tr[v][i] = 1;
      else
        tr[v][i] = 2;
    }
    return;
  }
  int mid = (l + r) / 2;
  build(v * 2, l, mid);
  build(v * 2 + 1, mid + 1, r);
  merge(v);
}
void update(int v, int l, int r, int pos, int val) {
  if (l == r) {
    for (int i = 0; i <= 59; i++) {
      if (i % val)
        tr[v][i] = 1;
      else
        tr[v][i] = 2;
    }
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid)
    update(v * 2, l, mid, pos, val);
  else
    update(v * 2 + 1, mid + 1, r, pos, val);
  merge(v);
}
int ans_time;
void get(int v, int l, int r, int ll, int rr) {
  if (r < ll || l > rr) return;
  if (l >= ll && r <= rr) {
    ans_time += tr[v][ans_time % 60];
    return;
  }
  int mid = (l + r) / 2;
  get(v * 2, l, mid, ll, rr);
  get(v * 2 + 1, mid + 1, r, ll, rr);
}
void solve() {
  build(1, 1, n);
  for (int i = 1; i <= q; i++) {
    char type;
    int x, y;
    cin >> type >> x >> y;
    if (type == 'A') {
      ans_time = 0;
      get(1, 1, n, x, y - 1);
      cout << ans_time << endl;
    } else
      update(1, 1, n, x, y);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  read();
  solve();
}
