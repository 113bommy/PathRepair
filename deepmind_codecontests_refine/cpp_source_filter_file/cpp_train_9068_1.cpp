#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n;
long long f[N];
long long q[N], head = 1, tail = 0;
struct node {
  long long x, y, A;
} P[N];
double T(long long j1, long long j2) {
  return 1.0 * (f[j1] - f[j2]) / (P[j1].x - P[j2].x);
}
bool cmp(node a, node b) { return a.x < b.x; }
int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld%lld%lld", &P[i].x, &P[i].y, &P[i].A);
  }
  long long ans = -1e18;
  sort(P + 1, P + 1 + n, cmp);
  for (long long i = 1; i <= n; i++) {
    while (tail > head && T(q[head], q[head + 1]) > 1.0 * P[i].y) head++;
    f[i] = P[i].x * P[i].y - P[i].A;
    if (head <= tail)
      f[i] = max(f[i], f[q[head]] - P[i].A + P[i].y * (P[i].x - P[q[head]].x));
    ans = max(ans, f[i]);
    while (tail > head && T(q[tail], i) < T(q[tail - 1], q[tail])) tail--;
    q[++tail] = i;
  }
  cout << ans;
}
