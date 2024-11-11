#include <bits/stdc++.h>
using namespace std;
template <class V, int NV>
class SegTree_1 {
 public:
  vector<V> val;
  static V const def = 1 << 20;
  V comp(V l, V r) { return min(l, r); };
  SegTree_1() { val = vector<V>(NV * 2, def); };
  V getval(int x, int y, int l = 0, int r = NV, int k = 1) {
    if (r <= x || y <= l) return def;
    if (x <= l && r <= y) return val[k];
    return comp(getval(x, y, l, (l + r) / 2, k * 2),
                getval(x, y, (l + r) / 2, r, k * 2 + 1));
  }
  void update(int entry, V v) {
    entry += NV;
    val[entry] = v;
    while (entry > 1)
      entry >>= 1, val[entry] = comp(val[entry * 2], val[entry * 2 + 1]);
  }
};
int H, W, K, Q;
int X[202000], Y[202000];
int X1[202000], Y1[202000];
int X2[202000], Y2[202000];
int ok[202000];
vector<int> evR[210000], evQ[210000];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> W >> H >> K >> Q;
  for (i = 0; i < K; i++) cin >> X[i] >> Y[i];
  for (i = 0; i < Q; i++) cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
  for (r = 0; r < 2; r++) {
    SegTree_1<int, 1 << 20> miny;
    for (i = 0; i < 210000; i++) evR[i].clear(), evQ[i].clear();
    for (i = 0; i < K; i++) evR[Y[i]].push_back(i);
    for (i = 0; i < Q; i++) evQ[Y2[i]].push_back(i);
    for (i = 1; i <= W; i++) miny.update(X[r], -1);
    for (i = 1; i <= H; i++) {
      for (auto& r : evR[i]) miny.update(X[r], i);
      for (auto& r : evQ[i]) ok[r] |= miny.getval(X1[r], X2[r] + 1) >= Y1[r];
    }
    swap(W, H);
    for (i = 0; i < K; i++) swap(X[i], Y[i]);
    for (i = 0; i < Q; i++) swap(X1[i], Y1[i]);
    for (i = 0; i < Q; i++) swap(X2[i], Y2[i]);
  }
  for (i = 0; i < Q; i++) cout << (ok[i] ? "YES" : "NO") << endl;
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false);
  for (i = 0; i < argc - 1; i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < s.size(); i++) ungetc(s[s.size() - 1 - i], stdin);
  solve();
  return 0;
}
