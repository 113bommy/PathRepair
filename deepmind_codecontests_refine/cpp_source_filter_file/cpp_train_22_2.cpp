#include <bits/stdc++.h>
using namespace std;
const int mxN = 80;
int N, K;
tuple<int, int, int> v[mxN];
int dp[mxN][mxN], pa[mxN][mxN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> N >> K;
    for (int i = (1); i <= (N); ++i) {
      int A, B;
      cin >> A >> B;
      v[i] = {B, A, i};
    }
    sort(v + 1, v + 1 + N);
    memset(pa, -1, sizeof pa);
    for (int i = (N); i >= (1); --i) {
      auto& [B, A, id] = v[i];
      for (int x = (0); x <= (K); ++x) {
        int y = i - 1 - x;
        dp[i][x] = 0;
        if (x < K) {
          int a = dp[i + 1][x + 1] + B * x + A;
          if (a > dp[i][x]) {
            dp[i][x] = a;
            pa[i][x] = x + 1;
          }
        }
        if (y < N - K) {
          int a = dp[i + 1][x] + B * (K - 1);
          if (a > dp[i][x]) {
            dp[i][x] = a;
            pa[i][x] = x;
          }
        }
      }
    }
    vector<int> p, q;
    cout << N + (N - K) << '\n';
    for (int i = 1, x = 0; i <= N; x = pa[i++][x]) {
      auto [B, A, id] = v[i];
      if (pa[i][x] == x) {
        q.push_back(id);
      } else {
        p.push_back(id);
      }
    }
    for (int i = (0); i <= ((int)(p).size() - 2); ++i) {
      cout << p[i] << ' ';
    }
    for (int i = (0); i <= ((int)(q).size() - 1); ++i) {
      cout << q[i] << ' ' << -q[i] << ' ';
    }
    cout << p.back() << '\n';
  }
}
