#include <bits/stdc++.h>
using namespace std;
struct Rectangle {
  int x1, y1, x2, y2, idx;
  Rectangle(int _x1, int _y1, int _x2, int _y2, int _idx) {
    x1 = _x1;
    y1 = _y1;
    x2 = _x2;
    y2 = _y2;
    idx = _idx;
  }
};
const int MX = 1e5 + 5;
const int INF = 1e9;
int n, m, k, q, tree[4 * MX], ans[2 * MX];
vector<pair<int, int> > rooks;
vector<Rectangle> rects;
int query(int l, int r) {
  int res = INF;
  for (l += MX, r += MX; l < r; l /= 2, r /= 2) {
    if (l & 1) res = min(res, tree[l++]);
    if (r & 1) res = min(res, tree[--r]);
  }
  return res;
}
void modify(int pos, int val) {
  pos += MX;
  for (tree[pos] = val; pos > 1; pos /= 2) {
    tree[pos / 2] = min(tree[pos], tree[pos ^ 1]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 0; i < k; i++) {
    int x1, y1;
    scanf("%d%d", &x1, &y1);
    x1--;
    y1--;
    rooks.push_back({x1, y1});
  }
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1--;
    y1--;
    x2--;
    y2--;
    rects.push_back(Rectangle(x1, y1, x2, y2, i));
  }
  sort(rects.begin(), rects.end(),
       [](Rectangle r1, Rectangle r2) { return r1.x2 < r2.x2; });
  sort(rooks.begin(), rooks.end(), [](pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
  });
  int ptr = 0, rp = 0;
  for (int i = 0; i < MX; i++) modify(i, -1);
  for (int i = 0; i < n; i++) {
    while (rp < k && rooks[rp].first == i) {
      modify(rooks[rp].second, i);
      rp++;
    }
    while (ptr < q && rects[ptr].x2 == i) {
      int mnm = query(rects[ptr].y1, rects[ptr].y2 + 1);
      if (mnm >= rects[ptr].x1) ans[rects[ptr].idx] = 1;
      ptr++;
    }
  }
  for (int i = 0; i < MX; i++) modify(i, -1);
  rp = 0;
  ptr = 0;
  sort(rects.begin(), rects.end(),
       [](Rectangle r1, Rectangle r2) { return r1.y2 < r2.y2; });
  sort(rooks.begin(), rooks.end(), [](pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
  });
  for (int i = 0; i < m; i++) {
    while (rp < k && rooks[rp].second == i) {
      modify(rooks[rp].first, i);
      rp++;
    }
    while (ptr < q && rects[ptr].y2 == i) {
      int mnm = query(rects[ptr].x1, rects[ptr].x2 + 1);
      if (mnm >= rects[ptr].y1) ans[rects[ptr].idx] = 1;
      ptr++;
    }
  }
  for (int i = 0; i < q; i++) {
    if (ans[i])
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
