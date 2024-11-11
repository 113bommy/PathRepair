#include <bits/stdc++.h>
using namespace std;
using cat = long long;
cat sz[82] = {1, 2};
pair<int, int> solve_pair(cat x, int k) {
  if (x == 0) return {0, (k + 1) / 2};
  if (x == sz[k] - 1) return {(k + 1) / 2, 0};
  if (x >= sz[k - 1]) {
    pair<int, int> prev = solve_pair(x - sz[k - 1], k - 2);
    prev.first++;
    return prev;
  }
  pair<int, int> prev = solve_pair(x, k - 1);
  return {min(prev.first, prev.second + 2),
          min(prev.first, prev.second) + (k + 1) / 2};
}
int solve(cat a, cat b, int k) {
  if (a > b) swap(a, b);
  if (a == b) return 0;
  if (k == 1) return 1;
  while (sz[k - 2] > b) k--;
  if (a == 0 && b == sz[k] - 1) return (k + 1) / 2;
  if (a >= sz[k - 1]) return solve(a - sz[k - 1], b - sz[k - 1], k - 2);
  if (b >= sz[k - 1] && a < sz[k - 1]) {
    pair<int, int> d_a = solve_pair(a, k - 1);
    pair<int, int> d_b = solve_pair(b - sz[k - 1], k - 2);
    return min(d_a.first, d_a.second) + d_b.first + 1;
  } else {
    int d0 = solve(a, b, k - 1);
    pair<int, int> d_a = solve_pair(a, k - 1);
    pair<int, int> d_b = solve_pair(b, k - 1);
    return min(d0, min(d_a.first + d_b.second, d_a.second + d_b.first) + 2);
  }
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int T, N;
  cin >> T >> N;
  N = min(N, 81);
  for (int i = 2; i <= 81; i++) sz[i] = sz[i - 1] + sz[i - 2];
  while (T--) {
    cat a, b;
    cin >> a >> b;
    cout << solve(a - 1, b - 1, N) << "\n";
  }
  return 0;
}
