#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
vector<int> b[N], c[N], sum[N];
string s[N];
int n, m;
int get(int i, int j, int i1, int j1) {
  return sum[i1][j1] - sum[i1][j - 1] - sum[i - 1][j1] + sum[i - 1][j - 1];
}
bool judge(int x) {
  int len = x * 2 + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum[i][j] =
          sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (s[i][j] == 'X');
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i + len - 1 <= n && j + len - 1 <= m) {
        if (get(i, j, i + len - 1, j + len - 1) == len * len) {
          b[i][j] = 1;
        } else
          b[i][j] = 0;
      } else
        b[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + b[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'X') {
        int i1 = max(1, i - len + 1), j1 = max(1, j - len + 1);
        if (get(i1, j1, i, j) == 0) return false;
      }
    }
  }
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = " " + s[i];
  }
  for (int i = 0; i <= n + 5; i++) {
    sum[i].resize(m + 5);
    b[i].resize(m + 5);
    c[i].resize(m + 5);
  }
  int l = 0, r = min(n, m), ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (judge(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  judge(ans);
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (b[i][j]) {
        c[i + ans][j + ans] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (c[i][j])
        printf("X");
      else
        printf(".");
    }
    printf("\n");
  }
  return 0;
}
