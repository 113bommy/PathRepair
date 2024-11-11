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
inline void add(t1 &a, t2 b, int mod = -1) {
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
const int maxn = 2210;
const int inff = 0x3f3f3f3f;
const int infc = 0x3f3f3f3f;
const int E = 700100;
const int N = maxn * 10;
struct network {
  int nv, ne, pnt[E], nxt[E];
  int vis[N], que[N], head[N], pv[N], pe[N];
  int flow, cap[E];
  int cost, dis[E], d[N];
  void addedge(int u, int v, int c, int w) {
    pnt[ne] = v;
    cap[ne] = c;
    dis[ne] = +w;
    nxt[ne] = head[u];
    head[u] = (ne++);
    pnt[ne] = u;
    cap[ne] = 0;
    dis[ne] = -w;
    nxt[ne] = head[v];
    head[v] = (ne++);
  }
  int mincost(int src, int sink) {
    int i, k, f, r;
    int mxf;
    for (flow = 0, cost = 0;;) {
      memset(pv, -1, sizeof(pv));
      memset(vis, 0, sizeof(vis));
      for (i = 0; i < nv; ++i) d[i] = infc;
      d[src] = 0;
      pv[src] = src;
      vis[src] = 1;
      for (f = 0, r = 1, que[0] = src; r != f;) {
        i = que[f++];
        vis[i] = 0;
        if (N == f) f = 0;
        for (k = head[i]; k != -1; k = nxt[k])
          if (cap[k] && dis[k] + d[i] < d[pnt[k]]) {
            d[pnt[k]] = dis[k] + d[i];
            if (0 == vis[pnt[k]]) {
              vis[pnt[k]] = 1;
              que[r++] = pnt[k];
              if (N == r) r = 0;
            }
            pv[pnt[k]] = i;
            pe[pnt[k]] = k;
          }
      }
      if (-1 == pv[sink]) break;
      for (k = sink, mxf = inff; k != src; k = pv[k])
        if (cap[pe[k]] < mxf) mxf = cap[pe[k]];
      flow += mxf;
      cost += d[sink] * mxf;
      for (k = sink; k != src; k = pv[k]) {
        cap[pe[k]] -= mxf;
        cap[pe[k] ^ 1] += mxf;
      }
    }
    return cost;
  }
  void init(int v) {
    nv = v;
    ne = 0;
    memset(head, -1, sizeof(head));
  }
} g;
int n;
pair<long long, long long> co[maxn * 2];
int arr1[maxn * 2], arr2[maxn * 2];
int loc[maxn * 2], cnt[maxn * 2];
long long GetValue(int no, long long t) {
  return co[no].first * t + co[no].second;
}
bool Judge(long long mid) {
  for (int i = 0; i < 2 * n; i++) {
    arr1[i] = i;
    arr2[i] = i;
  }
  sort(arr1, arr1 + 2 * n, [&](const int &a, const int &b) {
    if (co[a].second == co[b].second) {
      if (GetValue(a, mid) == GetValue(b, mid)) {
        return a < b;
      }
      return GetValue(a, mid) > GetValue(b, mid);
    }
    return co[a].second < co[b].second;
  });
  sort(arr2, arr2 + 2 * n, [&](const int &a, const int &b) {
    if (GetValue(a, mid) == GetValue(b, mid)) {
      if (co[b].second == co[a].second) {
        return a < b;
      }
      return co[b].second < co[a].second;
    }
    return GetValue(a, mid) < GetValue(b, mid);
  });
  for (int i = 0; i < 2 * n; i++) loc[arr2[i]] = i;
  memset(cnt, 0, sizeof(cnt));
  int rmax_loc = -1;
  for (int i = 0; i < 2 * n; i++) {
    rmax_loc = max(loc[arr1[i]], rmax_loc);
    if (arr1[i] < n) cnt[rmax_loc]++;
  }
  for (int i = 2 * n, sum = 0; i >= 0; i--) {
    sum += cnt[i];
    if (arr2[i] >= n) sum--;
    if (sum < 0) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long l = 0, r = 1ll << 31;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    scanf("%I64d%I64d", &co[i].first, &co[i].second);
  }
  while (l != r) {
    long long mid = (l + r) / 2;
    if (!Judge(mid)) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  if (!Judge(l)) {
    puts("-1");
  } else {
    int src = n * 8, sink = n * 8 + 1;
    g.init(n * 8 + 2);
    for (int i = 0; i < 2 * n; i++) {
      if (i < n) {
        g.addedge(src, i, 1, 0);
      } else {
        g.addedge(i + 2 * n, sink, 1, 0);
      }
      g.addedge(i, i + 2 * n, n, 0);
      g.addedge(arr2[i] + 2 * n, arr2[i] + 4 * n, n, 1);
      g.addedge(arr2[i] + 4 * n, arr2[i] + 2 * n, 1, 0);
      g.addedge(arr1[i], arr1[i] + 6 * n, 1, 1);
      g.addedge(arr1[i] + 6 * n, arr1[i], n, 0);
      if (i) {
        g.addedge(arr1[i] + 6 * n, arr1[i - 1] + 6 * n, n, 0);
        g.addedge(arr2[i] + 4 * n, arr2[i - 1] + 4 * n, n, 0);
      }
    }
    printf("%I64d %d\n", l, g.mincost(src, sink));
  }
  return 0;
}
