#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535897;
const int mod = 1000000007LL;
const int INF = 1e9;
vector<int> ma;
struct SegmentTree {
  vector<int> ta;
  SegmentTree *left, *right;
  int l, r;
  SegmentTree(int tl, int tr) {
    l = tl;
    r = tr;
    ta = vector<int>(ma.begin() + l, ma.begin() + r + 1);
    sort((ta).begin(), (ta).end());
    if (l != r) {
      int m = (l + r) / 2;
      left = new SegmentTree(l, m);
      right = new SegmentTree(m + 1, r);
    }
  }
  int get(int tl, int tr, int x) {
    if (tr < l || r < tl || r < l) return 0;
    if (tl == l && tr == r) {
      return lower_bound((ta).begin(), (ta).end(), x) - ta.begin();
    }
    int m = (l + r) / 2;
    if (m < tl) return right->get(tl, tr, x);
    if (m > tr) return left->get(tl, tr, x);
    return left->get(max(l, tl), min(m, tr), x) +
           right->get(max(m + 1, tl), min(tr, r), x);
  }
};
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  map<int, int> sa;
  vector<int> b(n), o(n);
  for (int i = 0; i < n; i++) {
    sa[a[i]]++;
    b[i] = sa[a[i]];
  }
  sa.clear();
  for (int i = n - 1; i >= 0; i--) {
    sa[a[i]]++;
    o[i] = sa[a[i]];
  }
  ma = o;
  SegmentTree st(0, n - 1);
  long long jv = 0;
  for (int i = 0; i < n - 1; i++) {
    jv += st.get(i + 1, n - 1, b[i]);
  }
  cout << jv << "\n";
  return 0;
}
