#include <bits/stdc++.h>
using namespace std;
const int maxn = 20 + 5;
long long k;
int n, m;
long long inp[maxn][maxn];
long long ans;
int mid;
map<long long, int> N[maxn][maxn];
void calleft(int x, int y, long long val, int cnt) {
  val ^= inp[x][y];
  if (mid == cnt) {
    N[x][y][val]++;
    return;
  }
  if (x + 1 <= n) calleft(x + 1, y, val, cnt + 1);
  if (y + 1 <= m) calleft(x, y + 1, val, cnt + 1);
  return;
}
void calright(int x, int y, long long val, int cnt) {
  if (cnt == n + m - 2 - mid) {
    if (N[x][y].count(k ^ val)) {
      ans += N[x][y][k ^ val];
    }
    return;
  }
  if (x - 1 >= 1) calright(x - 1, y, val ^ inp[x][y], cnt + 1);
  if (y - 1 >= 1) calright(x, y - 1, val ^ inp[x][y], cnt + 1);
  return;
}
int main() {
  cin >> n >> m >> k;
  mid = (n + m - 2) / 2;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> inp[i][j];
  calleft(1, 1, 0, 0);
  calright(n, m, 0, 0);
  cout << ans;
  return 0;
}
