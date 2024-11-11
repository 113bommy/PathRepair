#include <bits/stdc++.h>
using namespace std;
long long INF = 1e9;
long long MOD = 1e9 + 7;
int V[200100];
int W[200100];
int N, M, a, b, p;
int A[200100];
int B[200100];
int cur, res;
int vis[200100];
int cyc[200100];
int pos[200100];
pair<int, int> clen[200100];
int nxt[200100];
int ln[200100];
int exist[200100];
void check(int x) {
  if (vis[x]) return;
  a = b = x;
  do {
    a = V[a];
    if (vis[a]) return;
    vis[a] = 1;
    b = V[b];
    b = V[b];
  } while (a != b);
  pos[a] = ++p;
  vis[a] = 1;
  do {
    a = V[a];
    b = V[V[b]];
    vis[a] = 1;
    if (a == b) break;
    cyc[a] = cur;
    pos[a] = ++p;
  } while (a != b);
  vis[a] = 1;
  clen[cur] = make_pair(pos[a], p);
  cyc[a] = cur++;
}
struct node {
  int second, e, m, v;
  node *l, *r;
  node(int _s, int _e) : second(_s), e(_e) {
    m = (second + e) / 2;
    v = 0;
    if (second != e) {
      l = new node(second, m);
      r = new node(m + 1, e);
    }
  }
  void up(int x, int y) {
    if (v == e - second + 1) {
      return;
    }
    if (x == second && y == e) {
      v = e - second + 1;
      return;
    }
    if (y <= m)
      l->up(x, y);
    else if (x > m)
      r->up(x, y);
    else {
      l->up(x, m);
      r->up(m + 1, y);
    }
    v = l->v + r->v;
  }
  int query(int x, int y) {
    if (v == e - second + 1) {
      return 0;
    }
    if (second == x && y == e) {
      return e - second + 1 - v;
    }
    if (y <= m)
      return l->query(x, y);
    else if (x > m)
      return r->query(x, y);
    return l->query(x, m) + r->query(m + 1, y);
  }
} * root;
void pp(pair<int, int> a) { cout << a.first << ' ' << a.second << '\n'; }
int resolve(int a, int b) {
  pair<int, int> r = clen[cyc[a]];
  int l = r.second - r.first + 1;
  int cp = pos[a];
  if (b > l) b = l;
  pair<int, int> fst = make_pair(cp, min(cp + b, r.second));
  b -= (fst.second - fst.first + 1);
  int ans = 0;
  ans += root->query(fst.first, fst.second);
  root->up(fst.first, fst.second);
  if (b > 0) {
    fst = make_pair(r.first, r.first + b - 1);
    ans += root->query(fst.first, fst.second);
    root->up(fst.first, fst.second);
  }
  return ans;
}
pair<int, int> par(int x) {
  if (x == nxt[x]) return make_pair(x, 0);
  pair<int, int> t = par(nxt[x]);
  nxt[x] = t.first;
  ln[x] += t.second;
  return make_pair(nxt[x], ln[x]);
}
int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    cin >> V[i];
    W[i] = 1;
    exist[i] = 1;
  }
  root = new node(1, N);
  for (int i = 1; i <= M; ++i) cin >> A[i];
  for (int i = 1; i <= M; ++i) cin >> B[i];
  cur = 1;
  for (int i = 1; i <= N; ++i) {
    check(i);
  }
  for (int i = 1; i <= N; ++i) {
    nxt[i] = i;
    ln[i] = 0;
  }
  for (int i = 1; i <= M; ++i) {
    int a = (A[i] + res - 1) % N + 1;
    int b = B[i];
    if (cyc[a]) {
      res = resolve(a, b - 1);
      cout << res << '\n';
    } else {
      int ans = 0;
      while (b && !cyc[a]) {
        pair<int, int> t = par(V[a]);
        if (exist[a]) {
          ++ans;
        }
        exist[a] = 0;
        nxt[a] = t.first;
        ln[a] = 1 + t.second;
        if (ln[a] + 1 > b) {
          b = -1;
          break;
        }
        b -= ln[a];
        a = nxt[a];
      }
      if (b > 0) ans += resolve(a, b - 1);
      res = ans;
      cout << ans << '\n';
    }
  }
}
