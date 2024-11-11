#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int n, m;
char s[maxn];
long long num[maxn][5];
long long mu[maxn];
long long tmp;
long long res;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) num[j][s[j] - 'A']++;
  }
  for (int i = 0; i < m; i++) cin >> mu[i];
  res = 0;
  for (int i = 0; i < m; i++) {
    tmp = 0;
    for (int j = 0; j < 5; j++) tmp = max(tmp, num[i][j]);
    res = res + tmp * mu[i];
  }
  cout << res << endl;
  return 0;
}
