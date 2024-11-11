#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 85 - 69;
bool a[maxn][maxn];
string s[maxn * 2], t[maxn * 2];
int n, m, k;
bool chn;
void tabdil(void) {
  for (int i = 0; i < 2 * m - 1; i++)
    for (int j = i & 1 ^ 1; j < 2 * n - 1; j += 2) t[i] += s[j][i >> 1];
  for (int i = 0; i < 2 * n - 1; i++) s[i] = t[i];
  chn = true;
  swap(n, m);
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < 2 * n - 1; i++) cin >> s[i];
  if (n > m) tabdil();
  int all = n * (m - 1) + m * (n - 1);
  int need = (3 * all + 3) / 4;
  if (k == 1) {
    int cnt = 0;
    for (int i = 0; i < 2 * n - 1; i++)
      cnt += count(s[i].begin(), s[i].end(), 'E');
    if (cnt >= need) {
      cout << "YES\n";
      for (int i = 0; i < n; i++, cout << '\n')
        for (int j = 0; j < m; j++) cout << 1 << ' ';
    } else
      cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    a[i][0] = 0;
    int cnt = i and (a[i][0] xor a[i - 1][0] xor (s[i * 2 - 1][0] == 'E'));
    for (int j = 1; j < m; j++) {
      a[i][j] = a[i][j - 1] xor (s[i * 2][j - 1] == 'N');
      if (i) cnt += a[i][j] xor a[i - 1][j] xor (s[i * 2 - 1][j] == 'E');
    }
    if (cnt <= m / 2)
      for (int j = 0; j < m; j++) a[i][j] = !a[i][j];
  }
  if (chn)
    for (int i = 0; i < m; i++, cout << '\n')
      for (int j = 0; j < n; j++) cout << a[j][i] + 1 << ' ';
  else
    for (int i = 0; i < n; i++, cout << '\n')
      for (int j = 0; j < m; j++) cout << a[i][j] + 1 << ' ';
  return 0;
}
