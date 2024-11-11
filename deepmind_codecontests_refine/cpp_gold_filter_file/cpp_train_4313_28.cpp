#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
using namespace std;
long long gcd(long long i, long long j) {
  if (j == 0)
    return i;
  else
    return gcd(j, i % j);
}
template <typename T>
inline T getint() {
  T val = 0;
  char c;
  bool neg = false;
  while ((c = getchar()) && !(c >= '0' && c <= '9')) {
    neg |= c == '-';
  }
  do {
    val = (val * 10) + c - '0';
  } while ((c = getchar()) && (c >= '0' && c <= '9'));
  return val * (neg ? -1 : 1);
}
const long long INF = 1e9 + 100;
const int mod = 1000000007;
const long double eps = 1e-10, pi = acosl(-1);
const long long maxN = 300010, maxT = 10010, A = 179, mid = 150;
mt19937 mt_rand(time(0));
long long bp(long long et, long long b) {
  b %= mod - 1;
  long long res = 1;
  for (int i = 30; i >= 0; --i) {
    res = (res * res) % mod;
    if ((b & (1 << i)) != 0) res = (res * et) % mod;
  }
  return res;
}
void panic() {
  cout << "-1\n";
  exit(0);
}
const int byben_size = 23;
vector<int> merge(const vector<int>& a, const vector<int>& b,
                  bool want_mx = true) {
  int s1 = a.size(), s2 = b.size();
  int sz = min(s1 + s2, byben_size);
  vector<int> r(sz);
  if (!want_mx) {
    int y1 = 0, y2 = 0;
    int y = 0;
    while (y < sz && y1 < s1 && y2 < s2) {
      if (a[y1] < b[y2])
        r[y++] = a[y1++];
      else
        r[y++] = b[y2++];
    }
    while (y < sz && y1 < s1) r[y++] = a[y1++];
    while (y < sz && y2 < s2) r[y++] = b[y2++];
  } else {
    int y1 = s1 - 1, y2 = s2 - 1;
    int y = sz - 1;
    while (y >= 0 && y1 >= 0 && y2 >= 0) {
      if (a[y1] > b[y2])
        r[y--] = a[y1--];
      else
        r[y--] = b[y2--];
    }
    while (y >= 0 && y1 >= 0) r[y--] = a[y1--];
    while (y >= 0 && y2 >= 0) r[y--] = b[y2--];
  }
  return r;
}
vector<int> t[1 << 18];
int sz = 1 << 17;
int a[maxN];
vector<int> l1[maxN], r1[maxN];
inline void add(int l, int r, int id, bool want_mx) {
  for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
    if (l & 1) {
      int v = l++;
      t[v].push_back(id);
      int szz = t[v].size();
      int rr = szz;
      --szz;
      while (szz > 0 && t[v][szz] < t[v][szz - 1]) {
        swap(t[v][szz], t[v][szz - 1]);
        --szz;
      }
      if (rr > byben_size) {
        if (want_mx)
          t[v].erase(t[v].begin());
        else
          t[v].pop_back();
      }
    }
    if (~r & 1) {
      int v = r--;
      t[v].push_back(id);
      int szz = t[v].size();
      int rr = szz;
      --szz;
      while (szz > 0 && t[v][szz] < t[v][szz - 1]) {
        swap(t[v][szz], t[v][szz - 1]);
        --szz;
      }
      if (rr > byben_size) {
        if (want_mx)
          t[v].erase(t[v].begin());
        else
          t[v].pop_back();
      }
    }
  }
}
vector<int> get(int v, bool want_mx) {
  vector<int> r;
  v |= sz;
  for (v = v | sz; v; v >>= 1) {
    r = merge(t[v], r, want_mx);
  }
  return r;
}
long double pw[maxT];
void solve() {
  pw[0] = 1;
  for (int i = 1; i < maxT; ++i) pw[i] = pw[i - 1] * 2;
  int n = getint<int>();
  for (int i = 1; i <= n; ++i) {
    a[i] = getint<int>();
  }
  add(0, sz - 1, 0, 1);
  for (int i = 1; i <= n; ++i) {
    add(0, a[i], i, 1);
    l1[i] = get(a[i], 1);
  }
  for (int i = 0; i < 2 * sz; ++i) t[i].clear();
  add(0, sz - 1, n + 1, 0);
  for (int i = n; i > 0; --i) {
    add(0, a[i], i, 0);
    r1[i] = merge({i}, get(a[i] + 1, 0), 0);
  }
  long double ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < l1[i].size(); ++j) {
      for (int k = 0; k + 1 < r1[i].size(); ++k) {
        long long cnt =
            (long long)(l1[i][j] - l1[i][j - 1]) * (r1[i][k + 1] - r1[i][k]);
        int pww = k + l1[i].size() - j;
        if (pww > byben_size) break;
        ans += (long double)cnt / pw[pww] * a[i];
      }
    }
  }
  cout << fixed << ans / n / n << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
