#include <bits/stdc++.h>
using namespace std;
long long m, p, f[2][5100];
long long ans, S[5100][5100], a[5100], b[5100];
int n, x;
int v[110000];
int main() {
  ans = 1, S[0][0] = a[0] = b[0] = 1;
  cin >> n >> m >> p;
  for (long long i = 1; i < 5100; i++) {
    for (long long j = 1; j <= i; j++)
      S[i][j] = (S[i - 1][j - 1] + (j - 1LL) * S[i - 1][j]) % p;
    a[i] = (a[i - 1] * (m - i + 1LL)) % p;
    b[i] = (b[i - 1] * i) % p;
  }
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    for (int j = 1; j <= min((long long)v[i], m); j++)
      f[i & 1][j] =
          (((ans * a[j] - f[~i & 1][j] * b[j]) % p + p) * S[v[i]][j]) % p;
    ans = 0;
    for (int j = 0; j < v[i] + 1; j++) ans = (ans + f[i & 1][j]) % p;
    fill_n(f[~i & 1], v[i - 1] + 1, 0);
  }
  cout << ans << endl;
  return 0;
}
