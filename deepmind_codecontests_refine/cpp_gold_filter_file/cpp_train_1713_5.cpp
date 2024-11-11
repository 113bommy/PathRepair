#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 10;
static vector<int> V[MAXN], q[MAXN];
static vector<pair<int, int> > c[MAXN];
static pair<int, int> w[MAXN];
static int n, m, N, a[MAXN], b[MAXN], p[MAXN], Tohka[MAXN], sum[MAXN], id[MAXN];
inline int lowbit(int first) { return first & -first; }
inline void Add(int first, pair<int, int> d) {
  for (; first <= N; c[first].push_back(d), first += lowbit(first))
    ;
}
inline void Gets(int first, int d) {
  for (; first; q[first].push_back(d), first -= lowbit(first))
    ;
}
inline double calc1(const pair<int, int> &w, const double &first) {
  return first * w.first + w.second;
}
inline int calc2(const pair<int, int> &w, const int &first) {
  return first * w.first + w.second;
}
inline double Inter(const pair<int, int> &a, const pair<int, int> &b) {
  return (double)(b.second - a.second) / (a.first - b.first);
}
int T, T1, cnt;
inline void Calc(vector<pair<int, int> > &W, vector<int> &q) {
  static int s[MAXN], top, n;
  static double first[MAXN];
  static pair<int, int> w[MAXN];
  s[top = 1] = 0;
  n = (int)W.size();
  for (int i = 0; i < n; ++i) w[i] = W[i];
  for (int i = 1; i < n; ++i) {
    pair<int, int> wi = w[i];
    for (; top > 1 && first[top - 1] * (w[s[top]].first - wi.first) >=
                          wi.second - w[s[top]].second;
         --top, ++cnt)
      ;
    s[++top] = i;
    if (top > 1) first[top - 1] = Inter(w[s[top - 1]], wi), ++cnt;
  }
  for (int t = 1, i = 0; i < (int)q.size(); ++i) {
    for (; t < top && calc2(w[s[t]], b[q[i]] - p[q[i]]) >=
                          calc2(w[s[t + 1]], b[q[i]] - p[q[i]]);
         ++t)
      ;
    Tohka[q[i]] =
        min(Tohka[q[i]], (int)calc2(w[s[t]], b[q[i]] - p[q[i]]) + sum[p[q[i]]]);
  }
  W.clear();
  q.clear();
}
inline bool cmp(int a, int b) { return w[a] > w[b]; }
inline bool cmp1(int first, int second) {
  return b[first] - p[first] < b[second] - p[second];
}
void solve(int dep, int l, int r) {
  if (l == r) {
    vector<int> &v = V[l];
    for (int i = 0; i < (int)v.size(); ++i)
      Tohka[v[i]] = min(Tohka[v[i]], a[l] * b[v[i]]);
    return;
  }
  int mid = (l + r) >> 1;
  solve(dep + 1, l, mid);
  solve(dep + 1, mid + 1, r);
  N = mid - l + 1;
  for (int i = l; i <= mid; ++i)
    w[i - l + 1] = make_pair(a[i], a[i] * i - sum[i]),
              id[i - l + 1] = i - l + 1;
  sort(id + 1, id + N + 1, cmp);
  for (int i = 1; i <= N; ++i) Add(N - id[i] + 1, w[id[i]]);
  vector<int> s;
  for (int i = mid + 1; i <= r; ++i) {
    vector<int> &v = V[i];
    for (int j = 0; j < (int)v.size(); ++j) s.push_back(v[j]);
  }
  sort(s.begin(), s.end(), cmp1);
  for (int i = 0; i < (int)s.size(); ++i) {
    int h = max(p[s[i]] - b[s[i]] + 1, l);
    if (h > mid) continue;
    Gets(mid - h + 1, s[i]);
  }
  for (int i = 1; i <= N; ++i) Calc(c[i], q[i]);
}
int main() {
  memset(Tohka, 0x3f, sizeof(Tohka));
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int first;
    scanf("%d%d", &b[i], &first);
    V[first].push_back(i);
    p[i] = first;
  }
  solve(1, 1, n);
  for (int i = 1; i <= m; ++i) printf("%d\n", Tohka[i]);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
