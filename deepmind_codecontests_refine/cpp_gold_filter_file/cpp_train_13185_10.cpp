#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
struct node {
  node *go[30], *pa;
  vector<node *> son;
  vector<pair<int, int> > q;
  int val, pos;
} pool[N], *cur = pool, *rt;
char s[N], t[N];
int n;
node *newnode() {
  node *p = cur++;
  p->val = p->pos = 0;
  p->pa = 0;
  p->son.clear();
  return p;
}
node *append(node *p, int w) {
  node *np = newnode();
  np->val = p->val + 1;
  while (p && !p->go[w]) {
    p->go[w] = np;
    p = p->pa;
  }
  if (!p)
    np->pa = rt;
  else {
    node *q = p->go[w];
    if (q->val == p->val + 1)
      np->pa = q;
    else {
      node *nq = newnode();
      nq->val = p->val + 1;
      memcpy(nq->go, q->go, sizeof(q->go));
      nq->pa = q->pa;
      np->pa = q->pa = nq;
      while (p && p->go[w] == q) {
        p->go[w] = nq;
        p = p->pa;
      }
    }
  }
  return np;
}
void init() {
  cur = pool;
  rt = newnode();
  node *np = rt;
  for (int i = 1; i <= n; i++) {
    np = append(np, s[i] - 'a');
    np->pos = i;
  }
  for (node *p = pool; p != cur; p++)
    if (p->pa) p->pa->son.push_back(p);
}
int q, c, ans[N];
int ct = 0;
vector<pair<int, int> > seq;
void dfs(node *p) {
  int id = ct++;
  if (p->pos) seq.push_back(make_pair(id, p->pos));
  for (auto v : p->son) dfs(v);
  if (!p->q.empty()) {
    vector<int> c;
    for (auto it = lower_bound((seq).begin(), (seq).end(), make_pair(id, -1));
         it != seq.end(); ++it)
      c.push_back(it->second);
    sort((c).begin(), (c).end());
    map<int, int> val;
    for (auto w : p->q) {
      if (w.first > (int(c.size())))
        ans[w.second] = -1;
      else {
        if (val.count(w.first)) {
          ans[w.second] += val[w.first];
          continue;
        }
        int mv = 1e9;
        for (int i = 0;
             i < (int(c.size())) && i + w.first - 1 < (int(c.size())); i++)
          mv = min(mv, c[i + w.first - 1] - c[i]);
        val[w.first] = mv;
        ans[w.second] += mv;
      }
    }
  }
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  init();
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d %s", &c, t);
    int m = strlen(t);
    node *p = rt;
    for (int j = 0; j < m; j++) {
      int w = t[j] - 'a';
      if (!p->go[w]) {
        ans[i] = -1;
        break;
      } else
        p = p->go[w];
    }
    if (~ans[i]) {
      ans[i] = m;
      p->q.push_back(make_pair(c, i));
    }
  }
  dfs(rt);
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
