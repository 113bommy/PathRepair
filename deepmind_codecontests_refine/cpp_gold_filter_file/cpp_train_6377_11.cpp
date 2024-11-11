#include <bits/stdc++.h>
using namespace std;
void itval(istream_iterator<string> it) {}
template <typename T, typename... Args>
void itval(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  itval(++it, args...);
}
const long long int MOD = 1e9 + 7;
template <typename T>
inline void print(T x) {
  cout << x << "\n";
}
template <typename T>
inline void printvec(T x) {
  for (auto a : x) cout << a << ' ';
  cout << '\n';
}
struct custom {
  bool operator()(const pair<pair<long long int, long long int>,
                             pair<long long int, long long int> > &p1,
                  const pair<pair<long long int, long long int>,
                             pair<long long int, long long int> > &p2) const {
    pair<long long int, long long int> p = p1.first, q = p2.first;
    return p.first * q.second > p.second * q.first;
  }
};
long long int get_pow(long long int a, long long int b, long long int M = MOD) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % M;
    a = (a * a) % M;
    b >>= 1;
  }
  return res;
}
const long long int N = 2e5 + 5, inf = 2e18;
long long int tree[8 * N];
long long int siz;
vector<long long> v;
void init(int n) {
  siz = n;
  v.resize(n);
}
inline long long int _merge(long long int a, long long int b) {
  return max(a, b);
}
void _build(int node, int lx, int rx) {
  if (rx == lx) {
    tree[node] = v[lx];
    return;
  }
  int mid = (lx + rx) / 2;
  _build(2 * node + 1, lx, mid);
  _build(2 * node + 2, mid + 1, rx);
  tree[node] = _merge(tree[2 * node + 1], tree[2 * node + 2]);
}
void build() { _build(0, 0, siz - 1); }
int ans;
void query(int node, int lx, int rx, int req_l, int req_r, int w) {
  if (req_r < lx || rx < req_l || ans != -1) {
    return;
  }
  int mid = (lx + rx) / 2;
  if (req_l <= lx && rx <= req_r) {
    if (tree[node] < w) return;
    if (lx == rx) {
      ans = lx;
      return;
    }
    if (tree[2 * node + 2] >= w) {
      query(2 * node + 2, mid + 1, rx, req_l, req_r, w);
    } else {
      query(2 * node + 1, lx, mid, req_l, req_r, w);
    }
    return;
  }
  query(2 * node + 2, mid + 1, rx, req_l, req_r, w);
  if (ans == -1) query(2 * node + 1, lx, mid, req_l, req_r, w);
}
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  vector<long long> pref(n);
  init(n);
  set<char> t = {'a', 'e', 'i', 'o', 'u'};
  for (long long int i = (long long int)0; i < (long long int)(n); i++) {
    if (t.count(s[i]))
      pref[i] = -1;
    else
      pref[i] = 2;
    if (i) pref[i] += pref[i - 1];
    v[i] = pref[i];
  }
  build();
  long long int max_ans = 0;
  for (long long int i = (long long int)0; i < (long long int)(n); i++) {
    long long int to_minus = 0;
    if (i) to_minus = pref[i - 1];
    ans = -1;
    query(0, 0, siz - 1, i, n - 1, to_minus);
    if (ans != -1) {
      max_ans = max(max_ans, ans - i + 1);
    }
  }
  if (!t.count(s[n - 1])) max_ans = max(max_ans, 1ll);
  long long int cnt = 0;
  for (long long int i = (long long int)0; i < (long long int)(n); i++) {
    long long int x = max_ans + i - 1, to_minus = 0;
    if (i) to_minus = pref[i - 1];
    if (x < n && pref[x] - to_minus >= 0) cnt++;
  }
  if (max_ans) {
    cout << max_ans << ' ' << cnt << '\n';
  } else {
    cout << "No solution\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  clock_t z = clock();
  for (long long int tes = (long long int)0; tes < (long long int)(test);
       tes++) {
    solve();
  }
  fprintf(stderr, "Total Time:%.4f\n", (double)(clock() - z) / CLOCKS_PER_SEC),
      fflush(stderr);
  return 0;
}
