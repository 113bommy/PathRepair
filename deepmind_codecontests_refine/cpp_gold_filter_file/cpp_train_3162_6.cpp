#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
static void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static void amax(T &x, U y) {
  if (x < y) x = y;
}
bool a[200], b[200];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int r = 0, s = 0;
  for (int i = 0, u, v, w; i < n; i++) {
    cin >> u >> v >> w;
    if (a[v] || b[u]) {
      r += w;
      a[u] = b[v] = 1;
    } else {
      a[v] = b[u] = 1;
    }
    s += w;
  }
  cout << min(r, s - r);
  return 0;
}
