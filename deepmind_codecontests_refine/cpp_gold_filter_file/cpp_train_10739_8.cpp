#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int c[500];
int memo[501][501];
int solve(int l = 0, int r = n) {
  if (memo[l][r] == -1) {
    if (l == r) {
      memo[l][r] = 1;
    } else {
      int minInd = min_element(c + l, c + r) - c;
      int leftPos = 0, rightPos = 0;
      for (int i = l; i <= minInd; i++)
        leftPos = (leftPos + (long long)solve(l, i) * solve(i, minInd)) % mod;
      for (int i = minInd + 1; i <= r; i++)
        rightPos =
            (rightPos + (long long)solve(minInd + 1, i) * solve(i, r)) % mod;
      memo[l][r] = (long long)leftPos * rightPos % mod;
    }
  }
  return memo[l][r];
}
int main() {
  scanf("%d", &n);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &c[i]);
  for (int i = 0; i <= 500; i++) {
    for (int j = 0; j <= 500; j++) {
      memo[i][j] = -1;
    }
  }
  printf("%d\n", solve());
}
