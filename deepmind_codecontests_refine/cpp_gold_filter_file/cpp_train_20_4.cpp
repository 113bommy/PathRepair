#include <bits/stdc++.h>
using namespace std;
const long long int infinity = 9e18;
pair<long long int, long long int> t1[4 * 200005] = {};
pair<long long int, long long int> t2[4 * 200005] = {};
struct SegmentTree {
  void update(pair<long long int, long long int> t[], int v, int tl, int tr,
              int pos, int x) {
    if (tl == tr) {
      t[v].first += x;
      t[v].second += 1;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        update(t, 2 * v, tl, tm, pos, x);
      else
        update(t, 2 * v + 1, tm + 1, tr, pos, x);
      t[v].first = (t[2 * v].first + t[2 * v + 1].first);
      t[v].second = (t[2 * v].second + t[2 * v + 1].second);
    }
  }
  pair<long long int, long long int> query(
      pair<long long int, long long int> t[], int v, int tl, int tr, int l,
      int r) {
    if (l > r) return {0, 0};
    if (tl == l && tr == r) {
      return t[v];
    } else {
      int tm = (tl + tr) / 2;
      pair<long long int, long long int> left =
          query(t, 2 * v, tl, tm, l, min(tm, r));
      pair<long long int, long long int> right =
          query(t, 2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
      pair<long long int, long long int> p;
      p.first = left.first + right.first;
      p.second = left.second + right.second;
      return p;
    }
  }
};
long long int func(vector<pair<long long int, long long int> > &vp,
                   pair<long long int, long long int> t[]) {
  long long int n = vp.size();
  set<long long int> s;
  for (auto i : vp) {
    s.insert(i.second);
  }
  long long int speed = 0;
  map<long long int, long long int> m;
  for (auto i : s) {
    m[i] = speed++;
  }
  for (int i = 0; i < n; i++) {
    vp[i].second = m[vp[i].second];
  }
  SegmentTree st;
  long long int total = 0;
  for (int i = 0; i < n; i++) {
    pair<long long int, long long int> p =
        st.query(t, 1, 0, n - 1, 0, vp[i].second);
    total = total + (vp[i].first) * p.second - p.first;
    st.update(t, 1, 0, n - 1, vp[i].second, vp[i].first);
  }
  return total;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  vector<pair<long long int, long long int> > vp(n);
  for (int i = 0; i < n; i++) {
    cin >> vp[i].first;
  }
  for (int i = 0; i < n; i++) {
    cin >> vp[i].second;
  }
  sort(vp.begin(), vp.end());
  vector<pair<long long int, long long int> > pos, neg;
  long long int sum = 0;
  long long int total = 0;
  long long int count = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (vp[i].second >= 0) {
      sum += vp[i].first;
      count++;
      pos.push_back({vp[i].first, vp[i].second});
    } else {
      total = total + sum - vp[i].first * count;
      neg.push_back({vp[i].first, vp[i].second});
    }
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  total = total + func(pos, t1) + func(neg, t2);
  cout << total;
  return 0;
}
