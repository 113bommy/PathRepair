#include <bits/stdc++.h>
using namespace std;
int n, m, k, i, v;
string s, f, ans;
char news(char x, char y) {
  while (true) {
    int z = rand() % 26;
    if (char(z + 'a') != x && char(z + 'a') != y) return char(z + 'a');
  }
}
int main() {
  srand(time(NULL));
  cin >> n >> m;
  cin >> s >> f;
  for (i = 0; i < n; ++i)
    if (s[i] == f[i]) ++k;
  if (m * 2 < (n - k)) {
    cout << -1;
    return 0;
  }
  ans = s;
  k = 0;
  v = m;
  for (i = 0; i < n; ++i) {
    if (m == 0) break;
    if (s[i] != f[i]) m--, ans[i] = f[i];
  }
  for (i = 0; i < n; ++i) {
    if (m == 0) break;
    if (s[i] == f[i]) ans[i] = news(ans[i], f[i]), --m;
  }
  if (m > 0) cout << -1;
  for (i = 0; i < n; ++i)
    if (ans[i] != f[i]) ++k;
  for (i = 0; i < n; ++i) {
    if (k == v) break;
    if (s[i] != f[i]) ans[i] = news(ans[i], f[i]), ++k;
  }
  cout << ans;
}
