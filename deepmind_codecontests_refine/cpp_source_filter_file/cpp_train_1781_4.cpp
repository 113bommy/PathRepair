#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 12) + 5;
int rep[N];
int w, n, m;
char str[N];
int p3[15];
int getVal(int mask, int i) { return mask / p3[i] % 3; }
int setVal(int mask, int i, int j) {
  int diffVal = j - getVal(mask, i);
  return mask + diffVal * p3[i];
}
bool check(int mask) {
  for (int(i) = (0); (i) <= (int)(w - 1); (i)++)
    if (getVal(mask, i) == 2) return false;
  return true;
}
int convertDomain(int mask) {
  int ret = 0;
  assert(check(mask));
  for (int(i) = (0); (i) <= (int)(w - 1); (i)++) ret |= getVal(mask, i) << i;
  return ret;
}
long long dp[15][50000];
long long cnt(int i, int mask) {
  if (i == w) return rep[convertDomain(mask)];
  long long &ret = dp[i][mask];
  if (~ret) return ret;
  ret = 0;
  if (getVal(mask, i) == 2)
    return ret =
               cnt(i + 1, setVal(mask, i, 0)) + cnt(i + 1, setVal(mask, i, 1));
  return ret = cnt(i + 1, mask);
}
long long ans = 0;
void solve(int i, int mask2, int mask3, char *str) {
  if (i == w) {
    ans += rep[mask2] * cnt(0, mask3);
    return;
  }
  if (str[i] == 'A') {
    solve(i + 1, mask2, mask3 + 2 * p3[i], str);
    solve(i + 1, mask2 | (1 << i), mask3, str);
  } else if (str[i] == 'O') {
    solve(i + 1, mask2, mask3, str);
  } else if (str[i] == 'X') {
    solve(i + 1, mask2, mask3, str);
    solve(i + 1, mask2 | (1 << i), mask3 + 1 * p3[i], str);
  } else if (str[i] == 'a') {
    solve(i + 1, mask2 | (1 << i), mask3 + 1 * p3[i], str);
  } else if (str[i] == 'o') {
    solve(i + 1, mask2, mask3 + 1 * p3[i], str);
    solve(i + 1, mask2 | (1 << i), mask3 + 2 * p3[i], str);
  } else {
    solve(i + 1, mask2, mask3 + 1 * p3[i], str);
    solve(i + 1, mask2 | (1 << i), mask3, str);
  }
}
int main() {
  p3[0] = 1;
  for (int(i) = (1); (i) <= (int)(12); (i)++) p3[i] = p3[i - 1] * 3;
  scanf("%d%d%d", &w, &n, &m);
  for (int(i) = (1); (i) <= (int)(n); (i)++) {
    int x;
    scanf("%d", &x);
    ++rep[x];
  }
  memset(dp, -1, sizeof dp);
  for (int(j) = (1); (j) <= (int)(m); (j)++) {
    scanf("%s", str);
    reverse(str, str + w);
    ans = 0;
    solve(0, 0, 0, str);
    printf("%lld\n", ans);
  }
  return 0;
}
