#include <bits/stdc++.h>
using namespace std;
int N, M;
long long B[2][2][512][512];
void insert(long long a[512][512], int r, int c, long long v) {
  if (r == 0 || c == 0) return;
  for (int i = r; i < 512; i += i & -i)
    for (int j = c; j < 512; j += j & -j) a[i][j] ^= v;
}
long long lookup(long long a[512][512], int r, int c) {
  if (r == 0 || c == 0) return 0;
  long long res = 0;
  for (int i = r; i > 0; i -= i & -i)
    for (int j = c; j > 0; j -= j & -j) res ^= a[i][j];
  return res;
}
void modify(int r, int c, long long v) {
  if (r == 0 || c == 0) return;
  int r2 = (r % 2), c2 = (c % 2);
  if (r2 == 0 && c2 == 0) {
    insert(B[1][1], 1, 1, v);
    insert(B[1][1], r / 2 + 1, 1, v);
    insert(B[1][1], 1, c / 2 + 1, v);
    insert(B[1][1], r / 2 + 1, c / 2 + 1, v);
  } else if (r2 == 0 && c2 == 1) {
    insert(B[1][1], 1, 1, v);
    insert(B[1][1], r / 2 + 1, 1, v);
    insert(B[1][0], 1, c / 2 + 1, v);
    insert(B[1][0], r / 2 + 1, c / 2 + 1, v);
  } else if (r2 == 1 && c2 == 0) {
    insert(B[1][1], 1, 1, v);
    insert(B[1][1], 1, c / 2 + 1, v);
    insert(B[0][1], r / 2 + 1, 1, v);
    insert(B[0][1], r / 2 + 1, c / 2 + 1, v);
  } else if (r2 == 1 && c2 == 1) {
    insert(B[1][1], 1, 1, v);
    insert(B[1][0], 1, c / 2 + 1, v);
    insert(B[0][1], r / 2 + 1, 1, v);
    insert(B[0][0], r / 2 + 1, c / 2 + 1, v);
  }
}
long long get(int r, int c) {
  if (r == 0 || c == 0) return 0;
  return lookup(B[r % 2][c % 2], (r + 1) / 2, (c + 1) / 2);
}
int main() {
  for (int h = 0; h < 4; h++)
    for (int i = 0; i < 512; i++)
      for (int j = 0; j < 512; j++) B[h / 2][h % 2][i][j] = 0;
  scanf("%d %d", &N, &M);
  for (int q = 1; q <= M; q++) {
    int o;
    scanf("%d", &o);
    int x0, y0, x1, y1;
    long long v;
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
    if (o == 1) {
      printf("%I64d\n", (get(x1, y1) ^ get(x0 - 1, y1) ^ get(x1, y0 - 1) ^
                         get(x0 - 1, y0 - 1)));
    } else {
      scanf("%I64d", &v);
      modify(x1, y1, v);
      modify(x0 - 1, y1, v);
      modify(x1, y0 - 1, v);
      modify(x0 - 1, y0 - 1, v);
    }
  }
}
