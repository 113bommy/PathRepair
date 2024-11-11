#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const double pi = 3.141592653589793238;
const long long inf = 2 * (1e18);
void pv(vector<long long> v) {
  for (long long i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << endl;
}
void pa(long long a[], long long n, long long p) {
  for (long long i = p; i < n + p; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}
long long modexp(long long x, long long y) {
  long long res = 1;
  x = x % 998244353;
  while (y > 0) {
    if (y & 1LL) res = (res * x) % 998244353;
    y = y >> 1;
    x = (x * x) % 998244353;
  }
  return res;
}
long long invmod(long long a) { return modexp(a, 998244353 - 2); }
vector<long long> edge[1000005];
void ipgraph(long long n, long long m) {
  for (long long i = 1; i <= n; i += 1) edge[i].clear();
  if (m == 0) return;
  for (long long i = 1; i <= m; i += 1) {
    long long a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
}
void solve() {
  long long n;
  cin >> n;
  long long prev = inf;
  long long ans[n + 1], in[2 * n + 1];
  map<long long, long long> m;
  std::vector<long long> v;
  set<long long> s;
  long long flag = 0;
  char inc[3 * n + 1];
  for (long long i = 1; i <= 2 * n; i += 1) {
    char c;
    cin >> c;
    inc[i] = c;
    if (c == '+') {
      m[i] = 0;
      v.push_back(i);
    } else {
      long long a;
      cin >> a;
      in[i] = a;
      if (v.empty()) {
        flag = 1;
      } else {
        m[v.back()] = a;
        v.pop_back();
      }
    }
  }
  if (flag) {
    cout << "NO" << endl;
    return;
  }
  for (long long i = 1; i <= 2 * n; i += 1) {
    if (inc[i] == '+') {
      s.insert(m[i]);
    } else {
      if (in[i] != *s.begin()) {
        cout << "No" << endl;
        return;
      }
      s.erase(s.begin());
    }
  }
  cout << "YES" << endl;
  for (auto p : m) {
    cout << p.second << " ";
  }
}
int32_t main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long i = 1; i <= t; i += 1) {
    solve();
  }
}
