#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int treesize = 1 << 17;
const int maxd = 100206;
const int MOD = 1000000007;
const long long hst = 239;
struct tnode {
  tnode *l, *r;
  bool haveempty;
  long long hash;
  bool set0;
  tnode() {
    l = NULL;
    r = NULL;
    haveempty = true;
    hash = 0;
    set0 = false;
  }
  tnode(tnode &x)
      : l(x.l), r(x.r), haveempty(x.haveempty), hash(x.hash), set0(x.set0) {}
};
typedef tnode *pnode;
long long sth[treesize], st2[treesize];
void push(pnode cur) {
  if (!cur->set0) return;
  if (cur->l != NULL) {
    cur->l = new tnode(*cur->l);
    cur->l->set0 |= cur->set0;
  }
  if (cur->r != NULL) {
    cur->r = new tnode(*cur->r);
    cur->r->set0 |= cur->set0;
  }
  cur->hash = 0;
  cur->set0 = false;
  cur->haveempty = true;
}
inline long long gethash(pnode cur) {
  return (cur == NULL ? 0 : (cur->set0 ? 0 : cur->hash));
}
inline bool getempty(pnode cur) {
  return (cur == NULL ? true : (cur->set0 ? true : cur->haveempty));
}
void update(pnode cur, int sz) {
  cur->hash = gethash(cur->r) * sth[sz] + gethash(cur->l);
  cur->haveempty = getempty(cur->l) || getempty(cur->r);
}
bool add(pnode &cur, int cl, int cr, int x) {
  if (cr < x) return false;
  if (cur == NULL)
    cur = new tnode();
  else
    cur = new tnode(*cur);
  push(cur);
  if (x <= cl && !cur->haveempty) {
    cur->set0 = true;
    return false;
  }
  if (cl == cr) {
    cur->hash = 1;
    cur->haveempty = false;
    return true;
  }
  int cm = (cl + cr) / 2;
  bool done = add(cur->l, cl, cm, x) || add(cur->r, cm + 1, cr, x);
  update(cur, cr - cm);
  return done;
}
bool lesss(pnode a, pnode b, int cl, int cr) {
  if (gethash(a) == gethash(b)) return false;
  if (a == NULL) return true;
  if (b == NULL) return false;
  push(a);
  push(b);
  if (cl == cr) return a->hash < b->hash;
  int cm = (cl + cr) / 2;
  if (gethash(a->r) == gethash(b->r))
    return lesss(a->l, b->l, cl, cm);
  else
    return lesss(a->r, b->r, cm + 1, cr);
}
pnode d[maxn];
vector<pair<int, int>> gr[maxn];
int n, m;
int start, finish;
int from[maxn];
bool was[maxn];
vector<int> answer;
int ans;
inline void calcmod(pnode cur, int cl, int cr) {
  if (cur == NULL) return;
  push(cur);
  if (cl == cr) {
    ans = (ans + st2[cl] * (cur->hash != 0 ? 1 : 0)) % MOD;
    return;
  }
  int cm = (cl + cr) / 2;
  calcmod(cur->l, cl, cm);
  calcmod(cur->r, cm + 1, cr);
}
inline bool cmp(int a, int b) {
  if (lesss(d[a], d[b], 0, treesize - 1)) return true;
  if (lesss(d[b], d[a], 0, treesize - 1)) return false;
  return false;
}
set<int, bool (*)(int, int)> q(cmp);
int main() {
  sth[0] = 1;
  for (int i = 1; i < treesize; i++) sth[i] = sth[i - 1] * hst;
  st2[0] = 1;
  for (int i = 1; i < treesize; i++) st2[i] = (st2[i - 1] * 2) % MOD;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--, b--;
    gr[a].push_back({b, c});
    gr[b].push_back({a, c});
  }
  scanf("%d%d", &start, &finish);
  start--, finish--;
  if (start == finish) {
    printf("0\n1\n%d\n", start + 1);
    return 0;
  }
  d[start] = new tnode();
  from[start] = -1;
  pnode inf = new tnode();
  add(inf, 0, treesize - 1, maxd + 1);
  for (int i = 0; i < n; i++)
    if (i != start) d[i] = new tnode(*inf), from[i] = -1;
  for (int i = 0; i < n; i++) q.insert(i);
  while (!q.empty()) {
    int cur = *q.begin();
    q.erase(q.begin());
    was[cur] = true;
    for (auto x : gr[cur])
      if (!was[x.first]) {
        pnode newd = d[cur];
        add(newd, 0, treesize - 1, x.second);
        if (lesss(newd, d[x.first], 0, treesize - 1)) {
          q.erase(x.first);
          d[x.first] = newd;
          q.insert(x.first);
          from[x.first] = cur;
        }
      }
  }
  if (from[finish] == -1) {
    printf("-1\n");
    return 0;
  }
  ans = 0;
  calcmod(d[finish], 0, treesize - 1);
  printf("%d\n", ans);
  int cur = finish;
  while (cur != -1) {
    answer.push_back(cur);
    cur = from[cur];
  }
  printf("%d\n", answer.size());
  reverse(answer.begin(), answer.end());
  for (auto x : answer) printf("%d ", x + 1);
  printf("\n");
  return 0;
}
