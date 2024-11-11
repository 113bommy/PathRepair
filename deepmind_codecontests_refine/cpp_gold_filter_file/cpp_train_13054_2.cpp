#include <bits/stdc++.h>
using namespace std;
int p[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int q[100], tot;
void out(int x, int t) {
  int i;
  for (i = t - 1; i >= 1; i--)
    if (x < p[i]) printf("0");
  printf("%d", x);
}
int main() {
  int n, m, i, j, k, l, t;
  scanf("%d%d", &n, &m);
  if (n < 10) {
    for (i = 0; i < m; i++) {
      printf("%d0", n);
      out(i, 6);
      printf("\n");
    }
  } else if (n < 100) {
    int s, r;
    for (i = 0; i <= 9; i++)
      for (j = 0; j <= 9; j++)
        for (k = 0; k <= 9; k++)
          for (l = 0; l <= 9; l++)
            for (r = 0; r <= 9; r++)
              for (s = 0; s <= 9; s++) {
                t = i + j + k + l + r + s;
                if (m && t + n < 100)
                  printf("%d%d%d%d%d%d%d\n", i, j, k, l, r, s, t + n), m--;
                if (t == 0) continue;
                if (m && n - t >= 10)
                  printf("%d%d%d%d%d%d%d\n", i, j, k, l, r, s, n - t), m--;
                if (m <= 0) return 0;
              }
  } else if (n < 1000) {
    int s;
    for (i = 0; i <= 9; i++)
      for (j = 0; j <= 9; j++)
        for (k = 0; k <= 9; k++)
          for (l = 0; l <= 9; l++)
            for (s = 0; s <= 9; s++) {
              t = i + j + k + l + s;
              if (m && n + t < 1000) {
                printf("%d%d%d%d%d%d\n", i, j, k, l, s, n + t);
                m--;
              }
              if (m && t && n - t >= 100) {
                printf("%d%d%d%d%d%d\n", i, j, k, l, s, n - t);
                m--;
              }
              if (j != 0 && (t = i - j + k + l + s) > 0) {
                if (m && n + t <= 1000) {
                  printf("%d%d%d%d%d%d\n", i, j, k, l, s, n + t);
                  m--;
                }
                if (m && n - t >= 100) {
                  printf("%d%d%d%d%d%d\n", i, j, k, l, s, n - t);
                  m--;
                }
              }
              if (k != j && k != 0 && (t = i + j - k + l + s) > 0) {
                if (m && n + t <= 1000) {
                  printf("%d%d%d%d%d%d\n", i, j, k, l, s, n + t);
                  m--;
                }
                if (m && n - t >= 100) {
                  printf("%d%d%d%d%d%d\n", i, j, k, l, s, n - t);
                  m--;
                }
              }
              if (l != k && l != j && l != 0 && (t = i + j + k - l + s) > 0) {
                if (m && n + t <= 1000) {
                  printf("%d%d%d%d%d%d\n", i, j, k, l, s, n + t);
                  m--;
                }
                if (m && n - t >= 100) {
                  printf("%d%d%d%d%d%d\n", i, j, k, l, s, n - t);
                  m--;
                }
              }
              if (m == 0) return 0;
            }
  } else {
    int s;
    for (i = 0; i <= 9; i++)
      for (j = 0; j <= 9; j++)
        for (k = 0; k <= 9; k++)
          for (l = 0; l <= 9; l++) {
            q[0] = i - j - k - l;
            q[1] = i + j + k + l;
            q[2] = i - j + k + l;
            q[3] = i + j - k + l;
            q[4] = i + j + k - l;
            q[5] = i - j - k + l;
            q[6] = i - j + k - l;
            q[7] = i + j - k - l;
            q[8] = i * j + k + l;
            q[9] = i * j - k - l;
            q[10] = i * j - k + l;
            q[11] = i * j + k - l;
            q[12] = 10 * i + j + k + l;
            q[13] = 10 * i + j - k - l;
            q[14] = 10 * i + j - k + l;
            q[15] = 10 * i + j + k - l;
            q[16] = i + j * k + l;
            q[17] = i - j * k + l;
            q[18] = i - j * k - l;
            q[19] = i + j * k - l;
            q[20] = i + j + k * l;
            q[21] = i - j + k * l;
            q[22] = i - j - k * l;
            q[23] = i + j - k * l;
            q[24] = i + 10 * j + k + l;
            q[25] = i - (10 * j + k) + l;
            q[26] = i - (10 * j + k) - l;
            q[27] = i + 10 * j + k - l;
            q[28] = i + j + 10 * k + l;
            q[29] = i - j + 10 * k + l;
            q[30] = i - j - (10 * k + l);
            q[31] = i + j - (10 * k + l);
            q[32] = i * j + k * l;
            q[33] = i * j - k * l;
            q[34] = 10 * i + j + k * l;
            q[35] = 10 * i + j - k * l;
            q[36] = i * j + 10 * k + l;
            q[37] = i * j - (10 * k + l);
            q[38] = 10 * i + j + 10 * k + l;
            q[39] = 10 * i + j - (10 * k + l);
            q[40] = i * j * k + l;
            q[41] = i * j * k - l;
            q[42] = i + j * k * l;
            q[43] = i - j * k * l;
            q[44] = 100 * i + 10 * j + k + l;
            q[45] = 100 * i + 10 * j + k - l;
            q[46] = i + 100 * j + 10 * k + l;
            q[47] = i - (100 * j + 10 * k + l);
            q[48] = i * j * k * l;
            q[49] = 1000 * i + 100 * j + 10 * k + l;
            for (s = 0; s < 50; s++) q[s] = abs(q[s]);
            sort(q, q + 50);
            tot = unique(q, q + 50) - q;
            s = 0;
            if (m && (q[0] == 0) && (n != 10000))
              printf("%d%d%d%d%d\n", n, i, j, k, l), m--, s++;
            if (q[0] == 0) s = 1;
            for (; s < tot; s++) {
              if (m && (n + q[s] < 10000))
                printf("%d%d%d%d%d\n", n + q[s], i, j, k, l), m--;
              if (m && (n - q[s] >= 1000))
                printf("%d%d%d%d%d\n", n - q[s], i, j, k, l), m--;
            }
            if (m == 0) return 0;
          }
  }
  return 0;
}
