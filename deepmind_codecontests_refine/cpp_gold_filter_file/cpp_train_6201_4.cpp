#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 1e9 + 7;
const long double EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N = 1e5 + 1;
int x[N], y[N];
long long ans[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  memset(ans, -1, sizeof ans);
  int n, m, k;
  cin >> n >> m >> k;
  unordered_map<int, set<int>> plus, minus;
  for (int i = 0; i < k; i++) {
    cin >> x[i] >> y[i];
    plus[x[i] + y[i]].insert(i);
    minus[x[i] - y[i]].insert(i);
  }
  int cx = 0;
  int cy = 0;
  int dx = 1;
  int dy = 1;
  long long cur = 0;
  for (;;) {
    int tx = (dx == 1 ? n - cx : cx);
    int ty = (dy == 1 ? m - cy : cy);
    if (dx == dy) {
      for (int i : minus[cx - cy]) {
        ans[i] = cur + abs(x[i] - cx);
        plus[x[i] + y[i]].erase(i);
      }
      minus[cx - cy].clear();
    } else {
      for (int i : plus[cx + cy]) {
        ans[i] = cur + abs(x[i] - cx);
        minus[x[i] - y[i]].erase(i);
      }
      plus[cx + cy].clear();
    }
    if (tx < ty) {
      cur += tx;
      cx += dx * tx;
      cy += dy * tx;
      dx = -dx;
    } else {
      cur += ty;
      cx += dx * ty;
      cy += dy * ty;
      dy = -dy;
    }
    if (tx == ty) {
      break;
    }
  }
  for (int i = 0; i < k; i++) {
    cout << ans[i] << nl;
  }
  return 0;
}
