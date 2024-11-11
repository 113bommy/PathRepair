#include <bits/stdc++.h>
int N, M, Q;
struct node {
  int min[2][2][2], sum[2];
  int rev[2];
} T1[262144], T2[262144];
int a[2][100001], b[2][100001];
char str[100002];
void up(node *T, int p, int w) {
  for (int i = 0; i < 2; i++)
    T[p].sum[i] = T[p << 1].sum[i] + T[p << 1 | 1].sum[i];
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) {
        T[p].min[i][j][k] = 1000000000;
        for (int x = 0; x < 2; x++)
          for (int y = 0; y < 2; y++)
            T[p].min[i][j][k] =
                std::min(T[p].min[i][j][k], T[p << 1].min[i][j][x] +
                                                T[p << 1 | 1].min[i][y][k] +
                                                (x != y ? w : 0));
      }
}
void rev(node *T, int p, int side) {
  T[p].rev[side] ^= 1;
  T[p].sum[side] = -T[p].sum[side];
  for (int j = 0; j < 2; j++)
    for (int k = 0; k < 2; k++)
      std::swap(T[p].min[0][j][k], T[p].min[1][j ^ side ^ 1][k ^ side ^ 1]);
}
void down(node *T, int p) {
  for (int i = 0; i < 2; i++)
    if (T[p].rev[i]) {
      rev(T, p << 1, i);
      rev(T, p << 1 | 1, i);
      T[p].rev[i] = 0;
    }
}
void build(node *T, int (*a)[100001], int w, int p, int l, int r) {
  if (l == r) {
    T[p].sum[0] = a[0][l] ? 1 : -1;
    T[p].sum[1] = a[1][l] ? 1 : -1;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
          if (j != k)
            T[p].min[i][j][k] = 1000000000;
          else
            T[p].min[i][j][k] = (a[0][l] != j) + ((a[1][l] ^ i) != j);
    return;
  }
  int m = l + r >> 1;
  build(T, a, w, p << 1, l, m);
  build(T, a, w, p << 1 | 1, m + 1, r);
  up(T, p, w);
}
void P(node *T, int w, int p, int l, int r, int L, int R, int side) {
  if (L <= l && r <= R) {
    rev(T, p, side);
    return;
  }
  int m = l + r >> 1;
  down(T, p);
  if (L <= m) P(T, w, p << 1, l, m, L, R, side);
  if (R > m) P(T, w, p << 1 | 1, m + 1, r, L, R, side);
  up(T, p, w);
}
void print_ans() {
  int L = (T1[1].sum[0] + N) / 2;
  int R = (T1[1].sum[1] + N) / 2;
  int U = (T2[1].sum[0] + M) / 2;
  int D = (T2[1].sum[1] + M) / 2;
  int O = 1000000000;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      O = std::min(O, T1[1].min[0][i][j] + (i ? M - U : U) + (j ? M - D : D));
      O = std::min(O, T2[1].min[0][i][j] + (i ? N - L : L) + (j ? N - R : R));
    }
  printf("%d\n", O);
}
int main() {
  scanf("%d%d%d", &N, &M, &Q);
  for (int i = 0; i < 2; i++) {
    scanf("%s", str + 1);
    for (int j = 1; j <= N; j++) a[i][j] = str[j] == 'B';
  }
  for (int i = 0; i < 2; i++) {
    scanf("%s", str + 1);
    for (int j = 1; j <= M; j++) b[i][j] = str[j] == 'B';
  }
  build(T1, a, M, 1, 1, N);
  build(T2, b, N, 1, 1, M);
  print_ans();
  while (Q--) {
    char op[2];
    int l, r;
    scanf("%s%d%d", op, &l, &r);
    if (op[0] == 'L')
      P(T1, M, 1, 1, N, l, r, 0);
    else if (op[0] == 'R')
      P(T1, M, 1, 1, N, l, r, 1);
    else if (op[0] == 'U')
      P(T2, N, 1, 1, M, l, r, 0);
    else
      P(T2, N, 1, 1, M, l, r, 1);
    print_ans();
  }
  return 0;
}
