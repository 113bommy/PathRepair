#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long N = 1e2 + 1;
const long long M = 1e4 + 1;
const long long mod = 1e9 + 7;
const long double eps = 1E-7;
set<int> s;
int n, x, a[N];
int mx, cnt, sum;
bitset<101> g[M][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  g[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    a[x]++;
    sum += x;
    if (a[x] == 1) cnt++;
  }
  if (cnt <= 2) {
    cout << n;
    return 0;
  }
  for (int i = 1; i < N; i++)
    for (int j = 1; j <= a[i]; j++)
      for (int k = i; k <= sum; k++)
        for (int h = 1; h <= n; h++)
          if (g[k - i][h - 1].any()) g[k][h] |= g[k - i][h - 1], g[k][h][i] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 1; j <= a[i]; j++)
      if (g[i * j][j].count() == 2) mx = max(mx, j);
  cout << mx << endl;
}
