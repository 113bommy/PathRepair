#include <bits/stdc++.h>
using namespace std;
inline constexpr int pos(int p, int xi) {
  if (p == xi) {
    return 1;
  } else if (xi < p) {
    return xi + 1;
  } else {
    return xi;
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> X(M);
  vector<vector<int>> position_of(200005);
  for (auto m = 0; m < M; m++) {
    cin >> X[m];
    position_of[X[m]].push_back(m);
  }
  int64_t perm_sum = 0;
  for (auto i = 0; i < M - 1; i++) {
    perm_sum += abs(pos(1, X[i]) - pos(1, X[i + 1]));
  }
  cout << perm_sum << ' ';
  for (auto pi = 2; pi <= N; pi++) {
    for (auto i : position_of[pi - 1]) {
      if (i < M - 1) {
        perm_sum -= abs(pos(pi - 1, X[i]) - pos(pi - 1, X[i + 1]));
        perm_sum += abs(pos(pi, X[i]) - pos(pi, X[i + 1]));
      }
      if (i >= 1) {
        perm_sum -= abs(pos(pi - 1, X[i - 1]) - pos(pi - 1, X[i]));
        perm_sum += abs(pos(pi, X[i - 1]) - pos(pi, X[i]));
      }
    }
    for (auto i : position_of[pi]) {
      if (i < M - 1) {
        perm_sum -= abs(pos(pi - 1, X[i]) - pos(pi - 1, X[i + 1]));
        perm_sum += abs(pos(pi, X[i]) - pos(pi, X[i + 1]));
      }
      if (i >= 1) {
        perm_sum -= abs(pos(pi - 1, X[i - 1]) - pos(pi - 1, X[i]));
        perm_sum += abs(pos(pi, X[i - 1]) - pos(pi, X[i]));
      }
    }
    cout << perm_sum << ' ';
  }
  cout << endl;
  return 0;
}
