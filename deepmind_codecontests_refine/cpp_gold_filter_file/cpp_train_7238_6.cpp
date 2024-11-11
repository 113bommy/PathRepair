#include <bits/stdc++.h>
using namespace std;
template <typename t>
t in(t q) {
  cin >> q;
  return q;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < ((int)size(v)); ++i) {
    os << v[i];
    if (i != ((int)size(v)) - 1) os << ",";
  }
  os << "]";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  for (auto it : v) os << "(" << it.first << ":" << it.second << ")";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(" << v.first << "," << v.second << ")";
  return os;
}
const long double PI = acosl(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
inline int rand(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}
inline long long rand(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
int p;
int i;
int xw, yw;
long long ans = 0;
int x, y, m, j;
bool s1, s2;
int n, k;
struct node;
node* last;
struct node {
  int sum;
  node *lft, *rht;
  node() {
    sum = 0;
    lft = NULL;
    rht = NULL;
  }
  int query(int l) {
    if (l == 2) return sum;
    if (l) {
      if (!rht) rht = new node();
      last = rht;
      if (!lft) return 0;
      return lft->sum;
    }
    if (!lft) lft = new node();
    last = lft;
    if (!rht) return 0;
    return rht->sum;
  }
  void update(int l, int r) {
    if (l == r) {
      sum++;
      return;
    }
    int mid = (l + r) / 2;
    if (xw <= mid) {
      if (!lft) lft = new node();
      lft->update(l, mid);
    } else {
      if (!rht) rht = new node();
      rht->update(mid + 1, r);
    }
    sum++;
  }
};
node* r = new node();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(10);
  cin >> n >> k;
  xw = 0;
  r->update(0, 1073741823);
  for (i = 1; i < n + 1; ++i) {
    cin >> p;
    last = r;
    p ^= xw;
    x = 0;
    y = 1073741823;
    for (j = 29; j >= 0; --j) {
      s1 = ((1 << j) & k);
      s2 = (1 << j) & p;
      m = (x + y) / 2;
      if (s1 && s2) {
        y = m;
        if (!last->lft) break;
        last = last->lft;
      } else if (s1 && !s2) {
        x = m + 1;
        if (!last->rht) break;
        last = last->rht;
      } else if (s2) {
        xw = x;
        yw = m;
        ans += last->query(1);
        x = m + 1;
      } else {
        xw = m + 1;
        yw = y;
        ans += last->query(0);
        y = m;
      }
    }
    xw = x;
    yw = y;
    if (j == -1) ans += last->query(2);
    xw = p;
    r->update(0, 1073741823);
  }
  cout << ans;
  return 0;
}
