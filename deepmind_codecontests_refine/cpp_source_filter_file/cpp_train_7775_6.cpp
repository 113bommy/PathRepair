#include <bits/stdc++.h>
using namespace std;
int A[2009], B[2009];
int d[2][1000], drum[10][10][10000];
int v[4], urm[10000][16], masca[10000][16];
inline int getVal(int x) {
  int u = 0;
  bool ok = 0;
  for (int i = 0; i < 4; i++) {
    int c = x % 10;
    x /= 10;
    if (c == 0) {
      if (ok)
        u *= 10;
      else
        ok = 1;
    } else {
      u *= 10;
      u += c;
    }
  }
  if (!ok) return -1;
  return u;
}
inline void precalc() {
  for (int i = 0; i < 10000; i++) {
    int x = i;
    for (int j = 0; j < 4; j++) {
      v[j] = x % 10;
      x /= 10;
    }
    for (int j = 0; j < 16; j++) {
      x = 0;
      for (int p = 0; p < 4; p++) {
        x *= 10;
        if ((j & (1 << p)) == 0) x += v[p];
      }
      urm[i][j] = getVal(x);
      x = 0;
      for (int p = 0; p < 4; p++) {
        x *= 10;
        if (j & (1 << p)) x += v[p];
      }
      masca[i][j] = getVal(x);
    }
  }
  for (int i = 1; i <= 9; i++)
    for (int j = 1; j <= 9; j++) drum[i][j][0] = abs(i - j);
  for (int i = 1; i < 10000; i++) {
    int sus = 0, jos = 10, x = i;
    for (int j = 0; j < 4; j++) {
      int c = x % 10;
      if (c) {
        sus = max(sus, c);
        jos = min(jos, c);
      }
      x /= 10;
    }
    for (int a = 1; a <= 9; a++)
      for (int b = 1; b <= 9; b++)
        drum[a][b][i] = min(abs(a - jos) + sus - jos + abs(sus - b),
                            abs(a - sus) + sus - jos + abs(jos - b));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  precalc();
  for (int i = 0; i < 1000; i++) d[0][i] = 100000000;
  d[0][0] = 0;
  int a = 0, b = 1;
  A[0] = 1;
  B[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> A[i] >> B[i];
    for (int j = 0; j < 1000; j++) d[b][j] = 100000000;
    for (int j = 0; j < 1000; j++) {
      int s = 10 * j + B[i - 1];
      for (int p = 0; p < 16; p++)
        if (urm[s][p] != -1)
          d[b][urm[s][p]] =
              min(d[b][urm[s][p]], d[a][j] + drum[A[i - 1]][A[i]][masca[s][p]]);
    }
    a ^= 1;
    b ^= 1;
  }
  int ans = 100000000;
  for (int j = 0; j < 1000; j++) {
    int s = 10 * j + B[n];
    for (int p = 0; p < 16; p++)
      if (urm[s][p] == 0)
        for (int c = 1; c < 10; c++)
          ans = min(ans, d[a][j] + drum[A[n]][c][masca[s][p]]);
  }
  cout << ans + 2 * n;
  return 0;
}
