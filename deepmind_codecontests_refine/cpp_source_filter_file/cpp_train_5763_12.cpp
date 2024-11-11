#include <bits/stdc++.h>
using namespace std;
long long f[1000][1000];
long long rsum[1000];
long long csum[1000];
long long rs[1001];
long long cs[1001];
int main() {
  int h, w;
  long long i, j;
  scanf("%d %d", &h, &w);
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      scanf("%I64d", &f[i][j]);
    }
  }
  for (i = 0; i < h; i++) {
    rsum[i] = 0;
    for (j = 0; j < w; j++) rsum[i] += f[i][j];
  }
  for (i = 0; i <= h; i++) {
    rs[i] = 0;
    for (j = 0; j < i; j++)
      rs[i] += ((i - j - 1) * 4 + 2) * ((i - j - 1) * 4 + 2) * rsum[j];
    for (j = i; j < h; j++)
      rs[i] += ((j - i) * 4 + 2) * ((j - i) * 4 + 2) * rsum[j];
  }
  for (i = 0; i < w; i++) {
    csum[i] = 0;
    for (j = 0; j < h; j++) csum[i] += f[j][i];
  }
  for (i = 0; i <= w; i++) {
    cs[i] = 0;
    for (j = 0; j < i; j++)
      cs[i] += ((i - j - 1) * 4 + 2) * ((i - j - 1) * 4 + 2) * csum[j];
    for (j = i; j < w; j++)
      cs[i] += ((j - i) * 4 + 2) * ((j - i) * 4 + 2) * csum[j];
  }
  long long mx = 1000000000000000LL;
  pair<int, int> ans = pair<int, int>(0, 0);
  for (i = 0; i <= h; i++) {
    for (j = 0; j <= w; j++) {
      long long res = rs[i] + cs[j];
      if (res < mx) {
        mx = res;
        ans = pair<int, int>(i, j);
      }
    }
  }
  printf("%I64d\n", mx);
  printf("%d %d\n", ans.first, ans.second);
  return 0;
}
