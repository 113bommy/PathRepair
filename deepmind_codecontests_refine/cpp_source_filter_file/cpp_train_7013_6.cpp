#include <bits/stdc++.h>
using namespace std;
int n, p;
int A[55];
double mem[53][53][53][53];
double fat[55][55][55];
double F(int v) {
  if (v == 0)
    return 1.0;
  else
    return v * F(v - 1);
}
double fatorial(int a, int b, int c) {
  if (fat[a][b][c] < 0) {
    if (b < a)
      fat[a][b][c] = fatorial(b, a, c);
    else if (a == 0) {
      if (b == 0) {
        if (c == 0)
          fat[a][b][c] = (1.0);
        else
          fat[a][b][c] = (1.0 / c) * fatorial(a, b, c - 1);
      } else if (c == 0)
        fat[a][b][c] = b * fatorial(a, b - 1, c);
      else if (b % c == 0)
        fat[a][b][c] = (b / c) * fatorial(a, b - 1, c - 1);
      else if (b < c)
        fat[a][b][c] = (1.0 / c) * fatorial(a, b, c - 1);
      else if (b > c)
        fat[a][b][c] = (b)*fatorial(a, b - 1, c);
    } else {
      if (c == 0)
        fat[a][b][c] = a * b * fatorial(a - 1, b - 1, c);
      else if ((a * b) % c == 0)
        fat[a][b][c] = ((a * b) / c) * fatorial(a - 1, b - 1, c - 1);
      else if ((a * b) > c)
        fat[a][b][c] = b * fatorial(a, b - 1, c);
      else if ((a * b) < c)
        fat[a][b][c] = ((1.0) / c) * fatorial(a, b, c - 1);
    }
  }
  return fat[a][b][c];
}
double E(int size, int pIndex, int lastGuyIndex, int numP) {
  if (pIndex < 0) {
    if (lastGuyIndex != n && A[lastGuyIndex] <= size)
      return 0.0;
    else {
      return fatorial(numP, (p - numP - (lastGuyIndex != n)), p) * numP;
    }
  } else if (mem[size][pIndex][lastGuyIndex][numP] < 0.0) {
    double r1;
    double r2;
    if (pIndex != lastGuyIndex && size >= A[pIndex])
      r1 = E(size - A[pIndex], pIndex - 1, lastGuyIndex, numP + 1);
    else
      r1 = 0.0;
    if (lastGuyIndex != n)
      r2 = E(size, pIndex - 1, lastGuyIndex, numP);
    else
      r2 = 0.0;
    mem[size][pIndex][lastGuyIndex][numP] = r1 + r2;
  }
  return mem[size][pIndex][lastGuyIndex][numP];
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        fat[i][j][k] = -1.0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i <= 51; i++) {
    for (int j = 0; j <= 51; j++) {
      for (int k = 0; k <= 51; k++)
        for (int l = 0; l <= 51; l++) mem[i][j][k][l] = -1.0;
    }
  }
  scanf("%d", &p);
  double resp = 0.0;
  for (int i = 0; i <= n; i++) resp += E(p, n - 1, i, 0);
  printf("%.9lf", resp);
  return 0;
}
