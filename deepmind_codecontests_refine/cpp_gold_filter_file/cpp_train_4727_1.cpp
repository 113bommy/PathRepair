#include <bits/stdc++.h>
using namespace std;
void _fill_int(int* p, int val, int rep) {
  int i;
  for (i = 0; i < rep; i++) p[i] = val;
}
void _fill_ll(signed long long* p, signed long long val, int rep) {
  int i;
  for (i = 0; i < rep; i++) p[i] = val;
}
signed long long GETi() {
  signed long long i;
  scanf("%lld", &i);
  return i;
}
int N, K;
signed long long mo = 1000000007;
signed long long dpdp[205][205][16];
const int CN = 20;
signed long long C[CN][CN];
signed long long dodp(int level, int num, int mask) {
  int ma, i, j, k[5], l;
  if (num == 0) return 1;
  if (num < 0 || mask == 0) return 0;
  if (dpdp[level][num][mask] != -1) return dpdp[level][num][mask];
  signed long long ret = 0;
  for (ma = 0; ma < 16; ma++) {
    if ((mask & ma) != ma) continue;
    int bi = __builtin_popcount(ma);
    k[0] = k[1] = k[2] = k[3] = k[4] = 0;
    k[bi] = 1;
    if (bi == 2 && (ma != 5) && (ma != 10)) k[1]++;
    if (bi == 3) k[2] += 2;
    if (bi == 4) k[2] += 2, k[3] += 4;
    if (level > 0) {
      int ma2 = mask ^ ma;
      if (ma2 == 13 || ma2 == 11 || ma2 == 14) ma2 = 7;
      if (ma2 == 9 || ma2 == 6 || ma2 == 12) ma2 = 3;
      if (ma2 == 10) ma2 = 5;
      if (ma2 == 2 || ma2 == 4 || ma2 == 8) ma2 = 1;
      int x, y;
      for (l = 0; l < 5; l++) {
        if (k[l] == 0) continue;
        if (num - l < 0) continue;
        if (ma2 == 0)
          x = 0, y = 0;
        else if (ma2 == 1)
          x = 3, y = 0;
        else if (ma2 == 5)
          x = 6, y = 0;
        else if (ma2 == 3)
          x = 6, y = 1;
        else if (ma2 == 7)
          x = 9, y = 2;
        else if (ma2 == 15)
          x = 12, y = 4;
        for (i = 0; i < y + 1; i++)
          for (j = 0; j < x - i * 2 + 1; j++)
            ret += dodp(level - 1, num - l - (i + j), ma2) *
                   ((k[l] * C[y][i] * C[x - i * 2][j]) % mo);
      }
    } else {
      for (l = 0; l < 5; l++) ret += (num == l) * k[l];
    }
  }
  return dpdp[level][num][mask] = (ret %= mo);
}
void solve() {
  int f, i, j, k, l, x, y;
  cin >> N >> K;
  for (x = 0; x < CN; x++) C[x][0] = C[x][x] = 1;
  for (i = 1; i < CN; i++)
    for (j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mo;
  _fill_ll((signed long long*)dpdp, -1LL, sizeof(dpdp) / 8);
  signed long long ret = dodp(N, K, 15);
  for (i = 0; i < K; i++) ret = (ret * (i + 1)) % mo;
  cout << ret << endl;
}
int main(int argc, char** argv) {
  if (argc > 1) freopen(argv[1], "r", stdin);
  solve();
  return 0;
}
