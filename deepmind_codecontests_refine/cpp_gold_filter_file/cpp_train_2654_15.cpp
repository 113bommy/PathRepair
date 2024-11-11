#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10, inf = 1e15;
vector<int> v[maxn];
int flag[maxn];
inline pair<int, int> dfs(int x, int p) {
  flag[x] = flag[p] + 1;
  pair<int, int> ret = pair<int, int>(0, 0);
  if (flag[x] % 2 == 0)
    ret.first++;
  else
    ret.second++;
  for (int i = 0; i < v[x].size(); i++)
    if (flag[v[x][i]] == 0) {
      pair<int, int> G = dfs(v[x][i], x);
      ret.first += G.first;
      ret.second += G.second;
    } else if (flag[v[x][i]] < flag[x] && v[x][i] != p) {
      if (flag[v[x][i]] % 2 == flag[x] % 2) {
        cout << "0 1";
        exit(0);
      }
    }
  return ret;
}
inline long long C(long long x) { return (x * (x - 1)) / 2; }
inline long long CC(long long x) { return (x * (x - 1) * (x - 2)) / 6; }
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    if (flag[i] == 0) {
      pair<int, int> G = dfs(i, 0);
      ans += C(G.first) + C(G.second);
    }
  if (ans == 0) {
    if (m == 0)
      cout << "3 " << CC(n);
    else
      cout << "2 " << 1LL * m * (n - 2);
  } else
    cout << "1 " << ans;
  return 0;
}
