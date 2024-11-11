#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n;
int mask[20][2000];
int ans[20][2000];
int xans[2000];
int main() {
  int i, j, k, l;
  cin >> n;
  int X = 10;
  for (i = 0; i < X; i++) {
    for (j = 0; j < (1 << X); j++) {
      mask[i][j] = !!(j & (1 << i));
      mask[i + X][j] = !mask[i][j];
    }
  }
  for (i = 0; i < X * 2; i++) {
    int cnt = 0;
    vector<int> v;
    for (j = 0; j < n; j++)
      if (mask[i][j]) v.push_back(j), cnt++;
    if (cnt == 0) {
      for (j = 0; j < n; j++) ans[i][j] = 0x3f3f3f3f;
      continue;
    }
    printf("%d\n", cnt);
    for (auto e : v) printf("%d ", e + 1);
    printf("\n");
    fflush(stdout);
    for (j = 0; j < n; j++) scanf("%d", &ans[i][j]);
  }
  memset(xans, 0x3f, sizeof(xans));
  for (i = 0; i < n; i++) {
    for (j = 0; j < X * 2; j++) {
      if (mask[j][i] == 0) xans[i] = min(xans[i], ans[j][i]);
    }
  }
  printf("-1\n");
  for (i = 0; i < n; i++) printf("%d ", xans[i]);
  printf("\n");
  fflush(stdout);
  return 0;
}
