#include <bits/stdc++.h>
using namespace std;
int n;
int p[100005], sz[100005];
inline int parent(const int i) {
  return (i == p[i]) ? i : (p[i] = parent(p[i]));
}
inline void unite(const int i, const int j) {
  const int I = parent(i), J = parent(J);
  p[J] = I;
  sz[I] += sz[J];
}
inline bool is_lucky(int w) {
  for (int x; w; w /= 10) {
    x = w % 10;
    if (x != 4 && x != 7) return false;
  }
  return true;
}
inline void init() {
  for (int i = 0; i < 100005; ++i) p[i] = i, sz[i] = 1;
}
inline void read() {
  cin >> n;
  for (int i = 0, u, v, w; i < n - 1; ++i) {
    cin >> u >> v >> w;
    if (!is_lucky(w)) unite(u, v);
  }
}
inline long long solve() {
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == p[i]) {
      const long long s = sz[i];
      ans += s * (n - s) * (n - s - 1LL);
    }
  }
  return ans;
}
int main() {
  init();
  read();
  cout << solve();
  return 0;
}
