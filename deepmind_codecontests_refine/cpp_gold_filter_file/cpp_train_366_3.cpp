#include <bits/stdc++.h>
using namespace std;
int n, m, p[200010][40];
long long k, ans1, ans2, sum[200010][40], Min[200010][40];
void init() {
  for (int i = 1; i < 35; i++)
    for (int j = 0; j < n; j++)
      p[j][i] = p[p[j][i - 1]][i - 1],
      Min[j][i] = min(Min[j][i - 1], Min[p[j][i - 1]][i - 1]),
      sum[j][i] = sum[j][i - 1] + sum[p[j][i - 1]][i - 1];
}
void query(int x, long long y) {
  ans1 = 0;
  ans2 = (long long)10e10;
  long long k;
  int z = x;
  for (int i = 34; i >= 0; i--) {
    k = 1LL << i;
    if (y >= k) {
      y -= k;
      ans1 += sum[z][i];
      ans2 = min(Min[z][i], ans2);
      z = p[z][i];
    }
  }
}
int main() {
  cin >> n >> k;
  int x;
  for (int i = 0; i < n; i++) scanf("%d", &p[i][0]);
  for (int i = 0; i < n; i++) scanf("%I64d", &sum[i][0]), Min[i][0] = sum[i][0];
  init();
  for (int i = 0; i < n; i++) query(i, k), printf("%I64d %I64d\n", ans1, ans2);
  return 0;
}
