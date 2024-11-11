#include <bits/stdc++.h>
using namespace std;
long long N, M, K, A, B, X, Y, Z, C, D, a, b, c, d, i, j, k;
long long dp[18][163][2];
void solve() {
  string S;
  cin >> S;
  N = S.length();
  long long cnt = 0;
  vector<long long> V;
  for (long long i = 0; i < N - 2; i++) {
    if (S[i] == 'o' && S[i + 1] == 'n' && S[i + 2] == 'e') {
      cnt++;
      V.push_back(i + 2);
      i += 2;
    } else if (i <= N - 5 && S[i] == 't' && S[i + 1] == 'w' &&
               S[i + 2] == 'o' && S[i + 3] == 'n' && S[i + 4] == 'e') {
      cnt++;
      V.push_back(i + 3);
      i += 4;
    } else if (S[i] == 't' && S[i + 1] == 'w' && S[i + 2] == 'o') {
      cnt++;
      V.push_back(i + 2);
      i += 2;
    }
  }
  cout << cnt << endl;
  M = V.size();
  for (long long i = 0; i < M - 1; i++) {
    cout << V[i] << " ";
  }
  if (!V.empty()) {
    cout << V[V.size() - 1];
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
