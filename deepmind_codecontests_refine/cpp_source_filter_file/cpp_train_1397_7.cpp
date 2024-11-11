#include <bits/stdc++.h>
using namespace std;
const int MaxN = 10005;
const int oo = 1000000000;
const long long Base = 1000000007;
typedef int Tarr[MaxN];
int n, k, Esp;
int f[105][20005];
Tarr a, b;
int main() {
  Esp = 10000;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) b[i] *= k;
  memset(f, 255, sizeof(f));
  f[0][Esp] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = -10000 + Esp; j <= 10000 + Esp; j++) {
      f[i][j] = f[i - 1][j];
      if (j >= (a[i] - b[i]) && f[i - 1][j - (a[i] - b[i])] > -1)
        f[i][j] = max(f[i][j], f[i - 1][j - (a[i] - b[i])] + a[i]);
    }
  if (f[n][Esp])
    cout << f[n][Esp];
  else
    cout << -1;
  return 0;
}
