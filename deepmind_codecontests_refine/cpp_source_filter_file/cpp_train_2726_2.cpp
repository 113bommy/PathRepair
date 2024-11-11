#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long ModPow(long long base, long long exp, long long m) {
  long long r = 1, p;
  base %= m;
  while (exp) {
    if (exp & 1) r = (r * base) % m;
    exp = exp >> 1;
    base = (base * base) % m;
  }
  return r;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long h, w;
  cin >> h >> w;
  long long r[h + 1], c[w + 1];
  for (long long i = 1; i <= h; i++) cin >> r[i];
  for (long long i = 1; i <= w; i++) cin >> c[i];
  long long mat[h + 5][w + 5];
  for (long long i = 0; i < h + 5; i++)
    for (long long j = 0; j < w + 5; j++) mat[i][j] = -1;
  bool check = 1;
  for (long long i = 1; i <= h; i++) {
    long long j = 1;
    for (; j <= r[i]; j++) mat[i][j] = 1;
    mat[i][j] = 0;
  }
  for (long long j = 1; j <= w; j++) {
    long long i = 1;
    for (; i <= c[j]; i++) {
      if (mat[i][j] != -1)
        check = 0;
      else
        mat[i][j] = 1;
    }
    if (mat[i][j] == 1) check = 0;
    mat[i][j] = 0;
  }
  long long cnt = 0;
  for (long long i = 1; i <= h; i++) {
    for (long long j = 1; j <= w; j++)
      if (mat[i][j] == -1) cnt++;
  }
  long long ans = ModPow(2, cnt, MOD);
  if (!check)
    cout << 0;
  else
    cout << ans;
  return 0;
}
