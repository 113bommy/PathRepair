#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const int NEGATIVE_INF = -INF;
const int MAXN = 1010;
struct Node {
  long long v, e;
  Node(long long _v = 0, long long _e = 0) {
    v = _v;
    e = _e;
  }
};
long long h, q;
string order;
map<long long, long long> my_map;
map<long long, long long> my_map2;
pair<long long, pair<long long, long long> > calc(long long i) {
  long long self, left, right;
  if (my_map2.count(i) != 0)
    self = my_map2[i];
  else
    self = 0;
  if (my_map.count(2 * i) != 0)
    left = my_map[2 * i];
  else
    left = 0;
  if (my_map.count(2 * i + 1) != 0)
    right = my_map[2 * i + 1];
  else
    right = 0;
  return make_pair(self, make_pair(left, right));
}
void add_map(long long v, long long e) {
  my_map2[v] += e;
  while (v >= 1) {
    my_map[v] += e;
    v /= 2;
  }
}
void solve() {
  long long depth = 1, root = 1;
  long long max_t = 0;
  long double ans = 0.0, tp = 0.5;
  while (true) {
    pair<long long, pair<long long, long long> > info = calc(root);
    long long self = info.first;
    long long left = info.second.first, right = info.second.second;
    if (depth == h + 1) {
      ans += 2. * tp * max(max_t, self);
      break;
    }
    if (self + left > right) {
      ans += tp * max(max_t, self + left);
      max_t = max(max_t, self + right);
      root = 2 * root;
    }
    if (self + right > left) {
      ans += tp * max(max_t, self + right);
      max_t = max(max_t, self + left);
      root = root * 2 + 1;
    }
    tp /= 2;
    depth++;
    if (self + right > left && self + left > right) break;
  }
  cout << fixed << setprecision(12);
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin >> h >> q;
  long long v, e;
  while (q--) {
    cin >> order;
    if (order[0] == 'a') {
      cin >> v >> e;
      add_map(v, e);
    } else
      solve();
  }
  return 0;
}
