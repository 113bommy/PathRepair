#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool checkMax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T, typename... Args>
inline void checkMax(T &a, const Args... arg) {
  checkMax(a, max(arg...));
}
template <class T>
inline bool checkMin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename... Args>
inline void checkMin(T &a, const Args... arg) {
  checkMin(a, min(arg...));
}
const int INF = 0x3f3f3f3f;
const long long llINF = 1e18;
const int MAXN = 1e3 + 5;
const int MAXK = 10;
int n, K, ans;
int p[MAXN], vis[MAXN];
pair<int, int> a[MAXN], b[MAXN];
vector<int> vec[MAXK][MAXN], tmp;
pair<int, int> operator-(const pair<int, int> &x, const pair<int, int> &y) {
  return make_pair(x.first - y.first, x.second - y.second);
}
long long operator^(const pair<int, int> &x, const pair<int, int> &y) {
  return 1ll * x.first * y.second - 1ll * x.second * y.first;
}
bool Check(int &dep, int u) {
  if (dep > K) return false;
  for (int v : vec[p[dep]][u]) {
    if (vis[v]) continue;
    dep += 1;
    if (!Check(dep, v)) return false;
  }
  tmp.push_back(u);
  vis[u] = 1;
  return true;
}
int main() {
  scanf("%d%d", &K, &n);
  for (int i = 1; i <= K; i++) scanf("%d%d", &a[i].first, &a[i].second);
  for (int i = 1; i <= n; i++) scanf("%d%d", &b[i].first, &b[i].second);
  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (j == k) continue;
        if (b[k].first >= min(a[i].first, b[j].first) &&
            b[k].first <= max(a[i].first, b[j].first) &&
            b[k].second >= min(a[i].second, b[j].second) &&
            b[k].second <= max(a[i].second, b[j].second) &&
            ((a[i] - b[j]) ^ (a[i] - b[k])) == 0)
          vec[i][j].push_back(k);
        if ((int)vec[i][j].size() == K) break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= K; j++) p[i] = i;
    do {
      for (int v : tmp) vis[v] = 0;
      tmp.clear();
      int d = 1;
      if (Check(d, i)) {
        ans += 1;
        break;
      }
    } while (next_permutation(a + 1, a + 1 + n));
  }
  printf("%d\n", ans);
  return 0;
}
