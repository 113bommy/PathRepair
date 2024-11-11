#include <bits/stdc++.h>
#pragma optimize("", off)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:36777216")
const int mod = 1000000007;
using namespace std;
template <class T>
void smin(T& a, T val) {
  if (a > val) a = val;
}
template <class T>
void smax(T& a, T val) {
  if (a < val) a = val;
}
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  bool first = true;
  os << "[";
  for (auto i : v) {
    if (!first) os << ", ";
    os << i;
    first = false;
  }
  return os << "]";
}
const int N = 4 * 1e5 + 10;
bool vis[N];
std::vector<int> v[N];
int n, m, q;
void dfs(int s) {
  vis[s] = 1;
  for (auto i : v[s]) {
    if (!vis[i]) dfs(i);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> q;
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    y += n;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int cnt = 0;
  for (int i = 0; i < n + m; ++i) {
    if (!vis[i]) {
      vis[i] = 1;
      dfs(i);
      cnt++;
    }
  }
  cout << cnt - 1;
  return 0;
}
