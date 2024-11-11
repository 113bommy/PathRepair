#include <bits/stdc++.h>
using namespace std;
void Openfile() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
}
const int maxN = 2e3 + 5;
const int maxM = 1e6 + 5;
const long long INF = 1e9 + 7;
int N, K;
string s;
long long sum[maxN];
long long dp[maxN][maxN];
void Init() {}
void Enter() {
  cin >> N >> K;
  cin >> s;
  s = '!' + s;
}
inline void add(long long &x, long long y) { x = (x + y) % INF; }
void Solve() {
  dp[0][0] = sum[0] = 1;
  for (int n = 1, _b = N; n <= _b; n++) {
    for (int k = 0, _b = K; k <= _b; k++) {
      add(dp[n][k], sum[k] * (s[n] - 'a'));
      for (int last = 0; last < n && k >= (last + 1) * (N - n + 1); ++last) {
        add(dp[n][k],
            dp[n - last - 1][k - (1 + last) * (N - n + 1)] * ('z' - s[n]));
      }
      add(sum[k], dp[n][k]);
    }
  }
}
void PrintResult() {
  long long ans = (K == 0);
  for (int n = 1, _b = N; n <= _b; n++) {
    add(ans, dp[n][K]);
  }
  cout << ans << '\n';
}
int main() {
  Openfile();
  Init();
  Enter();
  Solve();
  PrintResult();
  return 0;
}
