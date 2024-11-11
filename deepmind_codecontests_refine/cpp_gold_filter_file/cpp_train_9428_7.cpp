#include <bits/stdc++.h>
using namespace std;
const long long N = (long long)(5e5) + 322;
const long long INF = (long long)(1e9);
const long long mod = (long long)(1e9) + 7;
const double eps = 1e-9;
int n, a[N], b[N], col[N];
vector<int> v[N];
void dfs(int x, int cl = 1) {
  col[x] = cl;
  for (auto it : v[x]) {
    if (col[it] == -1) {
      dfs(it, cl ^ 1);
    }
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    v[a[i]].push_back(b[i]);
    v[b[i]].push_back(a[i]);
  }
  for (int i = 2; i <= n + n; i += 2) {
    v[i].push_back(i + 1);
    v[i + 1].push_back(i);
  }
  v[1].push_back(n + n);
  v[n + n].push_back(1);
  memset(col, -1, sizeof col);
  for (long long i = 1; i <= n + n; ++i)
    if (col[i] == -1) dfs(i);
  for (long long i = 1; i <= n; ++i)
    cout << col[a[i]] + 1 << ' ' << col[b[i]] + 1 << "\n";
  return 0;
}
