#include <bits/stdc++.h>
using namespace std;
const char yes[] = "YES";
const char no[] = "NO";
class SegmentTree {
 private:
  vector<int> tree;
  int n;
  void assign(int i, int l, int r, int x, int v) {
    if (l == r) {
      tree[i] = v;
      return;
    }
    int m = (l + r) >> 1;
    if (x > m)
      assign(2 * i + 1, m + 1, r, x, v);
    else
      assign(2 * i, l, m, x, v);
    tree[i] = max(tree[2 * i], tree[2 * i + 1]);
  }
  int getMax(int i, int l, int r, int u, int v) const {
    if (l > v || r < u || l > r || v < u) return (0);
    if (u <= l && r <= v) return (tree[i]);
    int m = (l + r) >> 1;
    int L = getMax(2 * i, l, m, u, v);
    int R = getMax(2 * i + 1, m + 1, r, u, v);
    return (max(L, R));
  }

 public:
  SegmentTree() { n = 0; }
  SegmentTree(int n) {
    this->n = n;
    tree.assign(4 * n + 7, 0);
  }
  void assign(int x, int v) { assign(1, 1, n, x, v); }
  int getMax(int l, int r) const { return (getMax(1, 1, n, l, r)); }
};
struct Query {
  int top, bot, left, right, id;
  Query() { top = bot = left = right = id = 0; }
  void input(int id) {
    this->id = id;
    scanf("%d%d%d%d", &top, &left, &bot, &right);
  }
};
bool CompLeft(const Query &a, const Query &b) { return (a.left < b.left); }
bool CompTop(const Query &a, const Query &b) { return (a.top < b.top); }
int m, n, p, q;
Query query[200200];
bool answer[200200];
pair<int, int> rook[200200];
priority_queue<int, vector<int>, greater<int> > atRow[200200], atCol[200200];
void init(void) {
  scanf("%d%d%d%d", &m, &n, &p, &q);
  for (int i = (1), _b = (p); i <= _b; i = i + 1)
    scanf("%d%d", &rook[i].first, &rook[i].second);
  for (int i = (1), _b = (q); i <= _b; i = i + 1) query[i].input(i);
}
bool CompRow(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first < b.first);
}
bool CompCol(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
void checkRow(void) {
  sort(rook + 1, rook + p + 1, CompCol);
  sort(query + 1, query + q + 1, CompLeft);
  for (int i = (1), _b = (p); i <= _b; i = i + 1)
    atRow[rook[i].first].push(rook[i].second);
  SegmentTree myit(m);
  for (int i = (1), _b = (m); i <= _b; i = i + 1)
    myit.assign(i, atRow[i].empty() ? 200200 : atRow[i].top());
  int j = 1;
  for (int i = (1), _b = (q); i <= _b; i = i + 1) {
    while (j <= p && rook[j].second < query[i].left) {
      int x = rook[j].first;
      atRow[x].pop();
      myit.assign(x, atRow[x].empty() ? 200200 : atRow[x].top());
      j++;
    }
    if (myit.getMax(query[i].top, query[i].bot) <= query[i].right)
      answer[query[i].id] = true;
  }
}
void checkCol(void) {
  sort(rook + 1, rook + p + 1, CompRow);
  sort(query + 1, query + q + 1, CompTop);
  for (int i = (1), _b = (p); i <= _b; i = i + 1)
    atCol[rook[i].second].push(rook[i].first);
  SegmentTree myit(n);
  for (int i = (1), _b = (n); i <= _b; i = i + 1)
    myit.assign(i, atCol[i].empty() ? 200200 : atCol[i].top());
  int j = 1;
  for (int i = (1), _b = (q); i <= _b; i = i + 1) {
    while (j <= p && rook[j].first < query[i].top) {
      int y = rook[j].second;
      atCol[y].pop();
      myit.assign(y, atCol[y].empty() ? 200200 : atCol[y].top());
      j++;
    }
    if (myit.getMax(query[i].left, query[i].right) <= query[i].bot)
      answer[query[i].id] = true;
  }
}
void process(void) {
  for (int i = (1), _b = (n); i <= _b; i = i + 1)
    printf("%s\n", answer[i] ? yes : no);
}
int main(void) {
  init();
  checkRow();
  checkCol();
  process();
  return 0;
}
