#include <bits/stdc++.h>
using namespace std;
const char newline = '\n';
const int maxn = 1e5 + 1;
int stk[maxn], top = 0;
int pa[maxn], sz[maxn], dis[maxn];
void init(int n) {
  top = 0;
  for (int i = 1; i <= n; ++i) {
    pa[i] = i, sz[i] = 1, dis[i] = 0;
  }
}
int findpa(int id) {
  while (id != pa[id]) {
    id = pa[id];
  }
  return id;
}
int distance(int id) {
  int ret = 0;
  while (id != pa[id]) {
    ret ^= dis[id];
    id = pa[id];
  }
  return ret;
}
bool merge(int x, int y) {
  int xp = findpa(x), yp = findpa(y);
  int d = distance(x) ^ distance(y);
  if (xp == yp) {
    if (!d) {
      return false;
    }
  } else {
    if (sz[xp] > sz[yp]) {
      swap(xp, yp);
    }
    sz[yp] += sz[xp];
    pa[xp] = yp;
    dis[xp] = d ^ 1;
    stk[top++] = xp;
  }
  return true;
}
void rewind(int t) {
  while (top > t) {
    int cur = stk[--top];
    sz[pa[cur]] -= sz[cur];
    pa[cur] = cur;
    dis[cur] = 0;
  }
}
int n, q, tot;
map<pair<int, int>, int> ma;
pair<int, int> res[maxn];
pair<int, int> e[maxn];
int operation[maxn];
void solve(int l, int r) {
  init(n);
  int start_t = top;
  vector<int> undone;
  for (int i = 0; i < tot; ++i) {
    if (res[i].first <= l && res[i].second >= r) {
      if (!merge(e[i].first, e[i].second)) {
        for (int i = l; i <= r; ++i) {
          puts("NO");
        }
        rewind(start_t);
        return;
      }
    } else if (e[i].first > r || e[i].second < l)
      ;
    else {
      undone.push_back(i);
    }
  }
  int mid_t = top;
  for (int i = l; i <= r; ++i) {
    bool work = true;
    for (auto j : undone) {
      if (res[j].first <= i && i <= res[j].second) {
        if (!merge(e[j].first, e[j].second)) {
          work = false;
          break;
        }
      }
    }
    puts((work ? "YES" : "NO"));
    rewind(mid_t);
  }
  rewind(start_t);
}
int main() {
  scanf("%d %d", &n, &q);
  tot = 0;
  for (int i = 0; i < q; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (u > v) {
      swap(u, v);
    }
    pair<int, int> cur(u, v);
    if (ma.count(cur)) {
      int e = ma[cur];
      operation[i] = e;
      res[e].second = i - 1;
      ma.erase(cur);
    } else {
      res[tot].first = i;
      res[tot].second = q;
      e[tot] = cur;
      operation[i] = tot;
      ma[cur] = tot++;
    }
  }
  int bsz = sqrt(q + .05);
  int btot = (q + bsz - 1) / bsz;
  for (int i = 0; i < btot; ++i) {
    solve(i * bsz, min((i + 1) * bsz - 1, q - 1));
  }
}
