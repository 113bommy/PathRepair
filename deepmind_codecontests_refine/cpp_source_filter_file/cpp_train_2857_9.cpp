#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int> > Q;
struct Node {
  Node *lc, *rc;
  int size;
  long long sum;
} * Root, *Null;
struct Level {
  long long v1, v2;
  int id;
  friend bool operator<(const Level &a, const Level &b) { return a.v2 < b.v2; }
} val[300010];
int n, m;
void read() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    cin >> val[i].v1 >> val[i].v2;
    val[i].id = i;
  }
  sort(val + 1, val + n + 1);
}
Node *Insert(Node *p, int l, int r, int x, int val1, int val2) {
  if (p == Null) {
    p = new Node;
    p->lc = Null, p->rc = Null;
    p->size = 0, p->sum = 0;
  }
  p->size += val2, p->sum += val1;
  if (l == r) return p;
  int mid = (l + r) >> 1;
  if (x <= mid)
    p->lc = Insert(p->lc, l, mid, x, val1, val2);
  else
    p->rc = Insert(p->rc, mid + 1, r, x, val1, val2);
  return p;
}
long long Query(Node *p, int l, int r, int rank) {
  if (p == Null) return 0;
  if (l == r) return l * rank;
  int mid = (l + r) >> 1;
  if (p->lc->size >= rank)
    return Query(p->lc, l, mid, rank);
  else
    return p->lc->sum + Query(p->rc, mid + 1, r, rank - p->lc->size);
}
void print() {
  static char str[300010];
  Null = new Node;
  Null->lc = Null, Null->rc = Null;
  Null->size = 0, Null->sum = 0;
  Root = Null;
  long long minv = 1000000000000000000LL, sum = 0;
  fill(str + 1, str + n + 1, '0');
  int id;
  for (int i = 1; i <= n; ++i)
    Root = Insert(Root, 1, 1000000000, val[i].v1, val[i].v1, 1);
  for (int i = 0; i <= n; ++i) {
    sum += val[i].v1;
    if (i)
      Insert(Root, 1, 1000000000, val[i].v1, -val[i].v1, -1),
          Insert(Root, 1, 1000000000, val[i].v2 - val[i].v1,
                 val[i].v2 - val[i].v1, 1);
    if (m - i >= 0 && m - i <= n) {
      long long v = sum + Query(Root, 1, 1000000000, m - i);
      if (minv > v) minv = v, id = i;
    }
  }
  for (int i = 1; i <= id; ++i) {
    str[val[i].id] = '1';
    Q.push(make_pair(val[i].v1 - val[i].v2, val[i].id));
  }
  for (int i = id + 1; i <= n; ++i) Q.push(make_pair(-val[i].v1, val[i].id));
  for (int i = 1; i <= m - id; ++i) {
    str[Q.top().second] = '2';
    Q.pop();
  }
  cout << minv << endl;
  printf("%s\n", str + 1);
}
int main() {
  read();
  print();
  return 0;
}
