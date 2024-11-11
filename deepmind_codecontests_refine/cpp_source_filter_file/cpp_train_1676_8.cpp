#include <bits/stdc++.h>
const int Mod = (int)1e9 + 7;
const int MX = 1073741822;
const long long MXLL = 9223372036854775807;
const int Sz = 2e4 + 2;
using namespace std;
inline void Read_rap() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long dp1[Sz], dp2[Sz];
int a[Sz], b[Sz];
int n, m, p;
char ans[Sz];
int len;
int cost;
void solve(int lx, int ly, int rx, int ry) {
  if (lx == rx) {
    cost += (a[lx] + b[ly]) % p;
    for (int j = ly + 1; j <= ry; j++)
      ans[len++] = 'S', cost += (a[lx] + b[j]) % p;
    return;
  }
  int mid = (lx + rx) >> 1;
  for (int i = ly - 1; i <= ry + 1; i++) dp1[i] = dp2[i] = 0;
  for (int i = lx; i <= mid; i++)
    for (int j = ly; j <= ry; j++)
      dp1[j] = max(dp1[j], dp1[j - 1]) + (a[i] + b[j]) % p;
  for (int i = rx; i >= mid; i--)
    for (int j = ry; j >= ly; j--)
      dp2[j] = max(dp2[j], dp2[j + 1]) + (a[i] + b[j]) % p;
  int y = 0;
  long long V = -1;
  for (int j = ry; j >= ly; j--) {
    long long val = dp1[j] + dp2[j] - (a[mid] + b[j]) % p;
    if (val > V) {
      V = val;
      y = j;
    }
  }
  solve(lx, ly, mid, y);
  ans[len++] = 'C';
  solve(mid + 1, y, rx, ry);
}
int main() {
  scanf("%d %d %d", &n, &m, &p);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= m; i++) scanf("%d", b + i);
  solve(1, 1, n, m);
  printf("%d\n%s", cost, ans);
  return 0;
}
