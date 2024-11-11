#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = {{-1, 0}, {0, 1}, {1, 0},  {0, -1},
                        {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}
template <typename t, typename t1>
t min1(t a, t1 b) {
  return a < b ? a : b;
}
template <typename t, typename... arg>
t min1(t a, arg... arr) {
  return min1(a, min1(arr...));
}
template <typename t, typename t1>
t max1(t a, t1 b) {
  return a > b ? a : b;
}
template <typename t, typename... arg>
t max1(t a, arg... arr) {
  return max1(a, max1(arr...));
}
inline int jud(double a, double b) {
  if (abs(a) < eps && abs(b) < eps)
    return 0;
  else if (abs1(a - b) / max(abs1(a), abs1(b)) < eps)
    return 0;
  if (a < b) return -1;
  return 1;
}
template <typename t>
inline int jud(t a, t b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
  if (na == 0) return 0;
  int be = 0, en = na - 1;
  if (*a <= *(a + na - 1)) {
    if (f_lb == 0)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != 1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != -1)
          en = mid;
        else
          be = mid + 1;
      }
    if (f_small && jud(*(a + be), val) == 1) be--;
    if (!f_small && jud(*(a + be), val) == -1) be++;
  } else {
    if (f_lb)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != -1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != 1)
          en = mid;
        else
          be = mid + 1;
      }
    if (!f_small && jud(*(a + be), val) == -1) be--;
    if (f_small && jud(*(a + be), val) == 1) be++;
  }
  return be;
}
template <class T>
inline T lowb(T num) {
  return num & (-num);
}
inline int bitnum(unsigned int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(unsigned long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitnum(long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitmaxl(unsigned int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(unsigned long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
inline int bitmaxl(long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
long long pow(long long n, long long m, long long mod = 0) {
  if (m < 0) return 0;
  long long ans = 1;
  long long k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (mod) ans %= mod;
    }
    k *= k;
    if (mod) k %= mod;
    m >>= 1;
  }
  return ans;
}
template <class t1, class t2>
inline void add(t1& a, t2 b, int mod = -1) {
  if (mod == -1) mod = 1000000007;
  a += b;
  while (a >= mod) a -= mod;
  while (a < 0) a += mod;
}
template <class t>
void output1(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) cerr << arr[i] << ' ';
  cerr << endl;
}
template <class t>
void output2(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) output1(arr[i]);
}
const int maxn = 100100;
char orig[maxn];
int str[2][maxn];
int sa[2][maxn], rk[2][maxn], h[2][maxn];
int n;
const int SA_MAXN = maxn;
int wa[SA_MAXN * 2], wb[SA_MAXN * 2], wv[SA_MAXN * 2], ws1[SA_MAXN * 2];
int cmp(int* r, int a, int b, int l) {
  return r[a] == r[b] && r[a + l] == r[b + l];
}
void da(int* r, int* sa, int n, int m) {
  int i, j, p, *x = wa, *y = wb, *t;
  for (i = 0; i < m; i++) ws1[i] = 0;
  for (i = 0; i < n; i++) ws1[x[i] = r[i]]++;
  for (i = 1; i < m; i++) ws1[i] += ws1[i - 1];
  for (i = n - 1; i >= 0; i--) sa[--ws1[x[i]]] = i;
  for (j = 1, p = 1; p <= n; j *= 2, m = p) {
    for (p = 0, i = n - j; i < n; i++) y[p++] = i;
    for (i = 0; i < n; i++)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    for (i = 0; i < n; i++) wv[i] = x[y[i]];
    for (i = 0; i < m; i++) ws1[i] = 0;
    for (i = 0; i < n; i++) ws1[wv[i]]++;
    for (i = 1; i < m; i++) ws1[i] += ws1[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--ws1[wv[i]]] = y[i];
    for (t = x, x = y, y = t, p = 2, x[sa[0]] = 1, i = 1; i < n; i++)
      x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
  }
  return;
}
void calheight(int* r, int* sa, int* rank, int* height, int n) {
  int i, j, k = 0;
  for (i = 0; i < n; i++) rank[sa[i]] = i;
  for (i = 0; i < n; i++) {
    if (rank[i] == 0) continue;
    for (k ? k-- : 0, j = sa[rank[i] - 1];
         i + k < n && j + k < n && r[i + k] == r[j + k]; k++)
      ;
    height[rank[i] - 1] = k;
  }
  return;
}
int d[22];
int logg[SA_MAXN];
int st[2][SA_MAXN][22];
void InitRMQ(const int& n, int h[][maxn]) {
  int i, j;
  for (d[0] = 1, i = 1; i < 21; ++i) d[i] = 2 * d[i - 1];
  for (int cate = 0; cate < 2; cate++) {
    for (i = 0; i < n; ++i) st[cate][i][0] = h[cate][i];
    int k = int(log(double(n)) / log(2)) + 1;
    logg[0] = 0;
    logg[1] = 0;
    for (int i = 2; i <= n; i++) logg[i] = logg[i / 2] + 1;
    for (j = 1; j < k; ++j)
      for (i = 0; i < n; ++i) {
        if (i + d[j - 1] - 1 < n) {
          st[cate][i][j] =
              min(st[cate][i][j - 1], st[cate][i + d[j - 1]][j - 1]);
        } else
          break;
      }
  }
}
inline int quelcp(int cate, int x, int y) {
  int k = logg[y - x + 1];
  return min(st[cate][x][k], st[cate][y - d[k] + 1][k]);
}
inline int quelcp1(int cate, int x, int y) {
  if (y < x) swap(x, y);
  if (x == y) return n - sa[cate][x];
  if (x >= n || y >= n || x < 0 || y < 0) return 0;
  y--;
  int k = logg[y - x + 1];
  return min(st[cate][x][k], st[cate][y - d[k] + 1][k]);
}
inline pair<int, int> querange(int cate, int no, int height, int l) {
  int be1 = 0, en1 = no - 1;
  while (be1 < en1) {
    int height1 = (be1 + en1) / 2;
    if (quelcp(cate, height1, no - 1) < height)
      be1 = height1 + 1;
    else
      en1 = height1;
  }
  if (quelcp(cate, be1, no - 1) < height) be1++;
  int from = min1(be1, no);
  be1 = no;
  en1 = l - 1;
  while (be1 < en1) {
    int height1 = (be1 + en1 + 1) / 2;
    if (quelcp(cate, no, height1) < height)
      en1 = height1 - 1;
    else
      be1 = height1;
  }
  if (quelcp(cate, no, be1) < height) be1--;
  int to = max1(be1 + 1, no);
  return make_pair(from, to);
}
struct OneNode {
  int loc, last_lcp;
  long long sum;
  void Init(int loc) {
    this->loc = loc;
    this->last_lcp = 0;
    sum = 1ll * (n - loc) * (loc + 1);
  }
  void Upd(const OneNode& pre, int base_lcp) {
    int new_lcp = quelcp1(0, rk[0][loc + 1], rk[0][pre.loc + 1]) + 1;
    sum -= (base_lcp + 1) * (new_lcp - last_lcp);
    last_lcp = new_lcp;
  }
} node_arr[maxn];
typedef map<int, OneNode*> MPType;
MPType mp_arr[maxn];
MPType* MergeTo(MPType* from, MPType* to, int lcp) {
  if (!from) return to;
  if (!to) return from;
  if (from->size() > to->size()) {
    return MergeTo(to, from, lcp);
  }
  for (const auto& it : *from) {
    assert(to->find(it.first) == to->end());
    auto rit = to->insert(it).first;
    auto rit1 = rit;
    if (rit != to->begin()) {
      rit1--;
      rit->second->Upd(*rit1->second, lcp);
    }
    rit1 = to->end();
    rit1--;
    if (rit != rit1) {
      rit1 = rit;
      rit1++;
      rit1->second->Upd(*rit->second, lcp);
    }
  }
  return to;
}
MPType* Dfs(int l, int r) {
  if (l == r) {
    int loc = l == -1 ? 0 : n - sa[1][l];
    if (loc == n) {
      return nullptr;
    }
    node_arr[l + 1].Init(loc);
    mp_arr[l + 1][rk[0][loc + 1]] = node_arr + l + 1;
    return mp_arr + l + 1;
  }
  MPType* ans = nullptr;
  int lcp = quelcp1(1, l, r);
  for (int st = l; st <= r; st++) {
    int be = st, en = r;
    while (be < en) {
      int mid = (be + en + 1) / 2;
      if (quelcp1(1, st, mid) > lcp) {
        be = mid;
      } else {
        en = mid - 1;
      }
    }
    if (ans) {
      ans = MergeTo(ans, Dfs(st, be), lcp);
    } else {
      ans = Dfs(st, be);
    }
    st = be;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%s", orig);
  n = strlen(orig);
  for (int i = 0; i < n; i++) {
    str[0][i] = orig[i] - 'a' + 1;
    str[1][n - i - 1] = orig[i] - 'a' + 1;
  }
  for (int i = 0; i < 2; i++) {
    da(str[i], sa[i], n, 30);
    calheight(str[i], sa[i], rk[i], h[i], n);
  }
  InitRMQ(n, h);
  rk[0][n] = n;
  auto ans_mp = Dfs(-1, n - 1);
  long long ans = 0;
  for (auto it : *ans_mp) {
    ans += it.second->sum;
  }
  ans += 1ll * n * (n + 1) / 2;
  for (int i = 0; i < n - 1; i++) ans -= h[0][i];
  cout << ans + 1 << endl;
  return 0;
}
