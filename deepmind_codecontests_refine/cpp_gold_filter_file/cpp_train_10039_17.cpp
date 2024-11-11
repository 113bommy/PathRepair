#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 10;
long long n, k, q, N;
long long seg[maxn << 2], la[maxn << 2], a[maxn];
void build(long long v = 1, long long tl = 0, long long tr = n - 1) {
  la[v] = 0;
  if (tl == tr) {
    seg[v] = -tl;
    return;
  }
  long long tm = (tl + tr) >> 1;
  build(v << 1, tl, tm);
  build(v << 1 | 1, tm + 1, tr);
  seg[v] = min(seg[v << 1], seg[v << 1 | 1]);
}
void shift(long long v) {
  seg[v] += la[v];
  if ((v << 1) < (maxn << 2)) {
    la[v << 1] += la[v];
    la[v << 1 | 1] += la[v];
  }
  la[v] = 0;
}
void up(long long l, long long r, long long val, long long v = 1,
        long long tl = 0, long long tr = n - 1) {
  if (tl == l && tr == r) {
    la[v] += val;
    shift(v);
    return;
  }
  shift(v);
  if (l > r) return;
  long long tm = (tl + tr) >> 1;
  up(l, min(tm, r), val, v << 1, tl, tm);
  up(max(tm + 1, l), r, val, v << 1 | 1, tm + 1, tr);
  seg[v] = min(seg[v << 1], seg[v << 1 | 1]);
}
long long find(long long val, long long l, long long r, long long v = 1,
               long long tl = 0, long long tr = n - 1) {
  shift(v);
  if (seg[v] > val || l > r) return -inf;
  if (tl == tr) return tl;
  long long tm = (tl + tr) >> 1;
  long long X = find(val, max(tm + 1, l), r, v << 1 | 1, tm + 1, tr);
  if (X != -inf) return X;
  return find(val, l, min(tm, r), v << 1, tl, tm);
}
pair<long long, long long> ANS(vector<long long> a) {
  n = a.size();
  vector<pair<pair<long long, long long>, long long>> stmx, stmn;
  map<long long, long long> lst;
  long long lmx[n + 1];
  memset(lmx, 0, sizeof lmx);
  lmx[n] = n;
  build();
  pair<long long, long long> ans;
  for (long long l = n - 1; l >= 0; l--) {
    lmx[l] = lmx[l + 1];
    if (lst[a[l]]) lmx[l] = min(lmx[l], lst[a[l]] - 1);
    lst[a[l]] = l;
    long long R = l;
    if (stmx.size())
      while (a[l] > stmx.back().second) {
        up(stmx.back().first.first, stmx.back().first.second,
           a[l] - stmx.back().second);
        R = stmx.back().first.second;
        stmx.pop_back();
        if (stmx.empty()) break;
      }
    stmx.push_back({{l, R}, a[l]});
    R = l;
    if (stmn.size())
      while (a[l] < stmn.back().second) {
        up(stmn.back().first.first, stmn.back().first.second,
           stmn.back().second - a[l]);
        R = stmn.back().first.second;
        stmn.pop_back();
        if (stmn.empty()) break;
      }
    stmn.push_back({{l, R}, a[l]});
    R = find(k - l, l, lmx[l]);
    if (R - l >= ans.second - ans.first) ans = {l, R};
  }
  return ans;
}
signed main() {
  long long d;
  cin >> N >> k >> d;
  vector<long long> A;
  pair<long long, long long> ans = {1, 0};
  long long nm = 0;
  pair<long long, long long> ansd0 = {1, 0};
  for (long long i = 1; i <= N + 1; i++) {
    if (i <= N) cin >> a[i];
    if (d == 0) {
      if (a[i] != a[i - 1] || i > N) {
        if (nm > ansd0.second - ansd0.first + 1) ansd0 = {i - nm, i - 1};
        nm = 0;
      }
      nm++;
    } else {
      if (i > 1)
        if (((a[i] % d + d) % d != (a[i - 1] % d + d) % d) || i > N) {
          pair<long long, long long> X = ANS(A);
          X.first += i - A.size();
          X.second += i - A.size();
          if (X.second - X.first > ans.second - ans.first) ans = X;
          A.clear();
        }
      A.push_back((a[i] - (a[i] % d + d) % d) / d);
    }
  }
  if (d == 0)
    cout << ansd0.first << " " << ansd0.second << "\n";
  else
    cout << ans.first << " " << ans.second;
}
