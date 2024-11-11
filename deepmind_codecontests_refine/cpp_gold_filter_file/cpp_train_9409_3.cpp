#include <bits/stdc++.h>
using namespace std;
const int maxN = 500 + 10;
long long x[maxN], d[maxN][maxN], a[maxN][maxN];
bool mark[maxN];
int main() {
  for (int i = 0; i < maxN; i++)
    for (int j = 0; j < maxN; j++) d[i][j] = 2e9;
  for (int i = 0; i < maxN; i++) d[i][i] = 0;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<long long> res;
  for (int q = n - 1; q >= 0; q--) {
    int cur = x[q];
    d[cur][cur] = 0;
    mark[cur] = 1;
    for (int i = 1; i <= n; i++) d[cur][i] = min(a[cur][i], d[cur][i]);
    for (int i = 1; i <= n; i++) d[i][cur] = min(a[i][cur], d[i][cur]);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][cur] + d[cur][j]);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (!mark[i] || !mark[j]) continue;
        if (i == j) continue;
        ans += d[i][j];
      }
    res.push_back(ans);
  }
  reverse(res.begin(), res.end());
  for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
  cout << endl;
  return 0;
}
