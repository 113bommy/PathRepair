#include <bits/stdc++.h>
using namespace std;
struct Stree {
  vector<int> data;
  vector<bool> lazy;
  int size;
  Stree(int nsize) {
    size = 1;
    while (size < nsize) size *= 2;
    data.resize(size * 2, 0);
    lazy.resize(size * 2, 0);
  }
  void propagate(int pos, int lb, int rb) {
    if (lazy[pos]) {
      lazy[pos] = false;
      data[pos] = rb - lb - data[pos];
      if (pos < size) {
        lazy[pos * 2] = !lazy[pos * 2];
        lazy[pos * 2 + 1] = !lazy[pos * 2 + 1];
      }
    }
  }
  void set(int l, int r, int pos = 1, int lb = 0, int rb = -1) {
    if (rb == -1) rb = size;
    propagate(pos, lb, rb);
    if (rb <= l || r <= lb) return;
    if (l <= lb && rb <= r) {
      lazy[pos] = !lazy[pos];
      propagate(pos, lb, rb);
      return;
    }
    int mid = (lb + rb) / 2;
    set(l, r, pos * 2, lb, mid);
    set(l, r, pos * 2 + 1, mid, rb);
    data[pos] = data[pos * 2] + data[pos * 2 + 1];
  }
  int get(int l, int r, int pos = 1, int lb = 0, int rb = -1) {
    if (rb == -1) rb = size;
    propagate(pos, lb, rb);
    if (rb <= l || r <= lb) return 0;
    if (l <= lb && rb <= r) return data[pos];
    int mid = (lb + rb) / 2;
    return get(l, r, pos * 2, lb, mid) + get(l, r, pos * 2 + 1, mid, rb);
  }
};
bool byFirst(pair<int, int> l, pair<int, int> r) { return l.first < r.first; }
bool bySecond(pair<int, int> l, pair<int, int> r) {
  return l.second < r.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> second(n);
  for (int i = 0; i < n; i++) cin >> second[i];
  sort(second.begin(), second.end());
  vector<pair<int, int> > op;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a = lower_bound(second.begin(), second.end(), a) - second.begin();
    b = upper_bound(second.begin(), second.end(), b) - second.begin();
    if (a != b) op.push_back(make_pair(a, b));
  }
  vector<int> wins(n, 0);
  for (int side = 0; side < 2; side++) {
    vector<pair<int, int> > toAdd = op, toRemove = op;
    Stree st(n);
    if (side) {
      for (auto &c : toAdd) c = make_pair(n - c.second, n - c.first);
      for (auto &c : toRemove) c = make_pair(n - c.second, n - c.first);
    } else
      st.set(0, n);
    sort(toAdd.begin(), toAdd.end(), byFirst);
    sort(toRemove.begin(), toRemove.end(), bySecond);
    int ai = 0, ri = 0;
    for (int i = 0; i < n; i++) {
      while (ai < (int)toAdd.size() && toAdd[ai].first <= i) {
        st.set(toAdd[ai].first, toAdd[ai].second);
        ai++;
      }
      while (ri < (int)toRemove.size() && toRemove[ri].second <= i) {
        st.set(toRemove[ri].first, toRemove[ri].second);
        ri++;
      }
      if (side)
        wins[n - i - 1] += st.get(0, i);
      else
        wins[i] += st.get(0, i);
    }
  }
  long long result = 0;
  for (auto c : wins) result += 1LL * c * (c - 1) / 2;
  cout << 1LL * n * (n - 1) * (n - 2) / 6 - result << '\n';
  return 0;
}
