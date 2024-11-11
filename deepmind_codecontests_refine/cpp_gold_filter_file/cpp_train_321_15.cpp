#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007ll;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= MOD;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
template <typename t1, typename t2>
inline bool upmax(t1 &a, t2 b) {
  if (a < (t1)b) {
    a = (t1)b;
    return true;
  } else
    return false;
}
template <typename t1, typename t2>
inline bool upmin(t1 &a, t2 b) {
  if (a > (t1)b) {
    a = (t1)b;
    return true;
  } else
    return false;
}
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
inline T lcm(T a, T b) {
  return a * (b / gcd(a, b));
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int INF = 1000000404;
const long long LINF = 4000000000000000404ll;
const long double PI = acos(-1.0);
const long double EPS = 1e-9;
int SQ = 318;
int timer = 0;
const int N = 1100;
int a[N];
int b[N];
int col[N];
int col2[N];
int d[N];
void solve() {
  vector<int> g[N];
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    col[i] = 0;
    col2[i] = 0;
    d[i] = INF;
  }
  int k1, k2;
  cin >> k1;
  for (int i = 0; i < k1; i++) {
    cin >> a[i];
    col[a[i]] = 1;
  }
  cin >> k2;
  for (int i = 0; i < k2; i++) {
    cin >> b[i];
    col2[b[i]] = 1;
  }
  cout << "B " << b[0] << endl;
  int v;
  cin >> v;
  queue<int> q;
  d[v] = 0;
  q.push(v);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto y : g[x]) {
      if (d[y] > d[x] + 1) {
        d[y] = d[x] + 1;
        q.push(y);
      }
    }
  }
  int x = a[0];
  for (int i = 0; i < k1; i++) {
    if (d[a[i]] < d[x]) x = a[i];
  }
  cout << "A " << x << endl;
  int r;
  cin >> r;
  if (col2[r]) {
    cout << "C " << x << endl;
  } else {
    cout << "C " << -1 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
