#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
const int maxn = 1E4 + 10;
const long long INF = 1E16;
int n, cur, s[maxn], t[maxn];
long long c, f[2][maxn];
int main() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
  for (int i = 1; i <= n; i++) {
    f[cur ^ 1][i] = INF;
    for (int j = 1; j <= i; j++)
      f[cur][j] =
          min(f[cur ^ 1][j] + s[i] + 1LL * j * c, f[cur ^ 1][j - 1] + t[i]);
    f[cur][0] = f[cur ^ 1][0] + s[i];
    cur ^= 1;
  }
  long long Ans = INF;
  cur ^= 1;
  for (int i = 0; i <= n; i++) Ans = min(Ans, f[cur][i]);
  cout << Ans;
  return 0;
}
