#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<vector<pair<int, int>>> V(N);
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    while (A--) {
      int x, y;
      cin >> x >> y;
      V.at(i).push_back({--x, y});
    }
  }
  int ans = 0;
  for (int bit = 0; bit < 1 << N; bit++) {
    vector<int> tmp(N, -1);
    for (int i = 0; i < N; i++) {
      if (bit >> i & 1) {
        for (auto [x, y] : V.at(i)) {
          if ((bit >> x & i) ^ y) goto NG;
        }
      }
    }
    ans = max(ans, __builtin_popcount(bit));
  NG:;
  }
  cout << ans << "\n";
}
