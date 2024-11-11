#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
int pct(int x) { return __builtin_popcount(x); }
int bits(int x) { return 31 - __builtin_clz(x); }
int cdiv(int a, int b) { return a / b + !(a < 0 || a % b == 0); }
int fstTrue(function<bool(int)> first, int lo, int hi) {
  hi++;
  assert(lo <= hi);
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    first(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const long long INFLL = 0x3f3f3f3f3f3f3f3f;
const long long NINFLL = 0xc0c0c0c0c0c0c0c0;
const long long MOD = 1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
long long modInv(long long a) { return binpow(a, MOD - 2); }
bool sortcol(const vector<long long>& v1, const vector<long long>& v2) {
  return v1[1] < v2[1];
}
bool sortpair(const pair<int, int>& p1, const pair<int, int>& p2) {
  return p1.first < p2.first;
}
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long unsigned> distribution(0, 10);
const int mxN = 2e5;
int q = 1, n, arr[mxN], idx[mxN], st[4 * mxN], ans;
vector<vector<int> > fin;
void update(int i, int x, int lo = 0, int hi = -1, int node = 0) {
  if (hi == -1) hi = n - 1;
  if (hi < i || lo > i) return;
  if (lo == hi) {
    st[node] += x;
    return;
  }
  int mid = (lo + hi) / 2;
  update(i, x, lo, mid, 2 * node + 1);
  update(i, x, mid + 1, hi, 2 * node + 2);
  st[node] = max(st[2 * node + 1], st[2 * node + 2]);
}
int query(int s, int e, int lo = 0, int hi = -1, int node = 0) {
  if (hi == -1) hi = n - 1;
  if (hi < s || lo > e) return 0;
  if (lo >= s && hi <= e) return st[node];
  int mid = (lo + hi) / 2;
  return max(query(s, e, lo, mid, 2 * node + 1),
             query(s, e, mid + 1, hi, 2 * node + 2));
}
vector<int> LIS() {
  int dp[n + 1], val[n + 1], prev[n + 1];
  int lis = 0, end = 0;
  for (int i = (0); i < (n); i++) {
    if (!arr[i]) continue;
    int pos = lower_bound(dp, dp + lis, arr[i]) - dp;
    dp[pos] = arr[i];
    val[pos] = i;
    prev[i] = pos ? val[pos - 1] : -1;
    if (pos + 1 > lis) {
      lis = pos + 1;
      end = i;
    }
  }
  stack<int> s;
  vector<int> v;
  while (prev[end] >= 0) {
    s.push(arr[end]);
    end = prev[end];
  }
  v.push_back(arr[end]);
  while (!s.empty()) {
    v.push_back(s.top());
    s.pop();
  }
  return v;
}
void solve() {
  cin >> n;
  for (int i = (0); i < (n); i++) cin >> arr[i];
  for (int i = (0); i < (n); i++) idx[arr[i]] = i;
  int rem = n;
  while (rem) {
    int k = 0;
    while ((k + 1) * (k + 2) / 2 <= rem) k++;
    vector<int> v = LIS();
    if (v.size() > k) {
      vector<int> t;
      for (auto& i : v) {
        t.push_back(arr[idx[i]]);
        arr[idx[i]] = 0;
      }
      fin.push_back(t);
      rem -= v.size();
      ans++;
    } else {
      set<int> s;
      int par[n];
      fill(par, par + n, 0);
      for (int i = (0); i < (n); i++) {
        if (!arr[i]) continue;
        if (s.lower_bound(arr[i] + 1) == s.end())
          par[i] = -1;
        else {
          par[i] = idx[*s.lower_bound(arr[i] + 1)];
          s.erase(*s.lower_bound(arr[i] + 1));
        }
        s.insert(arr[i]);
      }
      bool vis[n];
      fill(vis, vis + n, 0);
      for (int i = (n)-1; i >= (0); i--) {
        if (!arr[i] || vis[i]) continue;
        vector<int> t;
        int j = i;
        while (j != -1) {
          vis[j] = 1;
          t.push_back(arr[j]);
          j = par[j];
        }
        reverse(begin(t), end(t));
        fin.push_back(t);
        ans++;
      }
      rem = 0;
    }
  }
  cout << ans << "\n";
  for (auto& i : fin) {
    cout << i.size() << " ";
    for (auto& j : i) cout << j << " ";
    cout << "\n";
  }
  ans = 0;
  fin.clear();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> q;
  while (q--) {
    solve();
  }
}
