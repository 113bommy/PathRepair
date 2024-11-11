#include <bits/stdc++.h>
const int OPEN = 0;
const int CLOSE = 1;
const int N = 200005;
const int LIM = N >> 1;
using namespace std;
struct event {
  int x, l, r, id;
  int y;
  bool isRook;
  event(int _x, int _y) {
    x = _x;
    y = _y;
    isRook = 1;
  }
  event(int _x, int _l, int _r, int _id) {
    x = _x;
    l = _l;
    r = _r;
    id = _id;
    isRook = 0;
  }
  bool operator<(const event &that) const {
    if (x != that.x) return x < that.x;
    if (isRook != that.isRook) return isRook;
    return id < that.id;
  }
};
struct rect {
  int x1, y1, x2, y2;
};
struct node {
  int l, r, minV;
  node *left, *right;
  node(int _l, int _r) {
    l = _l;
    r = _r;
    minV = 0;
    left = right = NULL;
  }
  void pushDown() {
    if (l != r && left == NULL) {
      left = new node(l, l + r >> 1);
      right = new node((l + r >> 1) + 1, r);
    }
  }
  void update(int i, int v) {
    pushDown();
    if (r < i || i < l) return;
    if (l == r) {
      minV = v;
      return;
    }
    left->update(i, v);
    right->update(i, v);
    minV = min(left->minV, right->minV);
  }
  int getMin(int i, int j) {
    pushDown();
    if (r < i || j < l) return N;
    if (i <= l && r <= j) return minV;
    return min(left->getMin(i, j), right->getMin(i, j));
  }
};
vector<event> E;
int nRook, nSite, n, m;
pair<int, int> rook[N];
bool row[N], col[N];
rect site[N];
void solve(bool chk[]) {
  E.clear();
  for (int i = (0); i < (nRook); ++i) {
    E.push_back(event(rook[i].first, rook[i].second));
  }
  for (int i = (0); i < (nSite); ++i) {
    E.push_back(event(site[i].x2, site[i].y1, site[i].y2, i));
  }
  sort(E.begin(), E.end());
  node *root = new node(1, LIM);
  for (__typeof(E.begin()) it = E.begin(); it != E.end(); ++it) {
    int x = it->x;
    bool isRook = it->isRook;
    if (isRook) {
      root->update(it->y, x);
    } else {
      int limit = site[it->id].x1;
      chk[it->id] = root->getMin(it->l, it->r) >= limit;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> nRook >> nSite;
  for (int i = (0); i < (nRook); ++i) {
    cin >> rook[i].first >> rook[i].second;
  }
  for (int i = (0); i < (nSite); ++i) {
    cin >> site[i].x1 >> site[i].y1 >> site[i].x2 >> site[i].y2;
  }
  solve(row);
  for (int i = (0); i < (nRook); ++i) swap(rook[i].first, rook[i].second);
  for (int i = (0); i < (nSite); ++i) {
    swap(site[i].x1, site[i].y1);
    swap(site[i].x2, site[i].y2);
  }
  solve(col);
  for (int i = (0); i < (nRook); ++i)
    if (row[i] || col[i])
      cout << "YES\n";
    else
      cout << "NO\n";
  return 0;
}
