#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline int len(const T &a) {
  return a.size();
}
constexpr int mxn = 3e3 + 10;
int n, p[mxn];
tuple<int, int, int> edges[mxn];
int guys[mxn], psum[mxn];
void clear() {
  for (int i = 0; i < mxn; ++i) {
    guys[i] = -1;
    psum[i] = p[i];
  }
}
int root(int v) { return guys[v] < 0 ? v : guys[v] = root(guys[v]); }
void unite(int v, int u) {
  v = root(v), u = root(u);
  if (v == u) {
    return;
  }
  if (guys[u] < guys[v]) {
    swap(u, v);
  }
  guys[v] += guys[u];
  guys[u] = v;
  psum[v] += psum[u];
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    edges[i] = {w, --v, --u};
  }
  int allp = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    allp += p[i];
  }
  auto solve = [&](int mid) {
    clear();
    for (int i = 0; i < n - 1; ++i) {
      if (get<0>(edges[i]) < mid) {
        unite(get<1>(edges[i]), get<2>(edges[i]));
      }
    }
    for (int i = 0; i < n; ++i) {
      if (guys[i] >= 0) {
        continue;
      }
      if (-guys[i] > (allp - psum[i])) {
        return false;
      }
    }
    return true;
  };
  int low = 1, high = 10000;
  while (high - low > 0) {
    int mid = (high + low + 1) >> 1;
    if (solve(mid)) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  printf("%d", low);
  return 0;
}
