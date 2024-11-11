#include <bits/stdc++.h>
using namespace std;
void err() { std::cerr << '\n' << "END OF DEBUG" << '\n' << '\n'; }
template <typename T, typename... Args>
void err(T a, Args... args) {
  std::cerr << a << ", ";
  err(args...);
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args) {
  for (auto x : a) {
    std::cerr << x << ", ";
  }
  err(args...);
}
const long double PI = acos(-1.0);
const long double eps = 1e-6;
const long long maxw = (long long)1e17 + (long long)10;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int maxn = 25;
struct node {
  int to;
  int w;
};
vector<node> e[maxn + maxn];
int n, k, t, cnt;
bool isv[maxn + maxn];
void dfs(int u, int sum, int lim) {
  if (u > n) {
    cnt++;
    return;
  }
  dfs(u + 1, sum, lim);
  int v, w;
  for (int i = 0; i < (int)e[u].size(); i++) {
    v = e[u][i].to;
    w = e[u][i].w;
    if (!isv[v] && w + sum <= lim && cnt < t) {
      isv[v] = true;
      dfs(u + 1, w + sum, lim);
      isv[v] = false;
    }
  }
}
void solve() {
  int l = 0, r = (int)1e5 + 10, mid;
  while (l < r) {
    mid = (l + r) >> 1;
    cnt = 0;
    dfs(1, 0, mid);
    if (cnt >= t) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", l);
}
int main(void) {
  int u, v, w;
  scanf("%d %d %d", &n, &k, &t);
  for (int i = 1; i <= k; i++) {
    scanf("%d %d %d", &u, &v, &w);
    v += n;
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }
  solve();
  return 0;
}
