#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return {i, j};
}
struct printer {
  ~printer() { cerr << endl; }
  template <class c>
  printer& operator,(c x) {
    cerr << boolalpha << x;
    return *this;
  }
  printer& operator,(string x) {
    cerr << x;
    return *this;
  }
  template <class c, class d>
  printer& operator,(pair<c, d> x) {
    return *this, "(", x.first, ", ", x.second, ")";
  }
  template <class... d, template <class...> class c>
  printer& operator,(c<d...> x) {
    return *this, range(begin(x), end(x));
  }
  template <class c>
  printer& operator,(rge<c> x) {
    *this, "[";
    for (auto it = x.b; it != x.e; ++it) *this, (it == x.b ? "" : ", "), *it;
    return *this, "]";
  }
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
const int N = 3e5 + 100;
int to[N * 30][2];
int cnt[N * 30];
int tot = 1;
int calc[30][2][2];
void add(int x) {
  int cur = 1;
  for (int k = 29; k >= 0; k--) {
    int d = (x >> k) & 1;
    if (to[cur][d] == 0) {
      to[cur][d] = ++tot;
    }
    calc[k][d ^ 1][d] += cnt[to[cur][d ^ 1]];
    cur = to[cur][d];
  }
  cur = 1;
  cnt[1]++;
  for (int k = 29; k >= 0; k--) {
    int d = (x >> k) & 1;
    cur = to[cur][d];
    cnt[cur]++;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    add(x);
  }
  long long inv = 0;
  int mask = 0;
  for (int k = 29; k >= 0; k--) {
    if (calc[k][0][1] >= calc[k][1][0]) {
      inv += calc[k][1][0];
    } else {
      mask |= (1 << k);
      inv += calc[k][0][1];
    }
  }
  cout << inv << " " << mask << endl;
}
