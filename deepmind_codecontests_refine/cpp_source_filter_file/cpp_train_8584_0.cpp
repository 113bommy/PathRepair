#include <bits/stdc++.h>
using namespace std;
namespace stuff {
const int LCM = 30;
struct Node {
  int take[LCM];
  int end[LCM];
};
const int MOD = 1000000007;
int per[111000];
Node tree[1 << 18];
vector<Node> nodes;
int L, R;
Node combine(const Node& lch, const Node& rch) {
  Node res;
  for (int st = 0; st < LCM; st++) {
    res.end[st] = rch.end[lch.end[st]];
    res.take[st] = lch.take[st] + rch.take[lch.end[st]];
  }
  return res;
}
void build(int at, int l, int r) {
  if (l == r) {
    for (int st = 0; st < LCM; st++) {
      if (st % per[l] == 0) {
        tree[at].take[st] = 2;
        tree[at].end[st] = (st + 2) % LCM;
      } else {
        tree[at].take[st] = 1;
        tree[at].end[st] = (st + 1) % LCM;
      }
    }
  } else {
    const int m = (l + r) >> 1;
    build(at + at, l, m);
    build(at + at + 1, m + 1, r);
    tree[at] = combine(tree[at + at], tree[at + at + 1]);
  }
}
void update(int at, int l, int r, int pos) {
  if (l == r) {
    for (int st = 0; st < LCM; st++) {
      if (st % per[l] == 0) {
        tree[at].take[st] = 2;
        tree[at].end[st] = (st + 2) % LCM;
      } else {
        tree[at].take[st] = 1;
        tree[at].end[st] = (st + 1) % LCM;
      }
    }
  } else {
    const int m = (l + r) >> 1;
    if (pos <= m)
      update(at + at, l, m, pos);
    else
      update(at + at + 1, m + 1, r, pos);
    tree[at] = combine(tree[at + at], tree[at + at + 1]);
  }
}
void query(int at, int l, int r) {
  if (L > r || R < l) return;
  if (L <= l && r <= R)
    nodes.push_back(tree[at]);
  else {
    const int m = (l + r) >> 1;
    query(at + at, l, m);
    query(at + at + 1, m + 1, r);
  }
}
void solve(int test_num) {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> per[i];
  build(1, 1, N);
  int Q;
  cin >> Q;
  while (Q-- > 0) {
    char type;
    cin >> skipws >> type;
    if (type == 'A') {
      cin >> L >> R;
      R--;
      nodes.clear();
      query(1, 1, N);
      Node res = nodes.front();
      for (int i = 1; i < (int)nodes.size(); i++) res = combine(res, nodes[i]);
      cout << res.take[0] << endl;
    } else {
      int pos, val;
      cin >> pos >> val;
      per[pos] = val;
      update(1, 1, N, pos);
    }
  }
}
void solve() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  for (int t = 1; t <= T; t++) solve(t);
}
}  // namespace stuff
int main() {
  stuff::solve();
  return 0;
}
