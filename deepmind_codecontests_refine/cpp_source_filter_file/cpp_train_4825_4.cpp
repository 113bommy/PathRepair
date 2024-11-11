#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000009;
inline int add(int a, int b) {
  if ((a += b) >= mod) a -= mod;
  return a;
}
inline int mult(int a, int b) {
  long long t = 1ll * a * b;
  if (t >= mod) t %= mod;
  return t;
}
int n, K, a, b, c, d, m;
class node {
 public:
  int ch[2], f[2], x, y;
} t[100010];
vector<int> ID;
void pushup(int p) {
  if (!p) return;
  if (!(t[p].ch[0]) && !(t[p].ch[1])) {
    t[p].f[0] = 0;
    t[p].f[1] = -1e9;
    return;
  }
  if (!(t[p].ch[0])) {
    t[p].f[0] = max(t[(t[p].ch[1])].f[0], t[(t[p].ch[1])].f[1]);
    t[p].f[1] = t[(t[p].ch[1])].f[0] + 1;
    return;
  }
  if (!(t[p].ch[1])) {
    t[p].f[0] = max(t[(t[p].ch[0])].f[0], t[(t[p].ch[0])].f[1]);
    t[p].f[1] = t[(t[p].ch[0])].f[0] + 1;
    return;
  }
  t[p].f[0] = max(t[(t[p].ch[0])].f[0], t[(t[p].ch[0])].f[1]) +
              max(t[(t[p].ch[1])].f[0], t[(t[p].ch[1])].f[1]);
  t[p].f[1] = max(max(t[(t[p].ch[0])].f[0], t[(t[p].ch[0])].f[1]) +
                      t[(t[p].ch[1])].f[0],
                  max(t[(t[p].ch[1])].f[0], t[(t[p].ch[1])].f[1]) +
                      t[(t[p].ch[0])].f[0]) +
              1;
}
inline int cmp(int a, int b) { return t[a].y < t[b].y; }
int build(vector<int> id) {
  if (!id.size()) return 0;
  int p = id.back();
  vector<int> L, R;
  for (int i = 0; i + 1 < id.size(); i++) {
    if (t[id[i]].x < t[p].x)
      L.push_back(id[i]);
    else
      R.push_back(id[i]);
  }
  (t[p].ch[0]) = build(L);
  (t[p].ch[1]) = build(R);
  pushup(p);
  return p;
}
void split(int p, int &x, int &y, int val) {
  if (!p) {
    x = y = 0;
    return;
  }
  if (t[p].x <= val)
    x = p, split(t[p].ch[1], t[x].ch[1], y, val);
  else
    y = p, split(t[p].ch[0], x, t[y].ch[0], val);
  pushup(x);
  pushup(y);
}
void merge(int &p, int x, int y) {
  if (!x || !y) {
    p = x | y;
    return;
  }
  if (t[x].y > t[y].y)
    p = x, merge(t[p].ch[1], t[x].ch[1], y);
  else
    p = y, merge(t[p].ch[0], x, t[y].ch[0]);
  pushup(p);
}
int rt;
int main() {
  scanf("%d%d", &n, &K);
  for (int i = 1; i <= K; i++) scanf("%d%d", &t[i].x, &t[i].y);
  scanf("%d%d%d%d", &a, &b, &c, &d);
  for (int i = K + 1; i <= n; i++) {
    t[i].x = add(mult(t[i - 1].x, a), c);
    t[i].y = add(mult(t[i - 1].y, b), d);
  }
  for (int i = 1; i <= n; i++) ID.push_back(i);
  sort(ID.begin(), ID.end(), cmp);
  rt = build(ID);
  scanf("%d", &m);
  for (int i = 1, l, r; i <= m; i++) {
    scanf("%d%d", &l, &r);
    int t1, t2, t3;
    split(rt, t1, t2, l - 1);
    split(t2, t2, t3, r);
    printf("%d\n", max(t[t2].f[0], t[t2].f[1]));
    merge(t2, t2, t3);
    merge(rt, t1, t2);
  }
  return 0;
}
