#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
bool vis[N];
vector<long long> v[N];
long long c0, c1;
int type[N];
void dfs(int x, int t) {
  if (t)
    c1++;
  else
    c0++;
  vis[x] = 1;
  type[x] = t;
  for (int y : v[x]) {
    if (!vis[y])
      dfs(y, !t);
    else if (type[y] == t) {
      cout << "0 1";
      exit(0);
    }
  }
}
int main() {
  long long n, m, mm, x, y, res = 0;
  cin >> n >> m;
  mm = m;
  if (!m) return !printf("3 %lld\n", n * (n - 1) * (n - 2) / 6);
  while (m--) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; !res && i <= n; i++) {
    if (v[x].size() > 1) res = 1;
  }
  if (!res) return !printf("2 %lld\n", mm * (n - 2));
  res = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    c0 = c1 = 0;
    dfs(1, 0);
    res += c0 * (c0 - 1) / 2 + c1 * (c1 - 1) / 2;
  }
  cout << 1 << " " << res;
  return 0;
}
