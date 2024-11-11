#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9;
struct SegTree {
  int mi[N << 2];
  void modify(int x, int l, int r, int qx, int qd) {
    if (l == r) {
      mi[x] = qd;
    } else {
      if (qx <= ((l + r) >> 1))
        modify((x << 1), l, ((l + r) >> 1), qx, qd);
      else
        modify((x << 1 | 1), ((l + r) >> 1) + 1, r, qx, qd);
      mi[x] = min(mi[(x << 1)], mi[(x << 1 | 1)]);
    }
  }
  int query(int x, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) {
      return mi[x];
    } else {
      int ans = INF;
      if (ql <= ((l + r) >> 1))
        ans = min(ans, query((x << 1), l, ((l + r) >> 1), ql, qr));
      if (qr > ((l + r) >> 1))
        ans = min(ans, query((x << 1 | 1), ((l + r) >> 1) + 1, r, ql, qr));
      return ans;
    }
  }
} dir[2];
pair<int, int> ans[N << 1];
string str[2] = {"YES", "NO"};
vector<pair<int, int> > p;
int len[2], k, q;
struct Query {
  pair<int, int> x, y;
  int id;
};
vector<Query> Q[2][N];
void work(int k) {
  for (int turn = 0; turn < int(2); turn++) {
    sort(p.begin(), p.end());
    int now = 0;
    for (int i = int(1); i <= int(len[turn]); i++) {
      while (now < k && p[now].first == i) {
        dir[turn].modify(1, 1, len[turn ^ 1], p[now++].second, i);
      }
      bool res = 0;
      for (auto q : Q[turn][i]) {
        if (turn) {
          res = dir[turn].query(1, 1, len[turn ^ 1], q.x.first, q.y.first) <
                q.x.second;
        } else {
          res = dir[turn].query(1, 1, len[turn ^ 1], q.x.second, q.y.second) <
                q.x.first;
        }
        if (turn)
          ans[q.id].second = res;
        else
          ans[q.id].first = res;
      }
    }
    for (int i = 0; i < int(p.size()); i++) {
      swap(p[i].first, p[i].second);
    }
  }
}
int main() {
  ios ::sync_with_stdio(0);
  cin >> len[0] >> len[1] >> k >> q;
  for (int i = 0; i < int(k); i++) {
    int x, y;
    cin >> x >> y;
    p.push_back({x, y});
  }
  for (int i = 0; i < int(q); i++) {
    int x, y, z, w;
    cin >> x >> y >> z >> w;
    Query tmp = {{x, y}, {z, w}, i};
    Q[0][z].push_back(tmp);
    Q[1][w].push_back(tmp);
  }
  work(k);
  for (int i = 0; i < int(q); i++) {
    cout << str[ans[i].first & ans[i].second] << endl;
  }
  return 0;
}
