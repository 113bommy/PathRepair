#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}
struct segtree {
  long long n;
  vector<pair<long long, long long>> dat;
  vector<long long> put;
  void init(vector<pair<long long, long long>> &v) {
    n = 1;
    while (n < v.size()) n *= 2;
    dat = vector<pair<long long, long long>>(n * 2, {INT_MAX, -1});
    put = vector<long long>(n * 2);
    for (long long i = 0; i < v.size(); i++)
      dat[i + n - 1] = pair<long long, long long>(0, v[i].second);
    for (long long i = n - 2; i >= 0; i--)
      dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
  }
  inline void push(long long k) {
    dat[k].first += put[k];
    if (k < n - 1) {
      put[k * 2 + 1] += put[k];
      put[k * 2 + 2] += put[k];
    }
    put[k] = 0;
  }
  void add(long long a, long long b, long long x) { add(a, b, x, 0, 0, n); }
  void add(long long a, long long b, long long x, long long k, long long l,
           long long r) {
    push(k);
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      put[k] += x;
      push(k);
      return;
    }
    add(a, b, x, k * 2 + 1, l, (l + r) / 2);
    add(a, b, x, k * 2 + 2, (l + r) / 2, r);
    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
  pair<long long, long long> query(long long a, long long b) {
    return query(a, b, 0, 0, n);
  }
  pair<long long, long long> query(long long a, long long b, long long k,
                                   long long l, long long r) {
    push(k);
    if (r <= a || b <= l) return {INT_MAX, -1};
    if (a <= l && r <= b) return dat[k];
    return min(query(a, b, k * 2 + 1, l, (l + r) / 2),
               query(a, b, k * 2 + 2, (l + r) / 2, r));
  }
};
long long H, W;
vector<long long> A[111111];
vector<pair<long long, long long>> vec[111111];
segtree seg[111111];
vector<long long> idx[111111];
signed main() {
  scanf("%lld%lld", &H, &W);
  for (long long i = 0; i < (H); i++) {
    A[i].resize(W);
    for (long long j = 0; j < (W); j++) scanf("%lld", &A[i][j]);
  }
  for (long long i = 0; i < (H); i++) {
    for (long long j = 0; j < (W); j++)
      if (A[i][j] != -1) vec[i].push_back({A[i][j], j});
    sort((vec[i]).begin(), (vec[i]).end());
    seg[i].init(vec[i]);
    idx[i] = vector<long long>(W, -1);
    for (long long j = 0; j < vec[i].size(); j++) {
      long long k =
          lower_bound((vec[i]).begin(), (vec[i]).end(),
                      pair<long long, long long>(vec[i][j].first + 1, -1)) -
          vec[i].begin();
      seg[i].add(k, vec[i].size(), 1);
      idx[i][vec[i][j].second] = j;
    }
  }
  priority_queue<long long, vector<long long>, greater<long long>> que;
  vector<long long> cnt(W);
  for (long long j = 0; j < (W); j++) {
    for (long long i = 0; i < (H); i++)
      if (idx[i][j] != -1) {
        if (seg[i].query(idx[i][j], idx[i][j] + 1).first)
          cnt[j]++;
        else
          seg[i].add(idx[i][j], idx[i][j] + 1, INT_MAX);
      }
    if (cnt[j]) continue;
    que.push(j);
  }
  vector<long long> ans;
  while (que.size()) {
    long long v = que.top();
    que.pop();
    ans.push_back(v);
    for (long long i = 0; i < (H); i++) {
      if (idx[i][v] == -1) continue;
      long long k = lower_bound((vec[i]).begin(), (vec[i]).end(),
                                pair<long long, long long>(A[i][v] + 1, -1)) -
                    vec[i].begin();
      seg[i].add(k, vec[i].size(), -1);
      while (true) {
        auto w = seg[i].query(0, vec[i].size());
        if (w.first > 0) break;
        seg[i].add(idx[i][w.second], idx[i][w.second] + 1, INT_MAX);
        cnt[w.second]--;
        if (cnt[w.second]) continue;
        que.push(w.second);
      }
    }
  }
  if (ans.size() != W) {
    puts("-1");
    return 0;
  }
  for (long long i = 0; i < (ans.size()); i++) printf("%lld ", ans[i] + 1);
  puts("");
  return 0;
}
