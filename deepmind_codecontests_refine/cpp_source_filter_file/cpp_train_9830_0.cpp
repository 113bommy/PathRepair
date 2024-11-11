#include <bits/stdc++.h>
using namespace std;
struct it {
  int o, c, x;
};
string s;
int n, q;
int res, cmp;
it t[4000040];
void init(int node, int l, int r) {
  if (l == r) {
    if (s[l] == '(')
      t[node].o = 1;
    else
      t[node].c = 1;
    return;
  }
  int mid = (l + r) / 2;
  init(node * 2, l, mid);
  init(node * 2 + 1, mid + 1, r);
  int p = min(t[node * 2].o, t[node * 2 + 1].c);
  t[node].x = t[node * 2].x + t[node * 2 + 1].x + p;
  t[node].o = t[node * 2].o + t[node * 2 + 1].o - p;
  t[node].c = t[node * 2].c + t[node * 2 + 1].c - p;
}
void query(int node, int l, int r, int u, int v) {
  if ((r < u) || (l > v)) return;
  if ((l >= u) && (r <= v)) {
    res += min(cmp, t[node].c) + t[node].x;
    cmp -= min(cmp, t[node].c);
    cmp += t[node].o;
    return;
  }
  int mid = (l + r) / 2;
  query(node * 2, l, mid, u, v);
  query(node * 2 + 1, mid + 1, r, u, v);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  int n = s.size();
  init(1, 0, n - 1);
  cin >> q;
  int l, r;
  for (int i = 1; i <= q; i++) {
    cin >> l >> r;
    res = 0;
    cmp = 0;
    query(1, 0, n - 1, l - 1, r - 1);
    cout << res * 2;
  }
  return 0;
}
