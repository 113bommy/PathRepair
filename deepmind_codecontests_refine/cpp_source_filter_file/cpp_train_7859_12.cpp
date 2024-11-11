#include <bits/stdc++.h>
using namespace std;
template <typename T>
void write(ostream& out, T t) {
  out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
  out << t << ' ';
  write(out, args...);
}
template <typename... Args>
void debug(Args... args) {}
template <typename T>
inline T abs(T t) {
  return t < 0 ? -t : t;
}
const long long modn = 1000000007;
const long long modn2 = 10000019;
inline long long mod(long long x) { return x % modn; }
const int MAXK = 1003, MAXQ = 2 * 30004 + 10010;
const int MAXN = MAXQ;
const long long INF = 9000000000000LL;
int n, m, k;
vector<pair<long long, int> > s;
long long dp[15000][MAXK];
void prep_cin() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
struct qry {
  int t, id;
};
vector<qry> q;
int L[MAXN], R[MAXN];
int acu[MAXN];
long long pot[MAXK];
int h;
inline long long f(int h) {
  long long res = 0;
  long long mx = 0;
  for (int a = 1; a <= k; a++) {
    mx = max(mx, dp[h][a]);
    res = mod(res + mod(mx) * pot[a - 1]);
  }
  return res;
}
inline bool sup(int i, int j, int l, int r) { return (i < l && j > r); }
inline void add(int id) {
  h++;
  int pes = s[id].second;
  long long val = s[id].first;
  for (int a = 0; a <= k; a++) {
    dp[h][a] = dp[h - 1][a];
    if (a >= pes) dp[h][a] = max(dp[h][a], dp[h - 1][a - pes] + val);
  }
}
void go(int i, int j) {
  if (i == j) {
    if (q[i].t == 3) printf("%lld\n", f(h));
    return;
  }
  int m = (i + j) / 2;
  if (acu[m] - (i == 0 ? 0 : acu[i - 1]) != 0) {
    int old = h;
    for (int a = m + 1; a <= j; a++) {
      if (q[a].t == 1 || q[a].t == 3) continue;
      int id = q[a].id;
      if (sup(L[id], R[id], i, m)) add(id);
    }
    go(i, m);
    h = old;
  }
  if (acu[j] - acu[m] != 0) {
    int old = h;
    for (int a = i; a <= m; a++) {
      if (q[a].t == 2 || q[a].t == 3) continue;
      int id = q[a].id;
      if (sup(L[id], R[id], m + 1, j)) add(id);
    }
    go(m + 1, j);
    h = old;
  }
}
int main() {
  scanf("%d%d", &n, &k);
  pot[0] = 1;
  for (int a = 1; a < k; a++) pot[a] = mod(pot[a - 1] * modn2);
  const int inf = 1e7;
  for (int a = 0; a < n; a++) {
    pair<long long, int> x;
    scanf("%lld %d", &x.first, &x.second);
    s.push_back(x);
    q.push_back({1, a});
    L[a] = a;
    R[a] = inf;
  }
  scanf("%d", &m);
  for (int a = 0; a < m; a++) {
    qry p;
    scanf("%d", &p.t);
    if (q.size() > 0) acu[q.size()] = acu[q.size() - 1];
    if (p.t == 1) {
      pair<long long, int> x;
      scanf("%lld %d", &x.first, &x.second);
      s.push_back(x);
      p.id = (int)s.size() - 1;
      L[p.id] = q.size();
      R[p.id] = inf;
    } else if (p.t == 2) {
      scanf("%d", &p.id);
      p.id--;
      R[p.id] = q.size();
    } else
      acu[q.size()]++;
    q.push_back(p);
  }
  n = s.size();
  m = q.size();
  for (int a = 0; a <= k; a++) dp[0][a] = -INF;
  dp[0][0] = 0;
  go(0, m - 1);
}
