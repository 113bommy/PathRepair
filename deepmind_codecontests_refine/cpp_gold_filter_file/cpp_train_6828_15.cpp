#include <bits/stdc++.h>
using namespace std;
int N, Q;
int A[101010];
int P[101010], K[101010];
vector<int> E[500];
const int DI = 400;
int ret[101010];
int dp[101010];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N;
  for (i = 1; i <= N; i++) cin >> A[i];
  cin >> Q;
  for (i = 0; i < (Q); i++) {
    cin >> P[i] >> K[i];
    if (K[i] <= DI)
      E[K[i]].push_back(i);
    else {
      while (P[i] <= N) {
        ret[i]++;
        P[i] = P[i] + A[P[i]] + K[i];
      }
    }
  }
  for (i = 1; i <= DI; i++) {
    for (j = N; j >= 1; j--) {
      if (j + A[j] + i > N)
        dp[j] = 1;
      else
        dp[j] = 1 + dp[j + A[j] + i];
    }
    for (auto& e : E[i]) ret[e] = dp[P[e]];
  }
  for (i = 0; i < (Q); i++) cout << ret[i] << endl;
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  solve();
  return 0;
}
