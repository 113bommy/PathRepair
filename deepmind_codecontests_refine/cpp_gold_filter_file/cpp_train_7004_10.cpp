#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
const int INF = 1e9;
const int MOD = 998244353;
long long add(long long x, long long y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}
long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) x += MOD;
  return x;
}
long long mul(long long x, long long y) {
  long long prod = x * 1ll * y;
  prod %= MOD;
  return prod;
}
long long inv(long long p, long long q) {
  long long expo = MOD - 2;
  while (expo) {
    if (expo & 1) p = mul(p, q);
    q = mul(q, q);
    expo >>= 1;
  }
  return p;
}
bool sortcol(const vector<int> &v1, const vector<int> &v2) {
  return v1[1] < v2[1];
}
vector<int> graph[N];
int a1[N], a2[N], seg[4 * N];
void solveTestCase() {
  int n, m, k, x, y, u, v;
  cin >> n >> k;
  vector<vector<int> > a(2, vector<int>(n + 2, 1));
  vector<int> b(k), pos(n + 1);
  for (int i = (int)1; i < (int)n + 1; ++i) cin >> a[0][i];
  for (int i = (int)1; i < (int)n + 1; ++i) pos[a[0][i]] = i;
  for (int i = (int)0; i < (int)k; ++i) cin >> b[i];
  for (int i = (int)0; i < (int)k; ++i) a[1][pos[b[i]]] = 0;
  a[0][0] = a[0][n + 1] = a[1][0] = a[1][n + 1] = 0;
  int ans = 1;
  for (int i = (int)0; i < (int)k; ++i) {
    ans = mul(ans, a[1][pos[b[i]] - 1] + a[1][pos[b[i]] + 1]);
    a[1][pos[b[i]]] = 1;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solveTestCase();
  return 0;
}
