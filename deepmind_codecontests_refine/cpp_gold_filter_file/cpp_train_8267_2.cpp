#include <bits/stdc++.h>
using namespace std;
inline long long in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
char ch[4000010];
inline string get() {
  scanf("%s", ch);
  return string(ch);
}
inline void read(long long *a, long long n) {
  for (long long i = 0; i < n; i++) a[i] = in();
}
template <class blank>
inline void out(blank x) {
  cout << x << "\n";
  exit(0);
}
template <class blank, class blank2>
inline void smin(blank &a, blank2 b) {
  a = a <= b ? a : b;
}
template <class blank, class blank2>
inline void smax(blank &a, blank2 b) {
  a = a >= b ? a : b;
}
const long long maxn = 1e6 + 10;
const long long maxm = 4e6 + 10;
const long long maxlg = 20;
const long long base = 29;
const long long mod = 1e9 + 7;
const long long inf = 2e18 + 10;
const double eps = 1e-9;
const long long SQ = 320;
vector<long long> g[maxn];
long long u[maxn], v[maxn];
bool mark[maxn], mrk[maxn];
vector<pair<long long, long long> > res;
inline long long dfs(long long node) {
  mark[node] = true;
  vector<long long> E;
  for (auto e : g[node])
    if (!mrk[e]) E.push_back(e), mrk[e] = true;
  vector<long long> st;
  for (auto e : E) {
    long long nxt = node ^ u[e] ^ v[e];
    if (!mark[nxt]) {
      long long rem = dfs(nxt);
      if (rem == -1)
        st.push_back(e);
      else
        res.push_back({rem, e});
    } else
      st.push_back(e);
  }
  while (st.size() >= 2) {
    long long f = st.back();
    st.pop_back();
    long long s = st.back();
    st.pop_back();
    res.push_back({f, s});
  }
  if (st.size()) return st.back();
  return -1;
}
int32_t main() {
  long long n = in(), m = in();
  if (m % 2) out("No solution\n");
  for (long long i = 0; i < m; i++) {
    v[i] = in(), u[i] = in();
    g[v[i]].push_back(i), g[u[i]].push_back(i);
  }
  dfs(1);
  for (auto e : res) {
    if (v[e.second] != u[e.first]) swap(v[e.second], u[e.second]);
    if (v[e.second] != u[e.first]) {
      swap(v[e.first], u[e.first]);
      if (v[e.second] != u[e.first]) swap(v[e.second], u[e.second]);
    }
    cout << v[e.first] << " " << u[e.first] << " " << u[e.second] << "\n";
  }
}
