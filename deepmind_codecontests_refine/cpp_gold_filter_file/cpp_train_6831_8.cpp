#include <bits/stdc++.h>
using namespace std;
const int xx[] = {0, 0, 1, -1};
const int yy[] = {1, -1, 0, 0};
int w[100000][6];
int g[100000];
int m;
int a[7], b[7];
int N, M;
int even;
void init() {
  for (int i = m + 1; i <= 6; ++i) a[i] = b[i] = 1;
  for (int i = 1; i <= a[6]; ++i)
    for (int j = 1; j <= a[5]; ++j)
      for (int k = 1; k <= a[4]; ++k)
        for (int p = 1; p <= a[3]; ++p)
          for (int q = 1; q <= a[2]; ++q) {
            int y = (i - 1) * a[5] * a[4] * a[3] * a[2] +
                    (j - 1) * a[4] * a[3] * a[2] + (k - 1) * a[3] * a[2] +
                    (p - 1) * a[2] + q;
            for (int x = 1; x <= a[1]; ++x) {
              w[(y - 1) * a[1] + x - 1][1 - 1] = x;
              w[(y - 1) * a[1] + x - 1][2 - 1] =
                  ((i - 1) * a[5] * a[4] * a[3] + (j - 1) * a[4] * a[3] +
                   (k - 1) * a[3] + p) &
                          1
                      ? q
                      : a[2] - q + 1;
              w[(y - 1) * a[1] + x - 1][3 - 1] =
                  ((i - 1) * a[5] * a[4] + (j - 1) * a[4] + k) & 1
                      ? p
                      : a[3] - p + 1;
              w[(y - 1) * a[1] + x - 1][4 - 1] =
                  ((i - 1) * a[5] + j) & 1 ? k : a[4] - k + 1;
              w[(y - 1) * a[1] + x - 1][5 - 1] = i & 1 ? j : a[5] - j + 1;
              w[(y - 1) * a[1] + x - 1][6 - 1] = i;
            }
          }
  N = a[1], M = a[2] * a[3] * a[4] * a[5] * a[6];
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j) {
      if (i < N) {
        int tmp = 0;
        for (int k = 1; k <= 6; ++k)
          tmp += abs(w[(j - 1) * a[1] + i - 1][k - 1] -
                     w[(j - 1) * a[1] + i + 1 - 1][k - 1]);
        assert(tmp == 1);
      }
      if (j < M) {
        int tmp = 0;
        for (int k = 1; k <= 6; ++k)
          tmp += abs(w[(j - 1) * a[1] + i - 1][k - 1] -
                     w[(j + 1 - 1) * a[1] + i - 1][k - 1]);
        assert(tmp == 1);
      }
    }
}
inline void walk(int x, int y, int tx, int ty) {
  for (int i = 1; i <= m; ++i)
    if (w[(y - 1) * a[1] + x - 1][i - 1] !=
        w[(ty - 1) * a[1] + tx - 1][i - 1]) {
      if (w[(ty - 1) * a[1] + tx - 1][i - 1] > w[(y - 1) * a[1] + x - 1][i - 1])
        printf("inc %d\n", i);
      else
        printf("dec %d\n", i);
      return;
    }
}
void work_LU_H(int lx, int rx, int ly, int ry) {
  for (int i = lx; i <= rx; i += 2) {
    for (int j = ly; j < ry; ++j) g[(j - 1) * a[1] + i - 1] = 0;
    g[(ry - 1) * a[1] + i - 1] = 2;
  }
  for (int i = lx + 1; i <= rx; i += 2) {
    for (int j = ly + 1; j <= ry; ++j) g[(j - 1) * a[1] + i - 1] = 1;
    g[(ly - 1) * a[1] + i - 1] = 2;
  }
}
void work_LU_V(int lx, int rx, int ly, int ry) {
  for (int j = ly; j <= ry; j += 2) {
    for (int i = lx; i < rx; ++i) g[(j - 1) * a[1] + i - 1] = 2;
    g[(j - 1) * a[1] + rx - 1] = 0;
  }
  for (int j = ly + 1; j <= ry; j += 2) {
    for (int i = lx + 1; i <= rx; ++i) g[(j - 1) * a[1] + i - 1] = 3;
    g[(j - 1) * a[1] + lx - 1] = 0;
  }
}
void work_RU_H(int lx, int rx, int ly, int ry) {
  for (int i = lx; i <= rx; i += 2) {
    for (int j = ly + 1; j <= ry; ++j) g[(j - 1) * a[1] + i - 1] = 1;
    g[(ly - 1) * a[1] + i - 1] = 2;
  }
  for (int i = lx + 1; i <= rx; i += 2) {
    for (int j = ly; j < ry; ++j) g[(j - 1) * a[1] + i - 1] = 0;
    g[(ry - 1) * a[1] + i - 1] = 2;
  }
}
void work_RU_V(int lx, int rx, int ly, int ry) {
  for (int j = ry; j >= ly; j -= 2) {
    for (int i = lx; i < rx; ++i) g[(j - 1) * a[1] + i - 1] = 2;
    g[(j - 1) * a[1] + rx - 1] = 1;
  }
  for (int j = ry - 1; j >= ly; j -= 2) {
    for (int i = lx + 1; i <= rx; ++i) g[(j - 1) * a[1] + i - 1] = 3;
    g[(j - 1) * a[1] + lx - 1] = 1;
  }
}
void work_LD_H(int lx, int rx, int ly, int ry) {
  for (int i = rx; i >= lx; i -= 2) {
    for (int j = ly; j < ry; ++j) g[(j - 1) * a[1] + i - 1] = 0;
    g[(ry - 1) * a[1] + i - 1] = 3;
  }
  for (int i = rx - 1; i >= lx; i -= 2) {
    for (int j = ly + 1; j <= ry; ++j) g[(j - 1) * a[1] + i - 1] = 1;
    g[(ly - 1) * a[1] + i - 1] = 3;
  }
}
void work_LD_V(int lx, int rx, int ly, int ry) {
  for (int j = ly; j <= ry; j += 2) {
    for (int i = lx + 1; i <= rx; ++i) g[(j - 1) * a[1] + i - 1] = 3;
    g[(j - 1) * a[1] + lx - 1] = 0;
  }
  for (int j = ly + 1; j <= ry; j += 2) {
    for (int i = lx; i < rx; ++i) g[(j - 1) * a[1] + i - 1] = 2;
    g[(j - 1) * a[1] + rx - 1] = 0;
  }
}
void work_RD_H(int lx, int rx, int ly, int ry) {
  for (int i = rx; i >= lx; i -= 2) {
    for (int j = ly + 1; j <= ry; ++j) g[(j - 1) * a[1] + i - 1] = 1;
    g[(ly - 1) * a[1] + i - 1] = 3;
  }
  for (int i = rx - 1; i >= lx; i -= 2) {
    for (int j = ly; j < ry; ++j) g[(j - 1) * a[1] + i - 1] = 0;
    g[(ry - 1) * a[1] + i - 1] = 3;
  }
}
void work_RD_V(int lx, int rx, int ly, int ry) {
  for (int j = ry; j >= ly; j -= 2) {
    for (int i = lx + 1; i <= rx; ++i) g[(j - 1) * a[1] + i - 1] = 3;
    g[(j - 1) * a[1] + lx - 1] = 1;
  }
  for (int j = ry - 1; j >= ly; j -= 2) {
    for (int i = lx; i < rx; ++i) g[(j - 1) * a[1] + i - 1] = 2;
    g[(j - 1) * a[1] + rx - 1] = 1;
  }
}
void work() {
  if (m == 1) {
    if (b[1] != 1 && b[1] != a[1])
      puts("No");
    else {
      if (a[1] == 2) {
        puts("Cycle");
        if (b[1] == 1)
          puts("inc 1"), puts("dec 1");
        else
          puts("dec 1"), puts("inc 1");
      } else {
        puts("Path");
        for (int i = 1; i < a[1]; ++i) {
          if (b[1] == 1)
            printf("inc 1\n");
          else
            printf("dec 1\n");
        }
      }
    }
    return;
  }
  init();
  int x = b[1], y = -1;
  for (int i = 1; i <= M && y == -1; ++i)
    if (b[2] == w[(i - 1) * a[1] + x - 1][2 - 1] &&
        b[3] == w[(i - 1) * a[1] + x - 1][3 - 1] &&
        b[4] == w[(i - 1) * a[1] + x - 1][4 - 1] &&
        b[5] == w[(i - 1) * a[1] + x - 1][5 - 1] &&
        b[6] == w[(i - 1) * a[1] + x - 1][6 - 1])
      y = i;
  if (even) {
    puts("Cycle");
    if (M & 1) {
      g[(1 - 1) * a[1] + 1 - 1] = 0;
      work_LU_H(1, N, 2, M);
      g[(2 - 1) * a[1] + N - 1] = 1;
      for (int i = 2; i <= N; ++i) g[(1 - 1) * a[1] + i - 1] = 3;
    } else {
      g[(1 - 1) * a[1] + 1 - 1] = 2;
      work_LU_V(2, N, 1, M);
      g[(M - 1) * a[1] + 2 - 1] = 3;
      for (int i = 2; i <= M; ++i) g[(i - 1) * a[1] + 1 - 1] = 1;
    }
    for (int i = 1; i <= N * M; ++i) {
      int tx = x + xx[g[(y - 1) * a[1] + x - 1]],
          ty = y + yy[g[(y - 1) * a[1] + x - 1]];
      walk(x, y, tx, ty);
      x = tx, y = ty;
    }
  } else {
    if ((x ^ y) & 1) {
      puts("No");
      return;
    }
    puts("Path");
    if (x == 1) {
      work_RU_V(1, N - 1, 1, y);
      g[(1 - 1) * a[1] + N - 1 - 1] = 2;
      for (int j = 1; j <= y; ++j) g[(j - 1) * a[1] + N - 1] = 0;
      if (y < M) work_LD_V(1, N, y + 1, M);
    } else if (x == N) {
      work_RD_V(2, N, 1, y);
      g[(1 - 1) * a[1] + 2 - 1] = 3;
      for (int j = 1; j <= y; ++j) g[(j - 1) * a[1] + 1 - 1] = 0;
      if (y < M) work_LU_V(1, N, y + 1, M);
    } else if (y == 1) {
      work_LD_H(1, x, 1, M - 1);
      g[(M - 1 - 1) * a[1] + 1 - 1] = 0;
      for (int i = 1; i <= x; ++i) g[(M - 1) * a[1] + i - 1] = 2;
      if (x < N) work_RU_H(x + 1, N, 1, M);
    } else if (y == M) {
      work_RD_H(1, x, 2, M);
      g[(2 - 1) * a[1] + 1 - 1] = 1;
      for (int i = 1; i <= x; ++i) g[(1 - 1) * a[1] + i - 1] = 2;
      if (x < N) work_LU_H(x + 1, N, 1, M);
    } else if (x & 1) {
      for (int i = 2; i <= x; ++i) g[(y - 1) * a[1] + i - 1] = 3;
      g[(y - 1) * a[1] + 1 - 1] = 1;
      work_RU_H(1, x, 1, y - 1);
      work_LU_V(x + 1, N, 1, y);
      work_LD_H(1, N, y + 1, M);
    } else {
      work_RD_V(1, x, 1, y);
      g[(1 - 1) * a[1] + x - 1] = 2;
      work_LU_H(x + 1, N, 1, y);
      g[(y - 1) * a[1] + N - 1] = 0;
      work_LD_H(1, N, y + 1, M);
    }
    for (int i = 1; i < N * M; ++i) {
      int tx = x + xx[g[(y - 1) * a[1] + x - 1]],
          ty = y + yy[g[(y - 1) * a[1] + x - 1]];
      walk(x, y, tx, ty);
      x = tx, y = ty;
    }
  }
}
int main() {
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d", a + i);
  even = 0;
  for (int i = 1; i <= m; ++i) scanf("%d", b + i), even |= !(a[i] & 1);
  work();
  return 0;
}
