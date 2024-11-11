#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000;
const int MOD = 1e9 + 7;
int memo[MAX_N][MAX_N][11][2];
int maxPref[MAX_N][MAX_N];
int n, m, k;
char strA[MAX_N + 5], strB[MAX_N + 5];
int dp(int indA, int indB, int currK, bool use) {
  if (!currK) return 0;
  if (indA >= n or indB >= m) {
    if (currK == 1 and use) return 0;
    return -40000;
  }
  int &r = memo[indA][indB][currK][use];
  if (r != -1) return r;
  if (use) {
    r = dp(indA, indB, currK - 1, false);
    if (strA[indA] == strB[indB])
      r = max(r, 1 + dp(indA + 1, indB + 1, currK, true));
    return r;
  }
  r = 0;
  r = max(r, dp(indA + 1, indB, currK, false));
  r = max(r, dp(indA, indB + 1, currK, false));
  if (strA[indA] == strB[indB])
    r = max(r, 1 + dp(indA + 1, indB + 1, currK, true));
  return r;
}
int main() {
  memset(memo, -1, sizeof memo);
  memset(maxPref, -1, sizeof maxPref);
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s", strA);
  scanf("%s", strB);
  printf("%d\n", dp(0, 0, k, false));
  return 0;
}
