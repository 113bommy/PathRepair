#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10240000,10240000")
using namespace std;
const int block_size = 320;
const long long mod = 1e9 + 7;
const long double eps = 1e-9;
const int inf = mod;
const double PI = atan(1) * 4;
template <typename T>
inline int sign(const T& a) {
  if (a < 0) return -1;
  if (a > 0) return 1;
  return 0;
}
template <typename T>
inline void in(T& x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
long long twop(int x) { return 1LL << x; }
template <typename A, typename B>
inline void in(A& x, B& y) {
  in(x);
  in(y);
}
template <typename A, typename B, typename C>
inline void in(A& x, B& y, C& z) {
  in(x);
  in(y);
  in(z);
}
template <typename A, typename B, typename C, typename D>
inline void in(A& x, B& y, C& z, D& xx) {
  in(x);
  in(y);
  in(z);
  in(xx);
}
template <class T>
void upd(T& a, T b) {
  a = max(a, b);
}
struct SAM {
  static const int maxn = 100010 * 2;
  struct node {
    node *nxt[26], *fail;
    int pos;
    int len;
  };
  node* root;
  int cnt;
  node no[maxn];
  node* newnode() { return &no[cnt++]; }
  SAM() {
    cnt = 0;
    root = newnode();
  }
  node* add(node* p, int c) {
    node* cur = newnode();
    cur->len = p->len + 1;
    while (p && !p->nxt[c]) p->nxt[c] = cur, p = p->fail;
    if (!p) {
      cur->fail = root;
      return cur;
    }
    node* q = p->nxt[c];
    if (q->len == p->len + 1) {
      cur->fail = q;
    } else {
      node* nq = newnode();
      *nq = *q;
      nq->len = p->len + 1;
      q->fail = cur->fail = nq;
      while (p && p->nxt[c] == q) p->nxt[c] = nq, p = p->fail;
    }
    return cur;
  }
  void init() {
    for (int i = 0; i < cnt; i++) no[i].pos = inf;
  }
  void getPos() {
    vector<node*> v;
    for (int i = 1; i < cnt; i++) {
      v.push_back(&no[i]);
    }
    sort(v.begin(), v.end(),
         [](const node* a, const node* b) { return a->len > b->len; });
    for (auto i : v) i->fail->pos = min(i->fail->pos, i->pos);
  }
  long long getNumOfDistinctSubstrings() {
    auto ans = 0;
    for (int i = 1; i < cnt; i++) ans += no[i].len - no[i].fail->len;
    return (ans);
  }
} sam, mas;
string s;
int ans = 0;
int occ[2][1010];
string q;
void preA() {
  auto r = sam.root;
  bool ok = 1;
  occ[0][0] = -1;
  int cnt = 1;
  for (auto i : q) {
    i -= 'A';
    if (!r->nxt[i]) {
      ok = 0;
      break;
    }
    r = r->nxt[i];
    occ[0][cnt++] = r->pos;
  }
}
void preB() {
  auto r = mas.root;
  bool ok = 1;
  occ[1][0] = -1;
  int cnt = 1;
  for (int j = ((int)q.size()) - 1; j >= 0; j--) {
    auto i = q[j];
    i -= 'A';
    if (!r->nxt[i]) {
      ok = 0;
      break;
    }
    r = r->nxt[i];
    occ[1][cnt++] = r->pos;
  }
}
void solve() {
  fill(occ[0], occ[0] + 1010, inf);
  fill(occ[1], occ[1] + 1010, inf);
  cin >> q;
  preA();
  preB();
  for (int i = 1; i < ((int)q.size()); i++) {
    if (occ[0][i] < ((int)q.size()) - 1 - occ[1][((int)q.size()) - i]) {
      ans++;
      return;
    }
  }
}
int main() {
  cin >> s;
  auto r = sam.root;
  for (int i = 0; i < ((int)s.size()); i++) r = sam.add(r, s[i] - 'A');
  r = sam.root;
  r->pos = -1;
  sam.init();
  for (int i = 0; i < ((int)s.size()); i++) r = r->nxt[s[i] - 'A'], r->pos = i;
  r = mas.root;
  for (int i = ((int)s.size()) - 1; i >= 0; i--) r = sam.add(r, s[i] - 'A');
  r = mas.root;
  r->pos = -1;
  mas.init();
  for (int i = ((int)s.size()) - 1; i >= 0; i--)
    r = r->nxt[s[i] - 'A'], r->pos = ((int)s.size()) - i - 1;
  sam.getPos();
  mas.getPos();
  int n;
  cin >> n;
  while (n--) solve();
  cout << ans << endl;
  return 0;
}
