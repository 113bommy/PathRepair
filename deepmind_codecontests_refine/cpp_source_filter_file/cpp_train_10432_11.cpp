#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 5;
int n, row[maxn], col[maxn], Row[maxn], Col[maxn];
char first[maxn][maxn];
void chn(int x, int y) {
  row[x]++;
  col[y]++;
}
char get(int x, int y) {
  int ret = row[x] + col[y];
  if (ret % 2 == 0) return '0';
  return '1';
}
void Chn(int x, int y) {
  Row[x]++;
  Col[x]++;
}
char Get(int x, int y) {
  int ret = Row[x] + Col[y];
  if (ret % 2 == 0) return '0';
  return '1';
}
char GET(int x, int y) {
  int ret = Row[x] + Col[y] + row[x] + col[y];
  if (ret % 2 == 0) return '0';
  return '1';
}
int main() {
  ios_base::sync_with_stdio(false);
  int ans = 0;
  cin >> n;
  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= n; j++) cin >> first[i][j];
  for (int sum = 2 * n; sum > n + 1; sum--) {
    for (int i = n; i + n >= sum; i--) {
      int j = sum - i;
      if (get(i, j) != first[i][j]) {
        chn(i, j);
        ans++;
      }
    }
  }
  for (int sum = 1; sum <= n; sum++) {
    for (int i = 1; i + 1 <= sum; i++) {
      int j = sum - i;
      if (Get(i, j) != first[i][j]) {
        Chn(i, j);
        ans++;
      }
    }
  }
  for (int i = 1; i <= n; i++)
    if (GET(i, n + 1 - i) != first[i][n + 1 - i]) ans++;
  cout << ans;
}
