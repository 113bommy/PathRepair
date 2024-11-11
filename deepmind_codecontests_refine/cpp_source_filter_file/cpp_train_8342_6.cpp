#include <bits/stdc++.h>
using namespace std;
const long long N = 1555, OO = 1110111110111, mod = 1000000007;
int n, x, sol, acc, t;
int dp[N], it[N], a[N];
int solve(int i) {
  if (i == n) return 0;
  if (it[i] == t) return dp[i];
  it[i] = t;
  int ret = 0, aux = 0;
  ret = max(ret, solve(i + 1));
  for (int j = i; j < n; j++) {
    aux += a[j];
    if (aux == acc) {
      ret = max(ret, 1 + solve(j + 1));
      break;
    }
  }
  return dp[i] = ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    acc = 0;
    for (int j = i; j < n; j++) {
      acc += a[j];
      ++t;
      if (solve(j + 1) > sol) {
        sol = dp[j + 1];
        x = acc;
      }
    }
  }
  cout << sol + 1 << "\n";
  acc = x;
  solve(0);
  for (int i = 0; i < n; i++) {
    acc = 0;
    for (int j = i; j < n; j++) {
      acc += a[j];
      if (acc == x && dp[j + 1] == sol) {
        cout << i + 1 << " " << j + 1 << "\n";
        sol--;
        i = j;
        j = n;
      }
    }
  }
  return 0;
}
