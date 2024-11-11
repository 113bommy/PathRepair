#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first - a.second) > (b.first - b.second);
}
const int mod = 1e9 + 7;
int par[100005];
int sz[100005];
long long int find(long long int a) {
  while (par[a] != a) a = par[a];
  return a;
}
long long int un(long long int a, long long int b) {
  long long int p1 = find(a);
  long long int p2 = find(b);
  if (p1 == p2) return 1;
  if (sz[p1] > sz[p2])
    par[p2] = p1, sz[p1] += sz[p2];
  else
    par[p1] = p2, sz[p2] += sz[p1];
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
  long long int ans = 0;
  for (int i = 0; i < m; ++i) {
    long long int a, b;
    cin >> a >> b;
    if (un(a, b)) {
      ans = (2 * ans + 1) % mod;
    }
    cout << ans << endl;
  }
  return 0;
}
