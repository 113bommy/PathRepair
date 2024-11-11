#include <bits/stdc++.h>
using namespace std;
struct q {
  int l, r;
  q(int l, int r) : l(l), r(r) {}
};
bool operator<(q l, q r) {
  if (l.l == r.l) return l.r > r.r;
  return l.l < r.l;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n + 1, 0);
  vector<q> q0;
  vector<bool> grow(n + 1, false);
  int t;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> t >> l >> r;
    if (t == 0) {
      q0.push_back(q(l, r));
    } else {
      for (int j = l + 1; j <= r; j++) grow[j] = 1;
    }
  }
  for (int i = 0; i < q0.size(); i++) {
    bool t = true;
    for (int j = q0[i].l; j <= q0[i].r; j++)
      if (grow[j] == 0) {
        t = false;
        break;
      }
    if (t) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES\n";
  int k = 5000;
  for (int i = 1; i <= n; i++) {
    if (grow[i] == 0) k--;
    cout << k << " ";
  }
  return 0;
}
