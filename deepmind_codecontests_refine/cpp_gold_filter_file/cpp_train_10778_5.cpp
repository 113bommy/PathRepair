#include <bits/stdc++.h>
using namespace std;
struct BIT {
  int N;
  vector<long long> tree, lazy;
  void init(int N) {
    this->N = N;
    tree = vector<long long>(4 * N, 0);
    lazy = vector<long long>(4 * N, -1);
  }
  void prop(int x, int l, int r) {
    int m = (l + r) / 2;
    if (l != r && lazy[x] != -1) {
      tree[x * 2] = lazy[x] * (m - l + 1);
      tree[x * 2 + 1] = lazy[x] * (r - (m + 1) + 1);
      lazy[x * 2] = lazy[x];
      lazy[x * 2 + 1] = lazy[x];
      lazy[x] = -1;
    }
  }
  void update(int x, int l, int r, int a, int b, int v) {
    if (r < a || b < l) return;
    if (a <= l && r <= b) {
      tree[x] = 1LL * v * (r - l + 1);
      lazy[x] = v;
      return;
    }
    prop(x, l, r);
    int m = (l + r) / 2;
    update(x * 2, l, m, a, b, v);
    update(x * 2 + 1, m + 1, r, a, b, v);
    tree[x] = tree[x * 2] + tree[x * 2 + 1];
  }
  long long query(int x, int l, int r, int a, int b) {
    if (r < a || b < l) return 0;
    if (a <= l && r <= b) return tree[x];
    prop(x, l, r);
    int m = (l + r) / 2;
    long long L = query(x * 2, l, m, a, b);
    long long R = query(x * 2 + 1, m + 1, r, a, b);
    return L + R;
  }
  void update(int a, int b, int v) { update(1, 0, N - 1, a, b, v); }
  long long query(int a, int b) { return query(1, 0, N - 1, a, b); }
} bit;
const int MN = 200000;
int N;
vector<int> arr, posl, posr;
vector<vector<int> > dpos, posc;
void get_dpos() {
  dpos.resize(MN + 1);
  for (int i = 0; i < N; i++) {
    for (int j = 1; j * j <= arr[i]; j++) {
      if (arr[i] % j == 0) {
        dpos[j].push_back(i);
        if (j * j != arr[i]) dpos[arr[i] / j].push_back(i);
      }
    }
  }
}
void get_pos() {
  posl = posr = vector<int>(N, -1);
  posc.resize(N);
  for (int i = 1; i <= MN; i++) {
    if (dpos[i].size() < 2) continue;
    int L1 = dpos[i][0], L2 = dpos[i][1];
    int R2 = dpos[i][(int)dpos[i].size() - 2];
    posl[L2] = i;
    posr[R2] = i;
    posc[L1].push_back(i);
  }
}
int main() {
  scanf("%d", &N);
  arr.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }
  get_dpos();
  get_pos();
  long long ans = 0;
  int X = N + 1;
  bit.init(X);
  int mx = -1;
  for (int i = N - 1; i >= 0; i--) {
    if (mx < posr[i]) {
      mx = posr[i];
      bit.update(0, i, posr[i]);
    }
  }
  ans += bit.query(1, X - 1);
  mx = -1;
  for (int i = 0; i < N - 1; i++) {
    if (mx < posl[i]) {
      mx = posl[i];
      int s = 0, e = X - 1, idx = -1;
      while (s <= e) {
        int m = (s + e) / 2;
        if (bit.query(m, m) < mx) {
          idx = m;
          e = m - 1;
        } else {
          s = m + 1;
        }
      }
      if (idx != -1) {
        bit.update(idx, X - 1, mx);
      }
    }
    for (auto& x : posc[i]) {
      int s = 0, e = dpos[x].back(), idx = -1;
      while (s <= e) {
        int m = (s + e) / 2;
        if (bit.query(m, m) < x) {
          idx = m;
          e = m - 1;
        } else {
          s = m + 1;
        }
      }
      if (idx != -1) {
        bit.update(idx, dpos[x].back(), x);
      }
    }
    ans += bit.query(i + 2, X - 1);
  }
  printf("%lld", ans);
  return 0;
}
