#include <bits/stdc++.h>
using namespace std;
template <class T>
using v2d = vector<vector<T>>;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int maxN = 2e4 + 10;
const int maxK = 1e2 + 10;
const long long inf = 1e15;
int n, k, h[maxN];
long long a[maxN], f[maxN], g[maxN], c[maxN];
vector<int> sorted, adj[maxN];
stack<int> st;
bool flag[maxN];
struct Line {
  long long a, b;
  Line(long long a, long long b) : a(a), b(b) {}
  long long intersect(Line d) {
    return floor((long double)(a - d.a) / (d.b - b));
  }
  long long valueAt(long long x) { return a * x + b; }
};
template <bool P>
struct PCHT {
  deque<Line> hull;
  stack<pair<Line, bool>> s;
  void addLine(Line d) {
    while ((int)hull.size() >= 2 &&
           d.intersect(hull.back()) <=
               hull.back().intersect(hull[(int)hull.size() - 2])) {
      if (P) {
        s.emplace(hull.back(), 1);
      }
      hull.pop_back();
    }
    if (P) {
      s.emplace(d, 0);
    }
    hull.push_back(d);
  }
  void rollback() {
    do {
      if (s.top().second) {
        hull.push_back(s.top().first);
      } else {
        hull.pop_back();
      }
      s.pop();
    } while (!s.empty() && s.top().second);
  }
  long long query(long long x) {
    int l = 0, r = (int)hull.size();
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (hull[mid].valueAt(x) <= hull[mid - 1].valueAt(x)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return hull[l].valueAt(x);
  }
};
PCHT<0> b[maxN * 4];
PCHT<1> cur;
int L, R;
long long val;
void build(int x, int lo, int hi) {
  b[x] = PCHT<0>();
  for (int i = (int)(lo); i <= (int)(hi); ++i) {
    b[x].addLine(Line(-i, f[i]));
  }
  if (lo < hi) {
    int mid = (lo + hi) / 2;
    build(x * 2, lo, mid);
    build(x * 2 + 1, mid + 1, hi);
  }
}
long long query(int x, int lo, int hi) {
  if (lo > R || hi < L) {
    return inf;
  }
  if (lo >= L && hi <= R) {
    return b[x].query(val);
  }
  int mid = (lo + hi) / 2;
  return min(query(x * 2, lo, mid), query(x * 2 + 1, mid + 1, hi));
}
void dfs(int u) {
  flag[u] = 1;
  cur.addLine(Line(a[u], c[u]));
  g[u] = cur.query(u);
  for (auto &v : adj[u]) {
    if (!flag[v]) {
      dfs(v);
    }
  }
  cur.rollback();
}
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= (int)(n); ++i) {
    cin >> a[i];
  }
  f[0] = inf;
  long long mx = -inf;
  for (int i = 1; i <= (int)(n); ++i) {
    uax(mx, a[i]);
    f[i] = i * mx;
  }
  sorted.resize(n);
  iota((sorted).begin(), (sorted).end(), 1);
  sort((sorted).begin(), (sorted).end(),
       [](int i, int j) { return a[i] < a[j]; });
  for (int i = 1; i <= (int)(n); ++i) {
    while (!st.empty() && a[st.top()] <= a[i]) {
      st.pop();
    }
    if (!st.empty()) {
      h[i] = st.top();
      adj[st.top()].emplace_back(i);
    }
    st.push(i);
  }
  for (int t = (int)(2); t <= (int)(k); ++t) {
    build(1, 0, n - 1);
    for (auto &i : sorted) {
      L = h[i], R = i - 1, val = a[i];
      c[i] = query(1, 0, n - 1);
    }
    fill(flag + 1, flag + n + 1, 0);
    for (int i = 1; i <= (int)(n); ++i) {
      if (!flag[i]) {
        dfs(i);
      }
    }
    copy(g + 1, g + n + 1, f + 1);
  }
  cout << f[n];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
