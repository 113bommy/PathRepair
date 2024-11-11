#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << ":" << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << ":" << arg1 << " |";
  __f(comma + 1, args...);
}
void Ishan_Pandey() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cout << setprecision(16) << fixed;
}
const long long int N = 200010;
long long int parent[N], rank1[N];
void make_set(long long int v) {
  parent[v] = v;
  rank1[v] = 0;
}
long long int find_set(long long int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(long long int a, long long int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (rank1[a] < rank1[b]) swap(a, b);
    parent[b] = a;
    if (rank1[a] == rank1[b]) rank1[a]++;
  }
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n + 2, 0);
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long int ans = 0;
  for (long long int i = 1; i <= n; i++) a[i] = min(a[i], a[i - 1] + 1);
  for (long long int i = n; i >= 1; i--) a[i] = min(a[i], a[i + 1] + 1);
  for (long long int i = 1; i <= n; i++) ans = max(ans, a[i]);
  cout << ans;
}
int32_t main() {
  Ishan_Pandey();
  solve();
  return 0;
}
