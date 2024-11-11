#include <bits/stdc++.h>
using namespace std;
int dp[3939][50];
int n, m, k;
int a[3939];
int getMin(int x, int y) { return x < y ? x : y; }
int getMax(int x, int y) { return x > y ? x : y; }
void solve() {
  int i = 0, j, d;
  vector<int> vec;
  scanf("%d %d %d", &n, &m, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  d = n - m;
  for (i = 0; i + d < n; i++) {
    vec.push_back(getMax(a[i], a[i + d]));
  }
  for (i = 0; i < vec.size(); i++) {
    dp[i][0] = vec[i];
  }
  int ans = 0;
  d = vec.size() - k;
  if (d < 1) d = 1;
  for (i = 0; i + d <= vec.size(); i++) {
    int x = vec[i];
    for (j = 0; j < d; j++) {
      if (vec[i + j] < x) {
        x = vec[i + j];
      }
    }
    if (x > ans) {
      ans = x;
    }
  }
  printf("%d\n", ans);
}
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
