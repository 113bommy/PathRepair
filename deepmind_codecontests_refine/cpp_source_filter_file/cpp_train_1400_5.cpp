#include <bits/stdc++.h>
using namespace std;
const int MAXN = 210, MOD = 1e9 + 7;
struct Pt {
  long long x, y;
  Pt() {}
  Pt(long long _x, long long _y) : x(_x), y(_y) {}
  friend Pt operator-(const Pt a, const Pt b) {
    return Pt(a.x - b.x, a.y - b.y);
  }
  friend long long operator*(const Pt a, const Pt b) {
    return a.x * b.y - a.y * b.x;
  }
} pts[MAXN];
int n;
long long f[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dfs(int l, int r) {
  if (vis[l][r]) return f[l][r];
  vis[l][r] = true;
  long long& res = f[l][r];
  if (l == r - 1) return res = 1;
  for (int k = l + 1; k < r; ++k) {
    if ((pts[r] - pts[l]) * (pts[r] - pts[k]) > 0) {
      res += dfs(l, k) * dfs(k, r);
      res %= MOD;
    }
  }
  return res;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> pts[i].x >> pts[i].y;
  pts[n] = pts[0];
  long long area = 0;
  for (int i = 0; i < n; ++i) area += pts[i] * pts[i + 1];
  if (area < 0) reverse(pts, pts + n), pts[n] = pts[0];
  cout << dfs(0, n - 1) << endl;
  return 0;
}
