#include <bits/stdc++.h>
using namespace std;
template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <typename Args>
void kill(Args args) {
  cout << args << "\n";
  exit(0);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const double PI = acos(-1);
const long long MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const int N = 201010;
long long arr[N];
long long disfrom1[N];
long long a[N];
int in[N], out[N], rev[N], timer;
vector<long long> st[4 * N];
vector<pair<int, long long>> adj[N];
int n;
void dfs(int v, int p = -1, long long cur = 0) {
  in[v] = ++timer;
  rev[timer] = v;
  disfrom1[v] = cur;
  for (pair<int, long long> next : adj[v]) {
    int nextnode = next.first;
    long long we = next.second;
    if (nextnode != p) {
      dfs(nextnode, v, cur + we);
    }
  }
  out[v] = timer;
}
void build(int p = 1, int l = 1, int r = n) {
  if (l == r) {
    st[p].emplace_back(disfrom1[rev[l]] - a[rev[l]]);
    return;
  }
  int mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  merge((st[p << 1]).begin(), (st[p << 1]).end(), (st[p << 1 | 1]).begin(),
        (st[p << 1 | 1]).end(), back_inserter(st[p]));
}
int query(int i, int j, long long val, int p = 1, int l = 1, int r = n) {
  if (i > r || j < l) return 0;
  if (i <= l && j >= r) {
    if (st[p][0] > val) {
      return 0;
    }
    int lo = 0, hi = (int)st[p].size() - 1;
    while (lo < hi) {
      int mid = (lo + hi + 1) >> 1;
      if (st[p][mid] <= val) {
        lo = mid;
      } else
        hi = mid - 1;
    }
    return lo + 1;
  }
  int mid = (l + r) >> 1;
  return query(i, j, val, p << 1, l, mid) +
         query(i, j, val, p << 1 | 1, mid + 1, r);
}
void solve(int testnum) {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int p, w;
    cin >> p >> w;
    adj[p].push_back({i, w});
    adj[i].push_back({p, w});
  }
  dfs(1);
  build();
  for (int i = 1; i <= n; i++) {
    int ans = query(in[i], out[i], disfrom1[i]);
    cout << ans - 1 << "\n";
  }
}
void precompute() {}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(12);
  int testcase = 1;
  clock_t zzzx = clock();
  precompute();
  for (int i = 1; i <= testcase; i++) {
    solve(i);
  }
  double elapsed_time = (double)(clock() - zzzx) / CLOCKS_PER_SEC;
  cerr << "elapsed_time"
       << " = " << (elapsed_time) << "\n";
  return 0;
}
