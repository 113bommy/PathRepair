#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
const int MAXN = 22;
int num[MAXN][MAXN], n, m;
bool ok() {
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = 1; j <= m; ++j) {
      cnt += (num[i][j] != j);
      if (cnt > 2) return 0;
    }
  }
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> num[i][j];
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = i + 1; j <= m; ++j) {
      for (int k = 1; k <= n; ++k) {
        swap(num[k][i], num[k][j]);
      }
      if (ok()) {
        puts("YES");
        return 0;
      }
      for (int k = 1; k <= n; ++k) {
        swap(num[k][i], num[k][j]);
      }
    }
  }
  puts("NO");
  return 0;
}
