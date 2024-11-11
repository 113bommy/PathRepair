#include <bits/stdc++.h>
using namespace std;
class FTree {
 public:
  vector<int> t;
  int n;
  void Init(int n) {
    this->n = n;
    t.assign(n, 0);
  }
  void Inc(int val, int pos) {
    for (int k = pos; k < n; k = (k | (k + 1))) t[k] += val;
  }
  int Sum(int r) {
    int res = 0;
    for (int k = r; k > 0; k = (k & (k + 1)) - 1) res += t[k];
    return res;
  }
  int Sum(int l, int r) { return Sum(r) - Sum(l - 1); }
};
class Game {
 public:
  FTree t[3];
  set<int> s[3];
  vector<int> a;
  int n, q;
  void Update(int val, int pos) {
    if (a[pos] != -1) {
      t[a[pos]].Inc(-1, pos);
      s[a[pos]].erase(pos);
    }
    t[val].Inc(1, pos);
    s[val].insert(pos);
    a[pos] = val;
  }
  Game() {
    cin >> n >> q;
    for (int i = 0; i < int(3); i++) t[i].Init(n);
    a.assign(n, -1);
    for (int i = 0; i < int(n); i++) {
      char c;
      cin >> c;
      if (c == 'R')
        Update(0, i);
      else if (c == 'P')
        Update(1, i);
      else if (c == 'S')
        Update(2, i);
    }
  }
  int Query(int val) {
    int P = val, R = (val + 2) % 3, S = (val + 1) % 3;
    int res = s[P].size();
    if (s[S].size() == 0) return res;
    if (s[R].size() == 0) return 0;
    int rmn = *s[R].begin(), smn = *s[S].begin(), rmx = *(--s[R].end()),
        smx = *(--s[S].end());
    if (smn < rmn) res -= t[P].Sum(smn, rmn);
    if (smx > rmx) res -= t[P].Sum(rmx, smx);
    return res;
  }
  int Query() {
    int res = 0;
    for (int i = 0; i < int(3); i++) res += Query(i);
    return res;
  }
  void Solve() {
    cout << Query() << endl;
    for (int i = 0; i < int(q); i++) {
      int pos;
      char c;
      cin >> pos;
      pos--;
      cin.get();
      cin >> c;
      if (c == 'R')
        Update(0, pos);
      else if (c == 'P')
        Update(1, pos);
      else if (c == 'S')
        Update(2, pos);
      cout << Query() << endl;
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Game g;
  g.Solve();
}
