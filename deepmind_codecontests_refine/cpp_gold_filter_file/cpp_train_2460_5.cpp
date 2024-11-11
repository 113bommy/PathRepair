#include <bits/stdc++.h>
using namespace std;
const int maxn = 40010;
int n, m, ans;
bool a[2][maxn];
int par[maxn];
int find(int x) { return par[x] == x ? x : (par[x] = find(par[x])); }
int merge(int x1, int x2) {
  int f1 = find(x1);
  int f2 = find(x2);
  if (f1 != f2) {
    par[f2] = f1;
    return 1;
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  int k = m / 4;
  for (int i = 0; i < n; i++) {
    int t = i & 1;
    string s;
    cin >> s;
    for (int j = 0; j < k; j++) {
      int r;
      if (isdigit(s[j]))
        r = s[j] - '0';
      else
        r = s[j] - 'A' + 10;
      a[t][j * 4 + 3] = r & 1, ans += (r & 1), r >>= 1;
      a[t][j * 4 + 2] = r & 1, ans += (r & 1), r >>= 1;
      a[t][j * 4 + 1] = r & 1, ans += (r & 1), r >>= 1;
      a[t][j * 4] = r & 1, ans += (r & 1);
    }
    int l = t * m;
    for (int j = 0; j < m; j++) par[l + j] = l + j;
    for (int j = 0; j < m - 1; j++)
      if (a[t][j] && a[t][j + 1]) ans -= merge(l + j, l + j + 1);
    for (int j = 0; j < m; j++)
      if (a[t][j] && a[t ^ 1][j]) ans -= merge(l + j, (t ^ 1) * m + j);
  }
  cout << ans << '\n';
}
