#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 100;
int t[4 * N];
vector<int> v;
void build(int node, int l, int r) {
  if (l == r)
    t[node] = v[l];
  else {
    int m = (l + r) / 2;
    build(node * 2, l, m);
    build(node * 2 + 1, m + 1, r);
    t[node] = max(t[node * 2], t[node * 2 + 1]);
  }
}
int get(int node, int tl, int tr, int l, int r) {
  if (l > tr || tl > r) return 0;
  if (l <= tl && tr <= r) return t[node];
  int tm = (tl + tr) / 2;
  return max(get(node * 2, tl, tm, l, r), get(node * 2 + 1, tm + 1, tr, l, r));
}
signed main() {
  cin.tie();
  cout.tie();
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  int ask[n];
  int id[n];
  for (int k = 0; k < n; ++k) {
    ask[k] = 0;
    id[k] = 0;
  }
  v.resize(m);
  for (int j = 0; j < m; ++j) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int p, x;
      cin >> p >> x;
      --p;
      ask[p] = x;
      v[j] = 0;
      id[p] = j;
    } else {
      int x;
      cin >> x;
      v[j] = x;
    }
  }
  build(1, 0, m - 1);
  for (int l = 0; l < n; ++l) {
    if (id[l] == 0)
      cout << max(a[l], get(1, 0, m - 1, id[l], m - 1)) << " ";
    else
      cout << max(ask[l], get(1, 0, m - 1, id[l], m - 1)) << " ";
  }
}
