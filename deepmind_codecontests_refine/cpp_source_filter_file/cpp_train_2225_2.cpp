#include <bits/stdc++.h>
using namespace std;
const int M = (int)1e5;
int A[M + 5], seq[M + 5];
set<int> path[M + 5];
signed main() {
  if (!false) {
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
  int N;
  scanf("%d", &N);
  for (int _i = (N), i = (0); i < _i; i++) scanf("%d", &A[i]);
  for (int _i = (M / 2), i = (2); i <= _i; i++) {
    int x = 0;
    for (int _j = (M / i), j = (1); j <= _j; j++) {
      if (binary_search(A, A + N, i * j)) {
        if (x) path[x].insert(i * j);
        x = i * j;
      }
    }
  }
  if (false)
    for (int _i = (M), i = (0); i < _i; i++)
      if (!path[i].empty()) {
        cout << i << ": ";
        for (int j : path[i]) cout << j << ' ';
        cout << '\n';
      }
  for (int _i = (N), i = (0); i < _i; i++) seq[A[i]] = 1;
  int ans = 0;
  for (int _i = (0), i = ((N)-1); i >= _i; i--) {
    for (int j : path[A[i]]) {
      ans = max(ans, seq[A[i]] = max(seq[A[i]], seq[j] + 1));
      if (false) cout << "[" << A[i] << ' ' << j << "] " << ans << '\n';
    }
  }
  printf("%d\n", ans);
  return 0;
}
