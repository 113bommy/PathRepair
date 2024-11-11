#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010, inf = 1000000000, mod = 1e9 + 7, delta = 31259;
vector<int> v;
long long c[maxn][maxn];
int main() {
  for (int i = 0; i < maxn; i++) c[i][i] = c[0][i] = 1;
  for (int i = 1; i < maxn; i++)
    for (int j = i + 1; j < maxn; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i][j - 1]) % mod;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  int t = n - m;
  long long ans = c[v[0] - 1][t];
  t -= v[0] - 1;
  ans *= c[n - v[m - 1]][t];
  t -= n - v[m - 1];
  for (int i = 1; i < m; i++) {
    for (int j = 0; j < v[i] - v[i - 1] - 2; j++) ans = (ans * 2) % mod;
    ans = (ans * c[v[i] - v[i - 1] - 1][t]) % mod;
    t -= v[i] - v[i - 1] - 1;
  }
  cout << ans << endl;
  return 0;
}
