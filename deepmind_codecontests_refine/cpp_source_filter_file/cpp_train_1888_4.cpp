#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = (int)(1e9 + 1e5);
const long long LINF = (long long)(2e18);
const long long BASE = 1003;
const double EPS = 1e-9;
const int MOD = 1000000007;
int tnum;
struct node {
  long long val;
  long long delta;
  pair<long long, int> mn;
};
struct number {
  int val;
  int pos_src;
  int pos_dst;
  bool add;
};
const int MAXN = 500500;
int len, n;
node tre[MAXN << 2];
int st[MAXN];
number a[MAXN];
number pl[MAXN];
int ans[MAXN];
set<int> positions;
void init() {
  scanf("%d\n", &len);
  for (int i = 1; i <= len; ++i) {
    char s;
    scanf("%c", &s);
    scanf("%d\n", &a[i].val);
    a[i].pos_src = i;
    a[i].add = (s == '+');
  }
}
void add(int tv, long long delta) {
  tre[tv].mn.first += delta;
  tre[tv].val += delta;
  tre[tv].delta += delta;
}
void push(int tv, int tl, int tr) {
  if (tl < tr) {
    add(tv * 2, tre[tv].delta);
    add(tv * 2 + 1, tre[tv].delta);
    tre[tv].delta = 0;
  }
}
void pull(int tv, int tl, int tr) {
  if (tl < tr) {
    tre[tv].mn = min(tre[tv * 2].mn, tre[tv * 2 + 1].mn);
  }
}
void build(int tv, int tl, int tr) {
  tre[tv].val = LINF;
  if (tl == tr) {
    tre[tv].mn = pair<long long, int>(tre[tv].val, tl);
  } else {
    int tm = (tl + tr) >> 1;
    build(tv * 2, tl, tm);
    build(tv * 2 + 1, tm + 1, tr);
    tre[tv].mn = min(tre[tv * 2].mn, tre[tv * 2 + 1].mn);
  }
}
void add(int tv, int tl, int tr, int l, int r, long long delta) {
  if (l > r) {
    return;
  }
  if (tl == l && r == tr) {
    add(tv, delta);
    return;
  }
  push(tv, tl, tr);
  int tm = (tl + tr) >> 1;
  add(tv * 2, tl, tm, l, min(tm, r), delta);
  add(tv * 2 + 1, tm + 1, tr, max(l, tm + 1), r, delta);
  pull(tv, tl, tr);
}
pair<long long, int> get_min(int tv, int tl, int tr, int l, int r) {
  if (l > r) {
    return pair<long long, int>(LINF, 0);
  }
  push(tv, tl, tr);
  if (tl == l && r == tr) {
    return tre[tv].mn;
  }
  int tm = (tl + tr) >> 1;
  return min(get_min(tv * 2, tl, tm, l, min(r, tm)),
             get_min(tv * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}
void debug(int tv, int tl, int tr) {
  if (tv == 1) {
    fprintf(stderr, "-------------\n");
  }
  fprintf(stderr,
          "tv: %d tl: %d tr: %d val: %lld delta: %lld mn.first: %lld "
          "mn.second: %d\n",
          tv, tl, tr, tre[tv].val, tre[tv].delta, tre[tv].mn.first,
          tre[tv].mn.second);
  if (tl < tr) {
    int tm = (tl + tr) >> 1;
    debug(tv * 2, tl, tm);
    debug(tv * 2 + 1, tm + 1, tr);
  }
}
int get_less_than_zero(int tv, int tl, int tr, int l, int r) {
  if (l > r) {
    return 0;
  }
  if (tre[tv].mn.first >= 0) {
    return 0;
  }
  push(tv, tl, tr);
  if (tl == tr) {
    return 1;
  }
  int tm = (tl + tr) >> 1;
  return get_less_than_zero(tv * 2, tl, tm, l, min(r, tm)) +
         get_less_than_zero(tv * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
}
int check() {
  if (positions.empty()) {
    return 0;
  }
  int st = (*positions.begin()) + 1;
  auto res = get_less_than_zero(1, 1, n, st, n);
  return (positions.size() - 1) - res;
}
void solve() {
  for (int i = 1; i <= len; ++i) {
    if (a[i].add) {
      pl[++n] = a[i];
    }
  }
  sort(pl + 1, pl + n + 1,
       [&](const number& n1, const number& n2) { return n1.val < n2.val; });
  for (int i = 1; i <= n; ++i) {
    a[pl[i].pos_src].pos_dst = i;
  }
  int p1 = 0, p2 = 0;
  while (p1 <= n) {
    p2 = p1;
    while (p2 + 1 <= n && pl[p2 + 1].val == pl[p1].val) {
      ++p2;
    }
    for (int i = p1; i <= p2; ++i) {
      st[i] = p1;
    }
    p1 = p2 + 1;
  }
  multimap<int, int> pls;
  for (int i = 1; i <= len; ++i) {
    if (a[i].add) {
      pls.insert(pair<int, int>(a[i].val, i));
    } else {
      auto it = pls.find(a[i].val);
      assert(it != pls.end());
      a[i].pos_dst = a[it->second].pos_dst;
      pls.erase(it);
    }
  }
  build(1, 1, n);
  for (int i = 1; i <= len; ++i) {
    add(1, 1, n, a[i].pos_dst, a[i].pos_dst,
        (a[i].add ? 1 : -1) * (-LINF - (a[i].val + 1) / 2 - a[i].val));
    add(1, 1, n, st[a[i].pos_dst], n, (a[i].add ? 1 : -1) * a[i].val);
    if (a[i].add) {
      positions.insert(a[i].pos_dst);
    } else {
      positions.erase(a[i].pos_dst);
    }
    ans[i] = check();
  }
}
void print_answer() {
  for (int i = 1; i <= len; ++i) {
    printf("%d\n", ans[i]);
  }
}
void precalc() {}
void run() {
  precalc();
  int t = 1;
  for (tnum = 1; tnum <= t; ++tnum) {
    init();
    solve();
    print_answer();
  }
}
int main() {
  srand(90);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  run();
  return 0;
}
