#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long dx[] = {1, -1, 0, 0};
long long dy[] = {0, 0, 1, -1};
vector<long long> parent(100001), sz(100001);
long long modexp(long long x, long long n, long long M) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return modexp((x * x) % M, n / 2, M);
  else
    return (x * modexp((x * x) % M, (n - 1) / 2, M)) % M;
}
void make_set(long long s) {
  parent[s] = s;
  sz[s] = 1;
}
long long find_parent(long long p) {
  if (p == parent[p]) return p;
  return parent[p] = find_parent(parent[p]);
}
void union_set(long long a, long long b) {
  a = find_parent(a);
  b = find_parent(b);
  if (a != b) {
    if (a < b) swap(a, b);
    parent[b] = parent[a];
    sz[a] += sz[b];
  }
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<long long> peak(n);
  set<long long> st;
  for (long long i = 1; i < n - 1; i++) {
    if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
      peak[i] = 1;
      st.insert(i);
    }
  }
  for (long long i = 1; i < n; i++) peak[i] += peak[i - 1];
  long long ans = 0, l = 0, j = 0;
  for (long long i = k - 1; i < n; i++) {
    long long x = peak[i] - peak[j];
    if (st.count(i)) x--;
    if (st.count(j)) x--;
    if (ans < x) ans = x, l = j + 1;
    j++;
  }
  cout << ans + 1 << " " << l << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test;
  test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
