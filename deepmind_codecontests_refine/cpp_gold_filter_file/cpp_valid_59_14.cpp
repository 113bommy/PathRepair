#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1 << 12;
int n, m;
int a[SIZE], _b[SIZE];
int b[SIZE];
vector<int> e[SIZE];
struct Union_Find {
  int d[1234567], num[1234567];
  void init(int n) {
    for (int i = 0; i < n; i++) {
      d[i] = i;
      num[i] = 1;
    }
  }
  int find(int x) {
    int y = x, z = x;
    while (y != d[y]) {
      y = d[y];
    }
    while (x != y) {
      x = d[x];
      d[z] = y;
      z = x;
    }
    return y;
  }
  bool is_root(int x) { return d[x] == x; }
  bool uu(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return 0;
    }
    if (num[x] > num[y]) {
      swap(x, y);
    }
    num[y] += num[x];
    d[x] = y;
    return 1;
  }
} U;
int rn;
int ma_v;
bitset<2001> u;
int from[SIZE];
long long add_v;
long long st;
void clear(int y) {
  int AA = y;
  while (AA != 1) {
    add_v += b[AA];
    if (b[AA]) rn--;
    b[AA] = 0;
    AA = from[AA];
  }
}
bool dfs(int x, int lt, long long now) {
  u[x] = 1;
  for (int y : e[x]) {
    if (y == lt) {
      continue;
    }
    if (u[y] && b[y] == 0) {
      if (now > st) {
        clear(y);
        clear(x);
        return 1;
      }
      continue;
    }
    if (now > a[y]) {
      if (u[y]) {
        clear(y);
        clear(x);
        return 1;
      } else {
        from[y] = x;
        if (dfs(y, x, now + b[y])) return 1;
      }
    }
  }
  return 0;
}
bool valid(long long st_v) {
  for (int i = (1); i <= (n); ++i) {
    b[i] = _b[i];
  }
  U.init(n + 1);
  rn = n;
  add_v = 0;
  while (rn == 1 || st_v <= ma_v) {
    st = st_v;
    u.reset();
    if (!dfs(1, 1, st_v)) break;
    st_v += add_v;
    add_v = 0;
  }
  return rn == 1 || st_v > ma_v;
}
void solve() {
  ma_v = *max_element(a + 1, a + n + 1) + 1;
  int ll = MOD, rr = ma_v;
  for (int x : e[1]) ll = min(ll, a[x]);
  while (ll < rr) {
    int mm = (ll + rr) / 2;
    if (valid(mm))
      rr = mm;
    else
      ll = mm + 1;
  }
  W(ll);
}
void input() {
  R(n, m);
  for (int i = (2); i <= (n); ++i) {
    R(a[i]);
  }
  for (int i = (2); i <= (n); ++i) {
    R(_b[i]);
  }
  for (int i = (1); i <= (n); ++i) {
    vector<int> tmp;
    e[i].swap(tmp);
  }
  for (int i = 0; i < (m); ++i) {
    int x, y;
    R(x, y);
    e[x].emplace_back(y);
    e[y].emplace_back(x);
  }
}
int main() {
  int ___T;
  scanf("%d", &___T);
  for (int cs = 1; cs <= ___T; cs++) {
    input();
    solve();
  }
  return 0;
}
