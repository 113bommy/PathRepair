#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const long long oo = 1e15;
long long f[N][4], a[N], b[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= 2; j++) f[i][j] = oo;
    a[0] = -1;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < 3; j++)
        for (int k = 0; k < 3; k++)
          if (a[i - 1] + j != a[i] + k)
            f[i][k] = min(f[i][k], f[i - 1][j] + b[i] * k);
    cout << min(f[n][0], min(f[n][1], f[n][2])) << '\n';
  }
}
