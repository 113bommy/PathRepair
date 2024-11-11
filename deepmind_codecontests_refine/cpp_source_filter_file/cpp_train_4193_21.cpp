#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e15 + 1;
const long long maxn = 101;
long long t, n, m, dem;
char a[maxn][maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  while (t--) {
    dem = 0;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= m; j++) cin >> a[i][j];
    for (long long i = 1; i <= m - 1; i++)
      if (a[1][i] == 'D') dem++;
    for (long long i = 1; i <= n; i++)
      if (a[i][m] == 'R') dem++;
    cout << dem << endl;
  }
}
