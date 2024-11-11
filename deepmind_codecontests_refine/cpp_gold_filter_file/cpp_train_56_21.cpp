#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, u, v;
char s[N];
bitset<N> f[30][N], ans[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> (s + 1);
    for (int j = 1; j <= m; ++j)
      f[s[j] - 'a'][i][j] = f[s[j] - 'a'][i][j + m] = ans[i][j] = 1;
  }
  cin >> u >> v;
  for (int i = 1; i <= u; ++i) {
    cin >> (s + 1);
    for (int j = 1; j <= v; ++j)
      if (s[j] != '?')
        for (int k = 1; k <= n; ++k)
          ans[k] &= (f[s[j] - 'a'][(k + i - 2) % n + 1] >> ((j - 1) % m));
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) cout << ans[i][j];
    cout << '\n';
  }
  return 0;
}
