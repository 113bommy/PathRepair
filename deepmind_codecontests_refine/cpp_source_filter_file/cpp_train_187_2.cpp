#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> F(N);
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < 10; ++j) {
      int f;
      cin >> f;
      F[i] |= (f << j);
    }
  vector<vector<int>> P(N, vector<int>(11));
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < 11; ++j) cin >> P[i][j];
  int ans = -1 << 29;
  for (int i = 1; i < (1 << 10); ++i) {
    int t = 0;
    for (int j = 0; j < N; ++j) t += P[j][__builtin_popcount(F[j] & i)];
    ans = max(ans, t);
  }
  cout << ans << endl;
  return 0;
}
