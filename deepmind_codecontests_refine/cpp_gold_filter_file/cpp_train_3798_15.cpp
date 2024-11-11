#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXQ = 2e5 + 10;
struct nodeseg {
  int val;
  bool flag;
  nodeseg(int _val = 0, int _f = 0) {
    val = _val;
    flag = _f;
  }
  nodeseg operator+(nodeseg n) {
    nodeseg ans = nodeseg();
    if (flag && n.flag) {
      ans.flag = 1;
      return ans;
    }
    if (flag) {
      ans = n;
      return ans;
    }
    if (n.flag) {
      return *this;
    }
    ans.val = min(val, n.val);
    return ans;
  }
} seg[4 * MAXN], nullnode;
void build(int node, int x, int y) {
  if (x == y) {
    seg[node] = 0;
    return;
  }
  build(node << 1, x, ((x + y) >> 1) + 0);
  build((node << 1) + 1, ((x + y) >> 1) + 1, y);
  seg[node] = seg[node << 1] + seg[(node << 1) + 1];
}
void update(int node, int x, int y, int id, int val) {
  if (x > id || y < id) return;
  if (x == y) {
    seg[node] = val;
    return;
  }
  update(node << 1, x, ((x + y) >> 1) + 0, id, val);
  update((node << 1) + 1, ((x + y) >> 1) + 1, y, id, val);
  seg[node] = seg[node << 1] + seg[(node << 1) + 1];
}
nodeseg query(int node, int x, int y, int l, int r) {
  if (x > r || y < l) return nullnode;
  if (x >= l && y <= r) return seg[node];
  nodeseg e = query(node << 1, x, ((x + y) >> 1) + 0, l, r);
  nodeseg d = query((node << 1) + 1, ((x + y) >> 1) + 1, y, l, r);
  return e + d;
}
int n, m, q, k;
pair<int, int> rooks[MAXQ];
pair<pair<int, int>, pair<int, int> > areas[MAXQ];
struct eve1 {
  int id, isrook, x;
  eve1(int _id, int _isrook, int _x) {
    id = _id;
    isrook = _isrook;
    x = _x;
  }
  bool operator<(eve1 e) const {
    if (x != e.x) return x < e.x;
    return isrook > e.isrook;
  }
};
struct eve2 {
  int id, isrook, y;
  eve2(int _id, int _isrook, int _y) {
    id = _id;
    isrook = _isrook;
    y = _y;
  }
  bool operator<(eve2 e) const {
    if (y != e.y) return y < e.y;
    return isrook > e.isrook;
  }
};
int marc[MAXQ];
std::vector<eve1> line1;
std::vector<eve2> line2;
int main() {
  nullnode.flag = 1;
  scanf("%d %d %d %d", &n, &m, &k, &q);
  for (int i = 1; i <= k; i++) {
    int x, y;
    scanf("%d %d", &rooks[i].first, &rooks[i].second);
    line1.push_back(eve1(i, 1, rooks[i].first));
    line2.push_back(eve2(i, 1, rooks[i].second));
  }
  for (int i = 1; i <= q; i++) {
    scanf("%d %d %d %d", &areas[i].first.first, &areas[i].first.second,
          &areas[i].second.first, &areas[i].second.second);
    line1.push_back(eve1(i, 0, areas[i].second.first));
    line2.push_back(eve2(i, 0, areas[i].second.second));
  }
  sort(line1.begin(), line1.end());
  build(1, 1, m);
  for (int i = 0; i < line1.size(); i++) {
    eve1 e = line1[i];
    if (e.isrook)
      update(1, 1, m, rooks[e.id].second, e.x);
    else {
      int y1y = areas[e.id].first.second;
      int y2y = areas[e.id].second.second;
      if (query(1, 1, m, y1y, y2y).val >= areas[e.id].first.first) marc[e.id]++;
    }
  }
  sort(line2.begin(), line2.end());
  build(1, 1, n);
  for (int i = 0; i < line2.size(); i++) {
    eve2 e = line2[i];
    if (e.isrook)
      update(1, 1, n, rooks[e.id].first, e.y);
    else {
      int x1x = areas[e.id].first.first;
      int x2x = areas[e.id].second.first;
      if (query(1, 1, n, x1x, x2x).val >= areas[e.id].first.second)
        marc[e.id]++;
    }
  }
  for (int i = 1; i <= q; i++) {
    if (!marc[i]) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
}
