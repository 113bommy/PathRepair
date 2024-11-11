#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, k, w, fl, fr;
long long dp[22][100005], fuck;
int A[100005], freq[100005];
int tl, tr, bestpos;
long long tmp, add;
void freq_update(int l, int r) {
  while (fl < l) {
    freq[A[fl]]--;
    add -= freq[A[fl]];
    fl++;
  }
  while (fl > l) {
    fl--;
    add += freq[A[fl]];
    freq[A[fl]]++;
  }
  while (fr < r) {
    fr++;
    add += freq[A[fr]];
    freq[A[fr]]++;
  }
  while (fr > r) {
    freq[A[fr]]--;
    add -= freq[A[fr]];
    fr--;
  }
}
void solve(int l, int r, int bestl, int bestr) {
  int mid = (l + r) >> 1;
  tl = bestl;
  tr = min(bestr, mid - 1);
  for (int i = (tl); i <= (tr); i++) {
    freq_update(i + 1, mid);
    tmp = dp[m - 1][i] + add;
    if (i == tl || tmp < dp[k][mid]) {
      bestpos = i;
      dp[m][mid] = tmp;
    }
  }
  if (l < mid) solve(l, mid - 1, bestl, bestpos);
  if (mid < r) solve(mid + 1, r, bestpos, bestr);
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = (1); i <= (n); i++) scanf("%d", &A[i]);
  for (int i = (1); i <= (n); i++) {
    add += freq[A[i]];
    dp[1][i] = add;
    freq[A[i]]++;
  }
  fl = 1;
  fr = n;
  for (int i = (2); i <= (k); i++) {
    m = i;
    solve(i, n, i - 1, n);
  }
  printf("%lld\n", dp[k][n]);
  return 0;
}
