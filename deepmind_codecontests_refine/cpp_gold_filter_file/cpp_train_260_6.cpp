#include <bits/stdc++.h>
using namespace std;
void judge() {
  freopen("array.in", "r", stdin);
  freopen("array.out", "w", stdout);
}
const int N = 21, inf = 1e9;
int ans = inf, f[N][1 << N], n, m, a[N][110000];
char s[110000];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (register int i = 1; i <= n; i++) {
    cin >> s + 1;
    for (register int j = 1; j <= m; j++) a[i][j] = s[j] - '0';
  }
  int Num = (1 << n) - 1;
  for (register int i = 1; i <= m; i++) {
    int s = 0;
    for (register int j = 1; j <= n; j++)
      if (a[j][i] == 1) s += (1 << (j - 1));
    f[0][s]++;
  }
  for (register int i = 1; i <= n; i++) {
    for (register int j = n; j; j--) {
      for (register int s = 0; s <= Num; s++)
        f[j][s] += f[j - 1][s ^ (1 << (i - 1))];
    }
  }
  for (register int s = 0; s <= Num; s++) {
    int t = 0;
    for (register int i = 1; i <= n; i++) t += min(i, n - i) * f[i][s];
    ans = min(t, ans);
  }
  cout << ans << endl;
  return 0;
}
