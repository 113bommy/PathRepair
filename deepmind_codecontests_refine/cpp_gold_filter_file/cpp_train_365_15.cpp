#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const int INF = (int)1E9;
const long long INF64 = (long long)1E18;
const long double EPS = 1E-8;
const long double PI = 3.1415926535897932384626433832795;
struct point {
  long long x, y;
  int idx;
  bool operator<(const point &a) const { return idx < a.idx; }
};
int sign(long long x) {
  if (x > 0) return +1;
  if (x < 0) return -1;
  return 0;
}
long long up(long long a, long long b) {
  if (sign(a) * sign(b) < 0) return 0;
  if (sign(a) < 0) a *= -1;
  if (sign(b) < 0) b *= -1;
  long long ans = a / b;
  if (a % b != 0) ans++;
  return ans;
}
long long down(long long a, long long b) {
  if (sign(a) * sign(b) < 0) return -1;
  if (sign(a) < 0) a *= -1;
  if (sign(b) < 0) b *= -1;
  long long ans = a / b;
  return ans;
}
int n;
point a[10010];
void solve(int v, int u, long long &l, long long &r) {
  long long A = a[u].y - a[v].y;
  long long B = a[v].x - a[u].x;
  long long C = -(a[v].x * A + a[v].y * B);
  if (A == 0) {
    l = 0;
    r = INF;
    if (sign(B) != sign(a[0].y - a[u].y)) r = -INF;
    return;
  }
  if (A > 0) {
    l = up(-B * a[0].y - C, A);
    r = INF;
    return;
  }
  if (A < 0) {
    l = -INF;
    r = down(-B * a[0].y - C, A);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < (int)(n); i++) {
    cin >> a[i].x >> a[i].y;
    a[i].idx = i;
  }
  long long l = min(a[0].x, a[1].x), r = max(a[0].x, a[1].x);
  for (int i = 1; i < n - 1; i++) {
    int j = i + 1;
    long long lf, rg;
    solve(i, j, lf, rg);
    l = max(l, lf);
    r = min(r, rg);
  }
  cout << max(0LL, r - l + 1) << endl;
  return 0;
}
