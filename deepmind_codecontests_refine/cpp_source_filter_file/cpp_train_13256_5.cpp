#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MOD = INF + 7;
int memo[3000 + 1][100 + 1][100];
int N;
vector<int> a, b;
int solve(int len, int w, int nouse) {
  if (len == 0) return 1;
  if (len < 0) return 0;
  if (memo[len][w][nouse] != -1) return memo[len][w][nouse];
  int res = 0;
  for (int i = 0; i < N; i++)
    if (i != nouse) {
      if (a[i] == w)
        res = (res + solve(len - b[i], b[i], i)) % MOD;
      else if (b[i] == w)
        res = (res + solve(len - a[i], a[i], i)) % MOD;
    }
  memo[len][w][nouse] = res;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  memset(memo, -1, sizeof(memo));
  int l;
  cin >> N >> l;
  a.resize(N);
  b.resize(N);
  for (int i = 0, _n = N; i < _n; i++) {
    cin >> a[i] >> b[i];
  }
  int res = 0;
  for (int i = 0, _n = 5; i < _n; i++) res = (res + solve(l, i + 1, -1)) % MOD;
  cout << res << endl;
}
