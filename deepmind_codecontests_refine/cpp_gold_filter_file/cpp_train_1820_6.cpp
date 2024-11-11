#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
long long n, k, b[100005], sl = 0;
pair<long long, long long> a[105];
long long f[105][105], g[105][105], c[105][105];
void nhanf() {
  for (long i = 1; i <= 101; i++)
    for (long j = 1; j <= 101; j++) {
      c[i][j] = 0;
      for (long l = 1; l <= 101; l++)
        c[i][j] = (c[i][j] + f[i][l] * f[l][j]) % M;
    }
  for (long i = 1; i <= 101; i++)
    for (long j = 1; j <= 101; j++) f[i][j] = c[i][j];
}
void nhang() {
  for (long i = 1; i <= 101; i++)
    for (long j = 1; j <= 101; j++) {
      c[i][j] = 0;
      for (long l = 1; l <= 101; l++)
        c[i][j] = (c[i][j] + f[i][l] * g[l][j]) % M;
    }
  for (long i = 1; i <= 101; i++)
    for (long j = 1; j <= 101; j++) f[i][j] = c[i][j];
}
void dq(long sl) {
  if (sl <= 1) return;
  dq(sl / 2);
  nhanf();
  if (sl % 2 == 1) nhang();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  if (k == 0) {
    cout << 1;
    return 0;
  }
  for (long i = 1; i <= n; i++) cin >> b[i];
  sort(b + 1, b + 1 + n);
  long d = 1;
  for (long i = 1; i <= n; i++)
    if (b[i] != b[i + 1]) {
      a[++sl] = {b[i], d};
      d = 1;
    } else
      d++;
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  for (long i = 1; i <= 99; i++) f[i + 1][i] = g[i + 1][i] = 1;
  for (long i = 1; i <= sl; i++) {
    f[101 - a[i].first][100] = g[101 - a[i].first][100] = a[i].second;
    f[101 - a[i].first][101] = g[101 - a[i].first][101] = a[i].second;
  }
  f[101][101] = g[101][101] = 1;
  dq(k);
  cout << (f[100][101] + f[101][101]) % M << '\n';
  return 0;
}
