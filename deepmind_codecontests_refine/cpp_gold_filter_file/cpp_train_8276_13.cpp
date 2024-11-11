#include <bits/stdc++.h>
using namespace std;
template <typename X>
inline X abs(const X& a) {
  return a < 0 ? -a : a;
}
template <typename X>
inline X sqr(const X& a) {
  return a * a;
}
const int size = 1e5 + 2;
const double eps = 0.0001;
const long double PI = 3.1415926535897932384626433832795;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;
void solution();
void include_file();
long long bin_search(long long left, long long right);
int main() {
  ios_base::sync_with_stdio(false);
  solution();
  return 0;
}
void include_file() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
vector<vector<int> > g;
int was[100];
void dfs(int v) {
  if (was[v]) return;
  was[v] = 1;
  for (int i = 0; i < g[v].size(); ++i) {
    dfs(g[v][i]);
  }
}
int bfs(int s, int toto) {
  queue<int> q;
  vector<bool> used(1001);
  vector<int> d(1001), p(1001);
  q.push(s);
  used[s] = true;
  p[s] = 1;
  d[s] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (size_t i = 0; i < g[v].size(); ++i) {
      int to = g[v][i];
      if (!used[to]) {
        used[to] = true;
        q.push(to);
        d[to] = d[v] + 1;
        p[to] = v;
      }
    }
  }
  return d[toto];
}
void yes() { cout << "YES"; }
void no() { cout << "NO"; }
namespace bits {
template <typename X>
inline X MAX(const X& a, const X& b) {
  return b & ((a - b) >> 31) | a & (~(a - b) >> 31);
}
template <typename X>
inline X MIN(const X& a, const X& b) {
  return a & ((a - b) >> 31) | b & (~(a - b) >> 31);
}
bool check2(const long long n) { return n > 0 && (n & (n - 1)); }
long long ostatok2(const long long n, const long long m) { return m & (n - 1); }
template <typename X>
void SWAP(X& a, X& b) {
  a ^= b;
  b ^= a;
  a ^= b;
}
size_t count_1_in_LL(unsigned long long n) {
  std::size_t i(0);
  for (; n; ++i) n &= n - 1;
  return i;
}
}  // namespace bits
void solution() {
  string s;
  int dm;
  cin >> s >> dm;
  int h = (s[0] - '0') * 10 + (s[1] - '0');
  int m = (s[3] - '0') * 10 + (s[4] - '0');
  m += dm;
  if (m > 60) h += m / 60, m %= 60;
  h %= 24;
  if (m == 60) m = 0, h++;
  if (h == 24) h = 0;
  if (h < 10) cout << 0;
  cout << h << ":";
  if (m < 10) cout << 0;
  cout << m;
}
