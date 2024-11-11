#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000 + 7;
const double esp = 1e-13;
struct node {
  int x, y;
  bool operator<(const node &op) const {
    return op.x > x || (op.x == x && op.y > y);
  }
} a[2000 + 10];
int h, w, n;
long long res[2000 + 10], gt[200000 + 10], rev[200000 + 10];
long long power(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n % 2) ans = ans * a % INF;
    a = a * a % INF;
    n /= 2;
  }
  return ans;
}
long long C(int n, int k) { return gt[n] * rev[k] % INF * rev[n - k] % INF; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cin >> h >> w >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
  a[++n] = {h, w};
  sort(a + 1, a + n + 1);
  gt[0] = 1;
  rev[0] = power(1, INF - 2);
  for (long long i = 1; i <= 100000; i++) {
    gt[i] = gt[i - 1] * i % INF;
    rev[i] = power(gt[i], INF - 2);
  }
  for (long long i = 1; i <= n; i++) {
    res[i] = C(a[i].x + a[i].y - 2, a[i].x - 1);
    for (long long j = 1; j <= i - 1; j++)
      if (a[i].x >= a[j].x && a[i].y >= a[j].y) {
        res[i] -= res[j] *
                  C(a[i].x - a[j].x + a[i].y - a[j].y, a[i].x - a[j].x) % INF;
        if (res[i] < 0) res[i] += INF;
      }
  }
  cout << res[n];
}
