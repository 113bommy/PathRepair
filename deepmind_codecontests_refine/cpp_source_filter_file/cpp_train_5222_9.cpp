#include <bits/stdc++.h>
using namespace std;
inline int L(int v) { return v << 1; }
inline int R(int v) { return (v << 1) ^ 1; }
inline int P(int v) { return v >> 1; }
const int r = 1 << 3;
const int s = r << 1;
int tree[s];
void wypisz() {
  int i, j, k = 0;
  for (int i = 1; i < s; i <<= 1) {
    for (int j = 1; j <= i; j++) {
      cout << tree[j + k] << " ";
    }
    cout << endl;
    k += i;
  }
}
void tryChange(int v, int val) {
  if (tree[v] > val) {
    tree[v] = val;
  }
}
void change(int v, int s, int e, int vs, int ve, int val) {
  if (e < vs || ve < s) return;
  if (s <= vs && ve <= e) {
    tryChange(v, val);
    return;
  }
  int split = (vs + ve) >> 1;
  change(L(v), s, e, vs, split, val);
  change(R(v), s, e, split + 1, ve, val);
}
int query(int v) {
  v += r;
  int ret = tree[v];
  while (v > 1) {
    v = P(v);
    ret = min(ret, tree[v]);
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, h, m;
  cin >> n >> h >> m;
  for (int i = 0; i < s; i++) {
    tree[i] = h;
  }
  int s, e, x;
  for (int i = 0; i < m; i++) {
    cin >> s >> e >> x;
    change(1, s, e, 0, r - 1, x);
  }
  int res = 0, q;
  for (int i = 1; i <= n; i++) {
    q = query(i);
    res += q * q;
  }
  cout << res << endl;
  return 0;
}
