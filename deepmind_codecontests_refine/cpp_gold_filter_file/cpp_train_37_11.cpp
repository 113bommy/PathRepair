#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, R, C, ans, st;
string s[N];
int a[N], sum[N];
int p[22][N];
int t[22][N];
int main() {
  scanf("%d%d%d", &n, &R, &C);
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    a[i] = s[i].size();
  }
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  for (int i = 1; i <= n; i++) {
    int l = i - 1, r = n;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (sum[mid] - sum[i - 1] + mid - i <= C)
        l = mid + 1;
      else
        r = mid - 1;
    }
    p[0][i] = l;
  }
  p[0][n + 1] = n + 1;
  for (int i = 0; i < 21; i++)
    for (int j = 1; j <= n + 1; j++) p[i + 1][j] = p[i][p[i][j]];
  for (int i = 1; i <= n; i++) {
    int x = i;
    for (int j = 0; j < 21; j++)
      if (R & (1 << j)) x = p[j][x];
    if (ans < x - i) {
      ans = x - i;
      st = i;
    }
  }
  for (int i = 1; i <= R; i++) {
    for (int j = st; j < p[0][st]; j++) {
      printf("%s", s[j].c_str());
      if (j + 1 != p[0][st]) printf(" ");
    }
    puts("");
    st = p[0][st];
  }
  return 0;
}
