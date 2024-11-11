#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5005;
int n, z[N][N], f[N];
char s[N];
void solve() {
  scanf("%d%s", &n, s + 1);
  for (int i = (n); i >= (1); i--)
    for (int j = (n); j >= (i); j--)
      z[i][j] = s[i] == s[j] ? (j <= n ? z[i + 1][j + 1] + 1 : 1) : 0;
  int as = 0;
  memset(f, 0, sizeof f);
  for (int i = (1); i <= (n); i++)
    for (int j = (0), je = (i); j < je; j++) {
      int l = z[j][i];
      if (i + l <= n && s[i + l] > s[j + l])
        (as = min(as, (f[i] = min(f[i], f[j] + n - i - l + 1))));
    }
  printf("%d\n", as);
}
int main() {
  int T;
  for (cin >> T; T--; solve())
    ;
}
