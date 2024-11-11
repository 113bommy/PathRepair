#include <bits/stdc++.h>
using namespace std;
const int M(22), N(100010);
int n, m, d, ans;
int st[M][N];
bool no[1 << M];
int getSt(int l, int r) {
  int t = (int)(log10(r - l + 1) / log10(2));
  return st[t][l] | st[t][r - (1 << t) + 1];
}
int bitCnt(int x) { return x ? bitCnt(x / 2) + x % 2 : 0; }
int main() {
  cin >> n >> m >> d;
  for (int i = 0; i < m; ++i) {
    int t, x;
    for (cin >> t; t; --t) {
      cin >> x;
      st[0][x] = 1 << i;
    }
  }
  for (int i = 1; i != M; ++i)
    for (int j = 1; j + (1 << i) - 1 <= n; ++j)
      st[i][j] = st[i - 1][j] | st[i - 1][j + (1 << (i - 1))];
  for (int i = 1; i + d - 1 <= n; ++i) no[getSt(i, i + d - 1)] = 1;
  int ans = m;
  for (int i = 0; i != (1 << m); ++i) {
    for (int j = 0; j != m; ++j)
      if (i & (1 << j)) no[i] |= no[i - (1 << j)];
    if (!no[i]) ans = min(ans, bitCnt(((1 << m) - 1) ^ i));
  }
  cout << ans << endl;
  return 0;
}
