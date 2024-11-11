#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000;
const int MOD = 1e9 + 7;
int memo[MAX_N][MAX_N][11];
int maxPref[MAX_N][MAX_N];
int n, m, k;
char strA[MAX_N], strB[MAX_N];
int dp(int indA, int indB, int currK);
int calc(int indA, int indB) {
  if (indA >= n or indB >= m) return 0;
  int &r = maxPref[indA][indB];
  if (r != -1) return r;
  if (strA[indA] != strB[indB]) return r = 0;
  return r = 1 + calc(indA + 1, indB + 1);
}
int dp(int indA, int indB, int currK) {
  if (!currK) return 0;
  if (indA >= n or indB >= m) return -40000;
  int &r = memo[indA][indB][currK];
  if (r != -1) return r;
  r = 0;
  r = max(r, dp(indA + 1, indB, currK));
  r = max(r, dp(indA, indB + 1, currK));
  int cMPref = maxPref[indA][indB];
  if (cMPref > 0) {
    for (int i = 1; i <= min(currK, cMPref); ++i)
      r = max(r, cMPref + dp(indA + cMPref, indB + cMPref, currK - i));
  }
  return r;
}
int main() {
  memset(memo, -1, sizeof memo);
  memset(maxPref, -1, sizeof maxPref);
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s", strA);
  scanf("%s", strB);
  for (int i = 0; i < n; ++i)
    for (int h = 0; h < m; ++h) calc(i, h);
  printf("%d\n", dp(0, 0, k));
  return 0;
}
