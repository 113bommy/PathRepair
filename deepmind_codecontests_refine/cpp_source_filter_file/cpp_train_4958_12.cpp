#include <bits/stdc++.h>
using namespace std;
template <typename T1>
void dbg_pr(vector<T1> V, int add = 0, int start = -1, int end = -1) {
  cout << "{";
  if (start < 0) start = 0;
  if (end < 0) end = V.size() - 1;
  for (int i = start; i <= end; i++) {
    cout << V[i] + add << ((i == end) ? "}" : " ");
  }
}
void dbg_pr(string V) { cout << "\"" << V << "\""; }
template <typename T1>
void dbg_pr(T1 V) {
  cout << V;
}
template <typename T1, typename T2>
void dbg_pr(map<T1, T2> M) {
  cout << "{";
  for (const auto m : M) {
    dbg_pr(m.first);
    cout << ":";
    dbg_pr(m.second);
    cout << ",";
  }
  cout << "}";
}
void debug_out() { cout << "\033[0m\n"; }
template <typename T1, typename... T2>
void debug_out(T1 A, T2... B) {
  cout << " ";
  dbg_pr(A);
  debug_out(B...);
}
int test = 1;
void setupFastCin() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
template <typename T1>
T1 chmin(T1 &x, const T1 v) {
  return x = min(x, v);
}
template <typename T1>
T1 chmax(T1 &x, const T1 v) {
  return x = max(x, v);
}
template <typename T1>
void pr(vector<T1> V, int add = 0, int start = -1, int end = -1) {
  if (start < 0) start = 0;
  if (end < 0) end = V.size() - 1;
  for (int i = start; i <= end; i++) {
    cout << V[i] + add << ((i == end) ? "\n" : " ");
  }
}
template <typename T1>
T1 gcd(const T1 &a, const T1 &b) {
  if (a == 0 || b == 0) return a + b;
  return gcd(b, a % b);
}
const int MAX = 100005;
const long long MOD = 1000000007ll;
long long current_cost = 0;
int cl = 0, cr = -1;
int C[MAX];
int N[MAX];
void delt(int x) {
  C[x]--;
  current_cost -= C[x];
}
void add(int x) {
  current_cost += C[x];
  C[x]++;
}
long long cost(int l, int r) {
  while (cr < r) add(N[++cr]);
  while (cr > r) delt(N[cr--]);
  while (cl < l) {
    delt(N[cl++]);
  }
  while (cl > l) add(N[--cl]);
  return current_cost;
}
int n, g;
void compute(vector<long long> &dp, const int &l, const int &r,
             const vector<long long> &dp_p, const int &op_l, const int &op_r) {
  if (r < l) return;
  int m = (l + r) / 2;
  int opt = op_l;
  dp[m] = LLONG_MAX;
  for (int i = op_l; i <= min(op_r, m); ++i) {
    int dp_c = (i == 0 ? 0 : dp_p[i - 1]) + cost(i, m);
    if (dp[m] > dp_c) {
      dp[m] = dp_c;
      opt = i;
    }
  }
  compute(dp, l, m - 1, dp_p, op_l, opt);
  compute(dp, m + 1, r, dp_p, opt, op_r);
}
void solve() {
  cin >> n >> g;
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }
  1337;
  vector<long long> dp(n), dp_p(n, (long long)n * n);
  for (int i = 0; i < g; i++) {
    compute(dp, 0, n - 1, dp_p, 0, n - 1);
    swap(dp, dp_p);
    1337;
  }
  {
    cout << dp_p[n - 1] << "\n";
    return;
  };
}
int main() {
  setupFastCin();
  int t = 1;
  while (t--) solve();
  return 0;
}
