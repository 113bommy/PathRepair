#include <bits/stdc++.h>
using namespace std;
void make_op(vector<int> &x, vector<pair<int, int> > &ans, int i, int j) {
  x[i] ^= x[j];
  ans.emplace_back(i, j);
}
void make_swap(vector<int> &x, vector<pair<int, int> > &ans, int i, int j) {
  if (i == j) return;
  make_op(x, ans, i, j);
  make_op(x, ans, j, i);
  make_op(x, ans, i, j);
}
int make_iter(vector<int> &x, vector<pair<int, int> > &ans, int pos,
              const int n) {
  int mid = int(max_element(x.begin() + pos, x.end()) - x.begin());
  make_swap(x, ans, mid, pos);
  if (x[pos] == 0) return -1;
  int bit = 31 - __builtin_clz(x[pos]);
  for (int j = 0; j < n; ++j) {
    if (j != pos && (x[j] & (1 << bit))) {
      make_op(x, ans, j, pos);
    }
  }
  return bit;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> xs(n), ys(n);
  for (int &x : xs) cin >> x;
  for (int &x : ys) cin >> x;
  vector<pair<int, int> > ans1, ans2;
  for (int _n(n), i(0); i < _n; i++) {
    int b1 = make_iter(xs, ans1, i, n);
    int b2 = make_iter(ys, ans2, i, n);
    if (b1 == -1 && b2 == -1) break;
    if (b1 == b2) continue;
    if (b2 > b1) {
      cout << -1 << endl;
      return 0;
    }
    for (int _n(i), j(0); j < _n; j++) {
      if (ys[j] & (1 << b1)) {
        make_op(xs, ans1, j, i);
      }
    }
    make_op(xs, ans1, i, i);
    --i;
  }
  if (xs != ys) {
    cout << -1 << endl;
    return 0;
  }
  ans1.insert(ans1.end(), ans2.rbegin(), ans2.rend());
  cout << ans1.size() << endl;
  for (auto el : ans1) cout << el.first + 1 << " " << el.second + 1 << endl;
  return 0;
}
