#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10, MOD = 1e9 + 7;
struct basis {
  static constexpr int D = 50;
  long long base[D] = {};
  long long who[D] = {};
  void add(long long x, long long me) {
    for (int i = 0; i < D; i++)
      if ((x >> i) & 1) {
        if (!base[i]) {
          base[i] = x;
          who[i] = me;
          return;
        }
        x ^= base[i];
        me ^= who[i];
      }
  }
  long long contains(long long x) {
    long long me = 0;
    for (int i = 0; i < D; i++)
      if ((x >> i) & 1) {
        if (!base[i]) return -1;
        x ^= base[i];
        me ^= who[i];
      }
    return me;
  }
};
const int LEFT = basis::D;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& c : a) cin >> c;
  vector<array<int, 3>> ans;
  auto op = [&](int i, int j, int k) {
    a[i] ^= 1, a[j] ^= 1, a[k] ^= 1;
    ans.push_back({i, j, k});
  };
  while (int(a.size()) > LEFT) {
    int l = int(a.size()) - 6, r = int(a.size()) - 1;
    vector<array<long long, 3>> cur;
    auto add = [&](int i, int dist) {
      int prv = i - dist, nxt = i + dist;
      if (nxt > r || nxt < l) return 0;
      long long cur_mask = 0;
      if (i >= l) cur_mask ^= 1ll << (i - l);
      if (prv >= l) cur_mask ^= 1ll << (prv - l);
      cur_mask ^= 1ll << (nxt - l);
      cur.push_back({cur_mask, i, dist});
      return 1;
    };
    for (int i = l; i <= r; i++) {
      int mid = l - 1;
      add(mid, i - mid);
      for (int dist = 1;; dist++) {
        if (!add(i, dist)) break;
      }
    }
    vector<int> choose;
    long long my_mask = 0;
    for (int i = l; i <= r; i++)
      if (a[i]) my_mask ^= 1ll << (i - l);
    for (int i = 0; i < int(cur.size()); i++)
      for (int j = i + 1; j < int(cur.size()); j++) {
        if ((cur[i][0] ^ cur[j][0]) == my_mask) choose = {i, j};
      }
    for (int i = 0; i < int(cur.size()); i++)
      if (cur[i][0] == my_mask) choose = {i};
    for (int i : choose) {
      int mid = cur[i][1], dist = cur[i][2];
      op(mid - dist, mid, mid + dist);
    }
    for (int rep = 0; rep < 6; rep++) {
      assert(a.back() == 0);
      a.pop_back();
    }
  }
  int l = 0, r = int(a.size()) - 1;
  basis b;
  vector<array<int, 2>> cur;
  for (int i = l; i <= r; i++)
    for (int dist = 1;; dist++) {
      int prv = i - dist, nxt = i + dist;
      if (nxt > r || prv < l) break;
      long long cur_mask = 1ll << (i - l);
      if (prv >= l) cur_mask ^= 1ll << (prv - l);
      if (prv <= r) cur_mask ^= 1ll << (nxt - l);
      b.add(cur_mask, 1ll << int(cur.size()));
      cur.push_back({i, dist});
    }
  long long my_mask = 0;
  for (int i = l; i <= r; i++)
    if (a[i]) my_mask ^= 1ll << (i - l);
  long long chose = b.contains(my_mask);
  if (chose == -1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int i = 0; i < int(cur.size()); i++)
    if ((chose >> i) & 1) {
      int mid = cur[i][0], dist = cur[i][1];
      op(mid - dist, mid, mid + dist);
    }
  cout << int(ans.size()) << '\n';
  for (auto c : ans)
    cout << c[0] + 1 << ' ' << c[1] + 1 << ' ' << c[2] + 1 << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) solve();
}
