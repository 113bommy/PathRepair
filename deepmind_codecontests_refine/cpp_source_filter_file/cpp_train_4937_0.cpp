#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
const int N = 1e6 + 10;
const int M = 25;
int d1, d2, ans, d[N], up[N][M];
int lca(int first, int second) {
  if (d[first] < d[second]) {
    swap(first, second);
  }
  if (d[first] != d[second]) {
    for (int i = M - 1; i > 0; i--) {
      if (d[up[first][i]] > d[second]) {
        first = up[first][i];
      }
    }
    first = up[first][0];
  }
  if (first == second) {
    return first;
  }
  for (int i = M - 1; i >= 0; i--) {
    if (up[first][i] != up[second][i]) {
      first = up[first][i];
      second = up[second][i];
    }
  }
  return up[first][0];
}
void add(int first, int second) {
  up[second][0] = first;
  d[second] = d[first] + 1;
  for (int i = 1; i < M; i++) {
    up[second][i] = up[up[second][i - 1]][i - 1];
  }
  int c1 = lca(d1, second);
  int c2 = lca(d2, second);
  int cur1 = d[d1] + d[second] - 2 * d[c1];
  int cur2 = d[d2] + d[second] - 2 * d[c2];
  if (max(cur1, cur2) > ans) {
    if (cur1 > cur2) {
      ans = cur1;
      d2 = second;
    } else {
      ans = cur2;
      d1 = second;
    }
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  ans = 0;
  d[1] = 1;
  d1 = d2 = 1;
  add(1, 2);
  add(1, 3);
  add(1, 4);
  int cur = 4;
  for (int i = 1; i <= n; i++) {
    int first;
    cin >> first;
    add(first, ++cur);
    add(first, ++cur);
    cout << ans << "\n";
  }
}
