#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
long long sum[35][2][2][2], cnt[35][2][2][2];
inline long long Calc(int _x, int _y, int _K) {
  if (_x == -1 || _y == -1) return 0;
  int x[35] = {0}, y[35] = {0}, K[35] = {0}, _p = 0;
  _p = -1;
  while (_x) x[++_p] = _x & 1, _x >>= 1;
  _p = -1;
  while (_y) y[++_p] = _y & 1, _y >>= 1;
  _p = -1;
  while (_K) K[++_p] = _K & 1, _K >>= 1;
  memset(sum, 0, sizeof(sum));
  memset(cnt, 0, sizeof(cnt));
  cnt[30][0][0][0] = 1;
  for (int i = 30; i; i--)
    for (int t1 = 0; t1 < 2; t1++)
      for (int t2 = 0; t2 < 2; t2++)
        for (int t3 = 0; t3 < 2; t3++) {
          for (int a = 0; a <= (t1 ? 1 : x[i - 1]); a++)
            for (int b = 0; b <= (t2 ? 1 : y[i - 1]); b++) {
              if ((a ^ b) > (t3 ? 1 : K[i - 1])) continue;
              int nt1 = t1 | (a < x[i - 1]), nt2 = t2 | (b < y[i - 1]),
                  nt3 = t3 | ((a ^ b) < K[i - 1]);
              (cnt[i - 1][nt1][nt2][nt3] += cnt[i][t1][t2][t3]) %= P;
              (sum[i - 1][nt1][nt2][nt3] +=
               sum[i][t1][t2][t3] +
               cnt[i][t1][t2][t3] * ((a ^ b) << (i - 1)) % P) %= P;
            }
        }
  long long Sum = 0, Cnt = 0;
  for (int t1 = 0; t1 < 2; t1++)
    for (int t2 = 0; t2 < 2; t2++)
      for (int t3 = 0; t3 < 2; t3++)
        (Sum += sum[0][t1][t2][t3]) %= P, (Cnt += cnt[0][t1][t2][t3]) %= P;
  return (Sum + Cnt) % P;
}
int main() {
  int Q, x1, x2, y1, y2, K;
  scanf("%d", &(Q));
  while (Q--) {
    scanf("%d", &(x1));
    scanf("%d", &(y1));
    scanf("%d", &(x2));
    scanf("%d", &(y2));
    scanf("%d", &(K));
    x1--;
    y1--;
    x2--;
    y2--;
    K--;
    printf("%I64d\n", (Calc(x2, y2, K) + P - Calc(x2, y1 - 1, K) + P -
                       Calc(x1 - 1, y2, K) + Calc(x1 - 1, y1 - 1, K)) %
                          P);
  }
  return 0;
}
