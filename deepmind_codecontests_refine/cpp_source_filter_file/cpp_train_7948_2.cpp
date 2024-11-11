#include <bits/stdc++.h>
using namespace std;
long long N, T, fib[103], dis[103];
pair<long long, long long> dis1[2][103];
pair<long long, long long> solve1(long long floor, long long p, long long id) {
  if (floor <= 2) return pair<long long, long long>(p != 1, p != fib[floor]);
  if (dis1[id][floor].first != -1) return dis1[id][floor];
  pair<long long, long long> all;
  if (p <= fib[floor - 1]) {
    pair<long long, long long> ans = solve1(floor - 1, p, id);
    all = pair<long long, long long>(
        min(ans.first, ans.second + 2),
        min(ans.first, ans.second) + dis[floor - 1] + 1);
  } else {
    all = solve1(floor - 2, p - fib[floor - 1], id);
    ++all.first;
  }
  return dis1[id][floor] = all;
}
long long solve(long long floor, long long p, long long q) {
  if (floor <= 2) return p != q;
  if (p > fib[floor - 1] && q > fib[floor - 1])
    return solve(floor - 2, p - fib[floor - 1], q - fib[floor - 1]);
  if (p <= fib[floor - 1] && q <= fib[floor - 1]) {
    pair<long long, long long> x = solve1(floor - 1, p, 0),
                               y = solve1(floor - 1, q, 1);
    return min(solve(floor - 1, p, q),
               min(x.first + y.second, x.second + y.first) + 2);
  }
  pair<long long, long long> P = solve1(floor - 1, p, 0),
                             Q = solve1(floor - 2, q - fib[floor - 1], 1);
  return min(P.first, P.second) + Q.first + 1;
}
signed main() {
  ios::sync_with_stdio(0);
  cin >> T >> N;
  fib[1] = 2;
  fib[2] = 3;
  for (long long i = 3; fib[i - 1] <= 1e16 && i <= N; ++i)
    fib[i] = fib[i - 1] + fib[i - 2];
  while (N > 100 || !fib[N]) --N;
  dis[1] = dis[2] = 1;
  for (long long i = 1; i <= N; ++i) dis[i] = dis[i - 2] + 1;
  for (long long i = 1; i <= T; ++i) {
    for (long long j = 1; j <= N; ++j)
      dis1[0][j] = dis1[1][j] = pair<long long, long long>(-1, -1);
    long long p, q;
    cin >> p >> q;
    cout << solve(N, min(p, q), max(p, q)) << endl;
  }
  return 0;
}
