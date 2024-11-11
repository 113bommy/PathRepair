#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int MOD = 1e9 + 7;
long long cnp[N][N];
void init() {
  for (int i = 0; i < N; ++i) {
    cnp[i][0] = cnp[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      cnp[i][j] = cnp[i - 1][j - 1] + cnp[i - 1][j];
      cnp[i][j] %= MOD;
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  init();
  int k;
  cin >> k;
  long long res = 1;
  int cur = 0;
  for (int i = 0; i < k; ++i) {
    int c;
    cin >> c;
    res *= cnp[cur + c - 1][c - 1];
    res %= MOD;
    cur += c;
  }
  cout << res << endl;
  return 0;
}
