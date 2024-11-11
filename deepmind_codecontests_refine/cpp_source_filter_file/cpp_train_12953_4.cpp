#include <bits/stdc++.h>
using namespace std;
const int MAXARR = 123456 + 5, MAXVAL = 1e6 + 5, MOD = 1e9 + 7,
          INF = 2147483647;
const long long INFLL = (1LL << 62);
template <class T>
void maximize(T &x, T y) {
  if (x < y) x = y;
}
template <class T>
void minimize(T &x, T y) {
  if (x > y) x = y;
}
struct ver {
  int x, lo, hi;
};
struct hor {
  int y, L, R;
};
struct data {
  int type, pos, low, high;
  data() {
    pos = 0;
    low = 0;
    high = 0;
  }
  data(int _type, int _pos, int _low, int _high) {
    type = _type;
    pos = _pos;
    low = _low;
    high = _high;
  }
  bool operator<(const data &other) const {
    return (pos < other.pos || (pos == other.pos && type > other.type));
  }
};
vector<ver> vertical;
vector<hor> horizontal;
vector<data> Y;
vector<int> cnt;
int n, m;
struct BIT {
  vector<int> t;
  void init(int num) { t.assign(num, 0); }
  void update(int pos, int val) {
    while (pos < t.size()) {
      t[pos] += val;
      pos += (pos & (-pos));
    }
  }
  int get(int pos) {
    int res = 0;
    while (pos) {
      res += t[pos];
      pos -= pos += (pos & (-pos));
    }
    return res;
  }
} tree;
int get(int l, int r) {
  if (l > r) return 0;
  return tree.get(r) - tree.get(l - 1);
}
void prepare(int num) {
  Y.clear();
  cnt.clear();
  for (int i = 1; i <= n; i++) {
    if (vertical[i].hi - num >= vertical[i].lo + num) {
      Y.push_back(data(1, vertical[i].lo + num, vertical[i].x, 1));
      Y.push_back(data(-1, vertical[i].hi - num, vertical[i].x, -1));
      cnt.push_back(vertical[i].x);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (horizontal[i].L + num <= horizontal[i].R - num) {
      Y.push_back(data(0, horizontal[i].y, horizontal[i].L + num,
                       horizontal[i].R - num));
    }
  }
  sort(Y.begin(), Y.end());
  sort(cnt.begin(), cnt.end());
  cnt.resize(unique(cnt.begin(), cnt.end()) - cnt.begin());
}
bool check(int num) {
  if (num == 0) return 1;
  prepare(num);
  tree.init(cnt.size() + 5);
  for (int i = 0; i < Y.size(); i++) {
    if (Y[i].type == 0) {
      int Low = lower_bound(cnt.begin(), cnt.end(), Y[i].low) - cnt.begin() + 1;
      int High = upper_bound(cnt.begin(), cnt.end(), Y[i].high) - cnt.begin();
      if (get(Low, High)) return 1;
    } else {
      int Low = lower_bound(cnt.begin(), cnt.end(), Y[i].low) - cnt.begin() + 1;
      tree.update(Low, Y[i].high);
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vertical.assign(n + 1, ver());
  for (int i = 1; i <= n; i++) {
    cin >> vertical[i].x >> vertical[i].lo >> vertical[i].hi;
    vertical[i].hi += vertical[i].lo;
  }
  horizontal.assign(m + 1, hor());
  for (int i = 1; i <= m; i++) {
    cin >> horizontal[i].L >> horizontal[i].y >> horizontal[i].R;
    horizontal[i].R += horizontal[i].L;
  }
  int hi = INF;
  int lo = 0;
  while (lo < hi) {
    int mid = (hi + lo) >> 1;
    if (check(mid))
      lo = mid;
    else
      hi = mid - 1;
    if (lo + 1 == hi) break;
  }
  while (check(lo)) lo++;
  cout << lo - 1;
  return 0;
}
