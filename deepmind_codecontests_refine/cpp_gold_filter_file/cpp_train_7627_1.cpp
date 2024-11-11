#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int powm(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * 1LL * a) % mod;
    b >>= 1LL;
    a = (a * 1LL * a) % mod;
  }
  return res;
}
const int N = 2e5 + 5;
const int M = 3005;
int n, m;
vector<pair<pair<int, int>, int>> edges;
bool check(int mid) {
  set<int> factory, airport;
  for (auto [p, day] : edges) {
    if (day > mid) continue;
    auto [u, v] = p;
    airport.insert(u);
    factory.insert(v);
  }
  return (airport.size() == n && factory.size() == n);
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    edges.push_back({{a, b}, d});
  }
  int low = 1, high = 1e9 + 1;
  while (low < high) {
    int mid = (low + high) / 2;
    if (check(mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  if (low > 1e9) {
    cout << -1 << '\n';
  } else
    cout << low << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  int _ = 0;
  while (_++ < tc) {
    solve();
  }
  return 0;
}
