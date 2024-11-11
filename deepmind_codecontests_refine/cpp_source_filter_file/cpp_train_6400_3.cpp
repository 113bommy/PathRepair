#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4")
using namespace std;
const int MAX_N = 11;
const long long MOD = 1000000007;
const long long INF = 1e18;
template <class T, int size>
class SegTree {
  int v = size;
  T segtree[4 * size + 1];
  void update(int idx, int l, int r, int i, T val) {
    if (l == r)
      segtree[idx] = val;
    else {
      int m = (l + r) / 2;
      if (i <= m)
        update(2 * idx, l, m, i, val);
      else
        update(2 * idx + 1, m + 1, r, i, val);
      segtree[idx] = min(segtree[2 * idx], segtree[2 * idx + 1]);
    }
  }
  T query(int idx, int l, int r, int lhs, int rhs) {
    if (r < lhs || l > rhs) return MAX_N;
    if (l >= lhs && r <= rhs) return segtree[idx];
    int m = (l + r) / 2;
    return min(query(2 * idx, l, m, lhs, rhs),
               query(2 * idx + 1, m + 1, r, lhs, rhs));
  }

 public:
  SegTree<T, size>() {
    for (int i = (0); i < (4 * v + 1); i++) segtree[i] = MAX_N;
  }
  inline void update(int i, int val) { update(1, 0, v - 1, i, val); }
  inline T query(int l, int r) { return query(1, 0, v - 1, l, r); }
};
int n, q;
int arr[MAX_N];
SegTree<int, MAX_N> bit;
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for (int i = (0); i < (n); i++) cin >> arr[i];
  set<int> cc;
  for (int i = (0); i < (n); i++) cc.insert(arr[i]);
  vector<int> last(n, -1), type(n);
  vector<pair<int, int>> pairs;
  map<int, int> mp;
  int cnt = 0;
  for (auto x : cc) mp.insert({x, cnt++});
  for (int i = (0); i < (n); i++) type[i] = mp[arr[i]];
  for (int i = (0); i < (n); i++) {
    if (~last[type[i]]) pairs.push_back({i, last[type[i]]});
    last[type[i]] = i;
  }
  sort(pairs.begin(), pairs.end());
  vector<pair<pair<int, int>, int>> qry(q);
  for (int i = (0); i < (q); i++) {
    cin >> qry[i].first.second >> qry[i].first.first;
    qry[i].first.second--, qry[i].first.first--;
    qry[i].second = i;
  }
  sort(qry.begin(), qry.end());
  int curr = 0, curr2 = 0;
  vector<int> ans(q);
  for (int i = (0); i < (n); i++) {
    while (curr2 < pairs.size()) {
      if (pairs[curr2].first > i) break;
      bit.update(pairs[curr2].second, pairs[curr2].first - pairs[curr2].second);
      curr2++;
    }
    while (curr < q) {
      if (qry[curr].first.first > i) break;
      ans[qry[curr].second] = bit.query(qry[curr].first.second, MAX_N);
      curr++;
    }
  }
  for (int i = (0); i < (q); i++) {
    if (ans[i] != MAX_N)
      cout << ans[i] << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}
