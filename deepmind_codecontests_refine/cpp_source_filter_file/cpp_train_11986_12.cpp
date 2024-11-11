#include <bits/stdc++.h>
using std::max;
using std::min;
const int inf = 0x3f3f3f3f, Inf = 0x7fffffff;
const long long INF = 0x3f3f3f3f3f3f3f3f;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>
_Tp gcd(const _Tp &a, const _Tp &b) {
  return (!b) ? a : gcd(b, a % b);
}
template <typename _Tp>
inline _Tp abs(const _Tp &a) {
  return a >= 0 ? a : -a;
}
template <typename _Tp>
inline void chmax(_Tp &a, const _Tp &b) {
  (a < b) && ((a = b), 0);
}
template <typename _Tp>
inline void chmin(_Tp &a, const _Tp &b) {
  (b < a) && (a = b);
}
template <typename _Tp>
inline void read(_Tp &x) {
  char ch(getchar());
  bool f(false);
  while (!isdigit(ch)) f |= ch == 45, ch = getchar();
  x = ch & 15, ch = getchar();
  while (isdigit(ch)) x = (((x << 2) + x) << 1) + (ch & 15), ch = getchar();
  f && (x = -x);
}
template <typename _Tp, typename... Args>
inline void read(_Tp &t, Args &...args) {
  read(t);
  read(args...);
}
inline int read_str(char *s) {
  char ch(getchar());
  while (ch == ' ' || ch == '\r' || ch == '\n') ch = getchar();
  char *tar = s;
  *tar = ch, ch = getchar();
  while (ch != ' ' && ch != '\r' && ch != '\n' && ch != EOF)
    *(++tar) = ch, ch = getchar();
  return tar - s + 1;
}
const int N = 100005;
int f[N], a[N], b[N];
struct node {
  int val, id;
  inline bool operator<(const node &o) const { return val < o.val; }
};
struct BIT {
  node c[N];
  void add(int x, node C) {
    for (; x < N; x += ((x) & (-(x)))) chmax(c[x], C);
  }
  void upd(int x) {
    for (; x < N; x += ((x) & (-(x)))) c[x] = {0, 0};
  }
  node sum(int x) {
    node ans = {0, 0};
    for (; x; x -= ((x) & (-(x)))) chmax(ans, c[x]);
    return ans;
  }
} tr;
node dp[N];
std::set<std::pair<int, int> > S;
void MAIN() {
  int n;
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]), b[i] = 0;
  int siz = n, cnt = 0;
  while (siz) {
    node maxx = {0, 0};
    for (int i = 1; i <= n; ++i) {
      if (!b[i]) {
        node tmp = tr.sum(a[i]);
        ++tmp.val;
        dp[i] = tmp;
        tmp.id = i, chmax(maxx, tmp);
        tr.add(a[i], tmp);
      }
    }
    for (int i = 1; i <= n; ++i)
      if (!b[i]) tr.upd(a[i]);
    if (maxx.val > f[siz]) {
      int cur = maxx.id;
      ++cnt;
      while (cur) {
        --siz;
        b[cur] = cnt;
        cur = dp[cur].id;
      }
    } else {
      S.clear();
      for (int i = 1; i <= n; ++i) {
        if (!b[i]) {
          auto it = S.lower_bound(std::make_pair(a[i], 0));
          if (it == S.end())
            b[i] = ++cnt;
          else {
            b[i] = it->second;
            S.erase(it);
          }
          S.insert(std::make_pair(a[i], b[i]));
        }
      }
      break;
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; ++i) {
    std::vector<int> v;
    for (int j = 1; j <= n; ++j)
      if (b[j] == i) v.push_back(j);
    printf("%d ", ((int)v.size()));
    for (auto it : v) printf("%d ", it);
    printf("\n");
  }
}
int main() {
  int qwq = 0;
  for (int i = 1; i < N; ++i) {
    while (qwq * (qwq + 1) / 2 <= i) ++qwq;
    f[i] = qwq - 1;
  }
  int _;
  read(_);
  while (_--) MAIN();
  return 0;
}
