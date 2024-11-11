#include <bits/stdc++.h>
using namespace std;
void dbg() { std::cout << "  #\n"; }
template <typename T, typename... Args>
void dbg(T a, Args... args) {
  std::cout << a << ' ';
  dbg(args...);
}
const long long maxn = 1e6 + 10;
const long long MAX = 1000;
const long long inf = 1e9;
const long long mod = 1e9 + 7;
long long n, w;
vector<long long> a[maxn];
struct segment_tree {
  long long x, y, z, w;
} tr[maxn * 4];
void pushup(long long k) { tr[k].z = max(tr[k * 2].z, tr[k * 2 + 1].z); }
void pushdown(long long k) {
  long long w = tr[k].w;
  tr[k * 2].w += w;
  tr[k * 2].z += w;
  tr[k * 2 + 1].w += w;
  tr[k * 2 + 1].z += w;
  tr[k].w = 0;
}
void build(long long i, long long k, long long l, long long r) {
  tr[k].w = 0, tr[k].x = l, tr[k].y = r;
  if (l == r) {
    tr[k].z = a[i][l - 1];
    return;
  }
  long long mid = (l + r) / 2;
  build(i, k * 2, l, mid);
  build(i, k * 2 + 1, mid + 1, r);
  pushup(k);
}
void update(long long k, long long l, long long r, long long w) {
  if (tr[k].y < l || tr[k].x > r) return;
  if (l <= tr[k].x && tr[k].y <= r) {
    tr[k].w += w;
    tr[k].z += w;
    return;
  }
  if (tr[k].w) pushdown(k);
  update(k * 2, l, r, w);
  update(k * 2 + 1, l, r, w);
  pushup(k);
}
long long query(long long k, long long l, long long r) {
  if (tr[k].y < l || tr[k].x > r) return -inf;
  if (l <= tr[k].x && tr[k].y <= r) {
    return tr[k].z;
  }
  if (tr[k].w) pushdown(k);
  return max(query(k * 2, l, r), query(k * 2 + 1, l, r));
}
long long ans[maxn];
void solve() {
  cin >> n >> w;
  for (long long i = (1); i <= (n); ++i) {
    long long num;
    cin >> num;
    for (long long j = (1); j <= (num); ++j) {
      long long x;
      cin >> x;
      a[i].push_back(x);
    }
  }
  for (long long i = (1); i <= (n); ++i) {
    long long l = a[i].size();
    build(i, 1, 1, l);
    if (l * 2 < w + 1) {
      long long maxx = 0;
      for (long long j = (1); j <= (l); ++j) {
        maxx = max(maxx, a[i][j - 1]);
        ans[j] += maxx;
        ans[j + 1] -= maxx;
      }
      maxx = 0;
      long long pos = l - 1;
      for (long long j = (w); j >= (w - l + 1); --j) {
        maxx = max(maxx, a[i][pos]);
        ans[j] += maxx;
        ans[j + 1] -= maxx;
        pos--;
      }
      maxx = max(0ll, *max_element((a[i]).begin(), (a[i]).end()));
      ans[l + 1] += maxx;
      ans[w - l + 1] -= maxx;
    } else {
      long long maxx = 0;
      for (long long j = (1); j <= (w - l); ++j) {
        maxx = max(maxx, a[i][j - 1]);
        ans[j] += maxx;
        ans[j + 1] -= maxx;
      }
      maxx = 0;
      long long pos = l - 1;
      for (long long j = (w); j >= (l + 1); --j) {
        maxx = max(maxx, a[i][pos]);
        ans[j] += maxx;
        ans[j + 1] -= maxx;
        pos--;
      }
      for (long long j = (w - l + 1); j <= (l); ++j) {
        maxx = query(1, j - w + l, j);
        ans[j] += maxx;
        ans[j + 1] -= maxx;
      }
    }
  }
  for (long long i = (1); i <= (w); ++i) {
    ans[i] += ans[i - 1];
    cout << ans[i] << " \n"[i == n];
  }
}
signed main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long T = 1;
  while (T--) {
    solve();
  }
}
