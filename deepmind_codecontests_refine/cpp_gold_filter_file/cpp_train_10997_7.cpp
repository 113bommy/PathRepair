#include <bits/stdc++.h>
using namespace std;
inline const int read() {
  int r = 0, k = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') k = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) r = r * 10 + c - '0';
  return r * k;
}
const double inf = 1e20;
const int N = 100010;
int n, q;
pair<int, int> p[N];
pair<pair<int, int>, int> t[N];
vector<pair<int, int> > h[N * 4];
vector<int> f[N * 4];
bool cmp(const pair<pair<int, int>, int> &A,
         const pair<pair<int, int>, int> &B) {
  if (A.first.second != B.first.second) return A.first.second < B.first.second;
  return A.first.first < B.first.first;
}
double getx(pair<int, int> A, pair<int, int> B) {
  int k1 = A.second, b1 = A.first;
  int k2 = B.second, b2 = B.first;
  if (k1 == k2)
    return -inf;
  else
    return (double)(b2 - b1) / (k1 - k2);
}
void build(int o, int L, int R) {
  for (int i = (L), _ = (R); i <= _; i++)
    t[i] = pair<pair<int, int>, int>(p[i], i);
  sort(t + L, t + R + 1, cmp);
  for (int i = (L), _ = (R); i <= _; i++) {
    while (h[o].size() >= 2 &&
           getx(h[o][h[o].size() - 2], h[o][h[o].size() - 1]) >=
               getx(h[o][h[o].size() - 1], t[i].first))
      h[o].pop_back(), f[o].pop_back();
    while (!h[o].empty() && h[o][h[o].size() - 1].first <= t[i].first.first &&
           h[o][h[o].size() - 1].second <= t[i].first.second)
      h[o].pop_back(), f[o].pop_back();
    h[o].push_back(t[i].first);
    f[o].push_back(t[i].second);
  }
  if (L == R) return;
  int mid = L + R >> 1;
  build(o << 1, L, mid);
  build(o << 1 | 1, mid + 1, R);
}
pair<long long, int> query(int o, long long t) {
  int l = 1, r = h[o].size() - 1, mid;
  while (l < r) {
    mid = l + r + 1 >> 1;
    if (t <= getx(h[o][mid], h[o][mid - 1]))
      r = mid - 1;
    else
      l = mid;
  }
  if (!r)
    return pair<long long, int>(h[o][0].first + h[o][0].second * t, f[o][0]);
  long long t1 = h[o][l - 1].first + h[o][l - 1].second * t,
            t2 = h[o][l].first + h[o][l].second * t;
  if (t1 > t2)
    return pair<long long, int>(t1, f[o][l - 1]);
  else
    return pair<long long, int>(t2, f[o][l]);
}
pair<long long, int> query(int l, int r, int t, int o, int L, int R) {
  if (l <= L && R <= r) return query(o, t);
  int mid = L + R >> 1;
  if (r <= mid)
    return query(l, r, t, o << 1, L, mid);
  else if (l > mid)
    return query(l, r, t, o << 1 | 1, mid + 1, R);
  else
    return max(query(l, mid, t, o << 1, L, mid),
               query(mid + 1, r, t, o << 1 | 1, mid + 1, R));
}
int getans(int l, int r, int t) { return query(l, r, t, 1, 1, n).second; }
void input() {
  n = read();
  q = read();
  for (int i = (1), _ = (n); i <= _; i++) {
    int a = read(), b = read();
    p[i] = pair<int, int>(a, b);
  }
}
void solve() {
  build(1, 1, n);
  while (q--) {
    int l = read(), r = read(), t = read();
    printf("%d\n", getans(l, r, t));
  }
}
int main() {
  input(), solve();
  return 0;
}
