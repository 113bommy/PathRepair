#include <bits/stdc++.h>
using namespace std;
string a, b;
int dp[3009][3009];
int solve(int idx1, int idx2) {
  if (idx1 >= a.length() && idx2 < b.length()) {
    return b.length() - idx2;
  }
  if (idx2 >= b.length() && idx1 < a.length()) {
    return a.length() - idx1;
  }
  if (idx1 >= a.length() && idx2 >= b.length()) return 0;
  if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
  dp[idx1][idx2] = 0;
  if (a[idx1] == b[idx2]) {
    dp[idx1][idx2] = solve(idx1 + 1, idx2 + 1);
  } else {
    dp[idx1][idx2] =
        min(min(solve(idx1 + 1, idx2) + 1, solve(idx1, idx2 + 1) + 1),
            solve(idx1 + 1, idx2 + 1) + 1);
  }
  return dp[idx1][idx2];
}
int ctr = 0;
void build(int idx1, int idx2) {
  if (idx1 >= a.length() && idx2 < b.length()) {
    for (int i = idx2; i < b.length(); i++) {
      cout << "INSERT " << 1 + idx1 + ctr << " " << b[i] << "\n";
      ctr++;
    }
    return;
  }
  if (idx2 >= b.length() && idx1 < a.length()) {
    for (int i = idx1; i < a.length(); i++) {
      cout << "DELETE " << 1 + idx1 + ctr << "\n";
    }
    return;
  }
  if (idx1 >= a.length() && idx2 >= b.length()) return;
  if (a[idx1] == b[idx2]) {
    idx1++;
    idx2++;
  } else if (dp[idx1][idx2] == solve(idx1 + 1, idx2) + 1) {
    cout << "DELETE " << idx1 + 1 + ctr-- << "\n";
    idx1++;
  } else if (dp[idx1][idx2] == solve(idx1, idx2 + 1) + 1) {
    cout << "INSERT " << idx1 + 1 + ctr++ << " " << b[idx2] << "\n";
    idx2++;
  } else if (dp[idx1][idx2] == solve(idx1 + 1, idx2 + 1) + 1) {
    cout << "REPLACE " << idx1 + 1 + ctr << " " << b[idx2] << "\n";
    idx1++;
    idx2++;
  }
  build(idx1, idx2);
  return;
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> a >> b;
  cout << solve(0, 0) << "\n";
  build(0, 0);
}
