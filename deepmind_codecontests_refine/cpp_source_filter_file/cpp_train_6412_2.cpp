#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
int N, K;
int a[500009], b[500009];
double sol;
priority_queue<pair<double, int> > pqp;
int solve(double mid) {
  int cnt = 0;
  sol = 0;
  for (int i = 0; i < N; ++i) {
    pqp.push({-a[i], 0});
    double u = b[i] - mid, v = pqp.top().first;
    if (u < v) {
      sol += u - v;
      pqp.pop();
      pqp.push({u, 1});
    }
  }
  while (!pqp.empty()) {
    cnt += pqp.top().second;
    pqp.pop();
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K;
  for (int i = 0; i < N; ++i) cin >> a[i];
  for (int i = 0; i < N; ++i) cin >> b[i];
  double l = 0, r = 2000000000LL;
  for (int i = 0; i < 50; ++i) {
    double mid = (l + r) / 2;
    if (solve(mid) < K)
      l = mid;
    else
      r = mid;
  }
  printf("%lld\n", (long long int)round(sol + l * K));
}
