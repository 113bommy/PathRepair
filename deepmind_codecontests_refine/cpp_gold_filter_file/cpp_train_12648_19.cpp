#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
const int LEN = 320;
int N, a[MAX_N], id[MAX_N], bel[MAX_N], L[LEN], R[LEN];
long long tk[LEN], tb[LEN], f[MAX_N], ans;
double slope(int i, int j) {
  if (a[i] == a[j])
    return f[i] > f[j] ? -1e20 : 1e20;
  else
    return (double)(f[i] - f[j]) / (a[i] - a[j]);
}
long long calc(int i) { return f[i] + tk[bel[i]] * a[i] + tb[bel[i]]; }
struct Hull {
  deque<int> q;
  void clear() { q.clear(); }
  void insert(int i) {
    while (q.size() > 1 &&
           slope(q[q.size() - 2], q[q.size() - 1]) < slope(q[q.size() - 1], i))
      q.pop_back();
    q.push_back(i);
  }
  pair<long long, int> query() {
    while (q.size() > 1 && calc(q[0]) <= calc(q[1])) q.pop_front();
    return make_pair(calc(q[0]), q[0]);
  }
} S[LEN];
void modify(int l, int ed, int k, int b) {
  while (l <= ed) {
    int x = bel[l], r = min(R[x], ed);
    if (l == L[x] && r == R[x])
      tk[x] += k, tb[x] += b;
    else
      for (int i = l; i <= r; i++) f[i] += 1ll * k * a[i] + b;
    l = r + 1;
  }
}
pair<long long, int> query(int l, int ed) {
  pair<long long, int> res = make_pair(0, 0);
  while (l <= ed) {
    int x = bel[l], r = min(R[x], ed);
    if (l == L[x] && r == R[x])
      res = max(res, S[x].query());
    else
      for (int i = l; i <= r; i++) res = max(res, make_pair(calc(i), i));
    l = r + 1;
  }
  return res;
}
void build(int x) {
  for (int i = L[x]; i <= R[x]; i++) f[i] += tk[x] * a[i] + tb[x];
  tk[x] = tb[x] = 0, S[x].clear();
  for (int i = L[x]; i <= R[x]; i++) S[x].insert(id[i]);
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", a + i);
    f[i] = a[i], id[i] = i;
    bel[i] = (i - 1) / LEN + 1;
    if (!L[bel[i]]) L[bel[i]] = i;
    R[bel[i]] = i;
  }
  for (int i = 1; i <= bel[N]; i++)
    sort(&id[L[i]], &id[R[i] + 1], [](int l, int r) { return a[l] < a[r]; }),
        build(i);
  long long ans = 0;
  while (1) {
    pair<long long, int> res = query(1, N);
    if (res.first <= 0) break;
    ans += res.first;
    f[res.second] = -1ll << 60;
    if (res.second > 1) modify(1, res.second - 1, 0, a[res.second]);
    if (res.second < N) modify(res.second + 1, N, 1, 0);
    build(bel[res.second]);
  }
  printf("%lld\n", ans);
  return 0;
}
