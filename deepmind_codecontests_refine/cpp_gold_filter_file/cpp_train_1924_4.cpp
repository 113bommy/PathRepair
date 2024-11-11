#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
int ary[10];
double dfs(int n, int m) {
  if (m == 0) {
    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (ary[i] > ary[j]) ans++;
    return ans;
  }
  double ans = 0.0;
  double sum = 0.0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int l = i - j;
      int r = i + j;
      if (l < 0 or r >= n) break;
      swap(ary[l], ary[r]);
      sum += dfs(n, m - 1);
      cnt++;
    }
    for (int j = 0; j < n; ++j) {
      int l = i - j;
      int r = i + j;
      if (l < 0 or r >= n) break;
      swap(ary[l], ary[r]);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int l = i - j;
      int r = i + j + 1;
      if (l < 0 or r >= n) break;
      swap(ary[l], ary[r]);
      sum += dfs(n, m - 1);
      cnt++;
    }
    for (int j = 0; j < n; ++j) {
      int l = i - j;
      int r = i + j + 1;
      if (l < 0 or r >= n) break;
      swap(ary[l], ary[r]);
    }
  }
  ans += sum / cnt;
  return ans;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &ary[i]);
  double ans = dfs(n, m);
  printf("%.12lf\n", ans);
}
