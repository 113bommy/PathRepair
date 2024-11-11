#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, MAXN = 1e5 + 7;
long long m[8][20][3][3];
long long f[3], g[3];
void init() {
  m[0][0][0][0] = 1;
  m[0][0][0][1] = 1;
  m[0][0][0][2] = 0;
  m[0][0][1][0] = 1;
  m[0][0][1][1] = 1;
  m[0][0][1][2] = 1;
  m[0][0][2][0] = 0;
  m[0][0][2][1] = 1;
  m[0][0][2][2] = 1;
  for (int i = 1; i <= 7; i++)
    for (int j = 0; j <= 2; j++) {
      if (i & (1 << j))
        for (int k = 0; k <= 2; k++) m[i][0][j][k] = 0;
      else
        for (int k = 0; k <= 2; k++) m[i][0][j][k] = m[0][0][j][k];
    }
  for (int i = 1; i < 10; i++)
    for (int j = 0; j <= 7; j++)
      for (int k1 = 0; k1 <= 2; k1++)
        for (int k2 = 0; k2 <= 2; k2++)
          for (int k3 = 0; k3 <= 2; k3++)
            m[j][i][k1][k2] =
                (m[j][i][k1][k2] +
                 m[j][i - 1][k1][k3] * (long long)m[j][i - 1][k3][k2] % mod) %
                mod;
}
long long n, m2;
long long cut[MAXN];
long long cntn, cntn2;
pair<long long, long long> A[MAXN];
pair<long long, pair<long long, long long> > A2[MAXN];
int now3[3], now4;
int main() {
  init();
  cin >> n >> m2;
  for (long long i = 1, i2, i3, i4; i <= n; i++) {
    cin >> i2 >> i3 >> i4;
    A2[++cntn2].first = i3;
    A2[cntn2].second.first = i2 - 1;
    A2[cntn2].second.second = 1;
    A2[++cntn2].first = i4 + 1;
    A2[cntn2].second.first = i2 - 1;
    A2[cntn2].second.second = 0;
  }
  sort(A2 + 1, A2 + 1 + cntn2);
  for (long long i = 1; i <= cntn2; i++) {
    if (A[cntn].first != A2[i].first) A[++cntn].first = A2[i].first;
    if (A2[i].second.second == 0)
      now3[A2[i].second.first]--;
    else
      now3[A2[i].second.first]++;
    now4 = 0;
    if (now3[0]) now4 |= 1;
    if (now3[1]) now4 |= 2;
    if (now3[2]) now4 |= 4;
    A[cntn].second = now4;
  }
  if (A[cntn].first != m2 + 1) {
    A[++cntn].first = m2 + 1;
    A[cntn].second = 0;
  }
  f[1] = 1;
  for (long long i = 1, now = 1, now2 = 0, i2, i3; i <= cntn; i++) {
    if (i == 1)
      i2 = A[i].first - 2;
    else
      i2 = A[i].first - now;
    i3 = 0;
    while (i2) {
      if (i2 & 1) {
        g[0] = g[1] = g[2] = 0;
        for (int k1 = 0; k1 <= 2; k1++) {
          for (int k2 = 0; k2 <= 2; k2++) {
            g[k1] =
                (g[k1] + f[k2] * (long long)m[now2][i3][k1][k2] % mod) % mod;
          }
        }
        f[0] = g[0];
        f[1] = g[1];
        f[2] = g[2];
      }
      i3++;
      i2 >>= 1;
    }
    now2 = A[i].second;
    now = A[i].first;
  }
  cout << f[1] << endl;
}
