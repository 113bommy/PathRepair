#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
const int N = 200005;
const int M = N * 2;
const int MAXN = M * 27;
const int CHAR_SET = 26;
template <class T>
bool read(T& x) {
  char c;
  while (!isdigit(c = getchar()) && c != '-' && c != EOF)
    ;
  if (c == EOF) return false;
  T flag = 1;
  if (c == '-') {
    flag = -1;
    x = 0;
  } else
    x = c - '0';
  while (isdigit(c = getchar())) x = x * 10 + c - '0';
  x *= flag;
  return true;
}
template <class T, class... R>
bool read(T& a, R&... b) {
  if (!read(a)) return false;
  return read(b...);
}
int rt[M], pos[N], ls[MAXN], rs[MAXN], val[MAXN], n_node, m;
void update(int& o, int l, int r, int x) {
  if (!o) o = ++n_node;
  if (l == r) {
    val[o]++;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    update(ls[o], l, mid, x);
  else
    update(rs[o], mid + 1, r, x);
  val[o] = val[ls[o]] + val[rs[o]];
}
int query(int o, int l, int r, int x, int y) {
  if (x <= l && y >= r) return val[o];
  int mid = (l + r) >> 1;
  if (y <= mid)
    return query(ls[o], l, mid, x, y);
  else if (x > mid)
    return query(rs[o], mid + 1, r, x, y);
  else
    return query(ls[o], l, mid, x, y) + query(rs[o], mid + 1, r, x, y);
}
int merge(int u, int v, int l, int r) {
  if (!u) return v;
  if (!v) return u;
  int o = ++n_node;
  if (l == r) {
    val[o] = val[u] + val[v];
    return o;
  }
  int mid = (l + r) >> 1;
  ls[o] = merge(ls[u], ls[v], l, mid);
  rs[o] = merge(rs[u], rs[v], mid + 1, r);
  val[o] = val[ls[o]] + val[rs[o]];
  return o;
}
class suffix_automaton {
 private:
  int ch[M][CHAR_SET], link[M], len[M], cnt[M], rk[M];
  int n, last;
  int get_chr(int c) const { return c; }
  int extend(int c, int id) {
    c = get_chr(c);
    int p = last;
    if (!ch[p][c]) {
      int np = ++n;
      len[np] = len[p] + 1;
      for (; p && !ch[p][c]; p = link[p]) ch[p][c] = np;
      if (!p)
        link[np] = 1;
      else {
        int q = ch[p][c];
        if (len[q] == len[p] + 1)
          link[np] = q;
        else {
          int nq = ++n;
          for (int i = 0; i < CHAR_SET; i++) ch[nq][i] = ch[q][i];
          link[nq] = link[q];
          len[nq] = len[p] + 1;
          link[q] = link[np] = nq;
          for (; p && ch[p][c] == q; p = link[p]) ch[p][c] = nq;
        }
      }
      last = np;
    } else if (len[ch[p][c]] != len[p] + 1) {
      int q = ch[p][c], nq = ++n;
      for (int i = 0; i < CHAR_SET; i++) ch[nq][i] = ch[q][i];
      link[nq] = link[q];
      len[nq] = len[p] + 1;
      link[q] = nq;
      for (; p && ch[p][c] == q; p = link[p]) ch[p][c] = nq;
      last = nq;
    } else
      last = ch[p][c];
    update(rt[last], 1, m, id);
    return last;
  }

 public:
  suffix_automaton() : n(1), last(1) {}
  void insert(const char* s, int id) {
    last = 1;
    for (int i = 0; s[i]; i++) extend(s[i], id);
    pos[id] = last;
  }
  int size() const { return n; }
  void init() {
    for (int i = 1; i <= n; i++) cnt[len[i]]++;
    for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
    for (int i = 1; i <= n; i++) rk[cnt[len[i]]--] = i;
    for (int i = n; i >= 1; i--)
      rt[link[rk[i]]] = merge(rt[link[rk[i]]], rt[rk[i]], 1, m);
  }
} sa;
mt19937 gen(steady_clock::now().time_since_epoch().count());
char s[N];
int main() {
  time_point<steady_clock> start = steady_clock::now();
  int q, l, r, k;
  read(m, q);
  for (int i = 1; i <= m; i++) {
    scanf("%s", s);
    sa.insert(s, i);
  }
  sa.init();
  while (q--) {
    read(l, r, k);
    printf("%d\n", query(rt[pos[k]], 1, m, l, r));
  }
  cerr << endl
       << "------------------------------" << endl
       << "Time: "
       << duration<double, milli>(steady_clock::now() - start).count() << " ms."
       << endl;
  return 0;
}
