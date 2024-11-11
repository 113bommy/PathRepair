#include <bits/stdc++.h>
using namespace std;
int n, lft[1000000], rit[1000000], dp[1000000], bck[1000000];
char s[1000001];
vector<int> pc, fo;
bool ok(int m) {
  int l = 0;
  for (int i = 0; i < (int)(pc.size()); ++i) {
    while (l < (int)fo.size() && fo[l] + m < pc[i]) ++l;
    lft[i] = l;
  }
  l = fo.size() - 1;
  for (int i = pc.size() - 1; i >= 0; --i) {
    while (l >= 0 && fo[l] - m > pc[i]) --l;
    rit[i] = l;
  }
  for (int i = 0; i < (int)(pc.size()); ++i) {
    dp[i] = -1;
    int bf = i ? dp[i - 1] : -1;
    if (bf >= bck[i])
      dp[i] = rit[i];
    else if (lft[i] <= bf + 1)
      dp[i] = bck[i];
    if (i) {
      int bf = i - 1 ? dp[i - 2] : -1;
      if (lft[i] <= bf + 1) dp[i] = max(dp[i], rit[i - 1]);
    }
  }
  return dp[(int)pc.size() - 1] == (int)fo.size() - 1;
}
int main() {
  scanf("%d%s", &n, s);
  for (int i = 0; i < (int)(n); ++i)
    if (s[i] == 'P')
      pc.push_back(i);
    else if (s[i] == '*')
      fo.push_back(i);
  if ((int)pc.size() == 1) {
    int an = 0, mx = 0;
    for (int i = pc[0]; i < (int)(n); ++i)
      if (s[i] == '*') ++an, mx = i;
    int an2 = 0, mn = 1e9;
    for (int i = pc[0]; i >= 0; --i)
      if (s[i] == '*') ++an2, mn = i;
    if (an > an2)
      printf("%d %d\n", an, mx - pc[0]);
    else if (an2 > an)
      printf("%d %d\n", an2, pc[0] - mn);
    else if (mx - pc[0] < pc[0] - mn)
      printf("%d %d\n", an, mx - pc[0]);
    else
      printf("%d %d\n", an, pc[0] - mn);
    return 0;
  }
  int l = -1, pcc = 0;
  for (int i = 0; i < (int)(n); ++i)
    if (s[i] == 'P')
      bck[pcc] = l, ++pcc;
    else if (s[i] == '*')
      ++l;
  l = 1;
  int r = n;
  while (r > l) {
    int m = l + r >> 1;
    if (ok(m))
      r = m;
    else
      l = m + 1;
  }
  printf("%d %d\n", (int)fo.size(), l);
}
