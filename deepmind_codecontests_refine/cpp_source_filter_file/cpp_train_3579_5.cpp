#include <bits/stdc++.h>
using namespace std;
const int MAXN = -1;
int n, A[305], B[305], C[305][305], D[305][305];
bool S[305][305], T[305][305][305];
int solves(int a, int b) {
  if (A[a] < b) return 1;
  if (A[b] < a) return 1;
  if (B[b - a] < a) return 1;
  A[a] = b;
  A[b] = a;
  B[b - a] = a;
  return 0;
}
int solvet(int a, int b, int c) {
  if (C[a][b] < c) return 1;
  if (C[b][c] < a) return 1;
  if (C[a][c] < b) return 1;
  if (D[b - a][c - b] < a) return 1;
  C[a][b] = C[b][a] = c;
  C[a][c] = C[c][a] = b;
  C[c][b] = C[b][c] = a;
  D[b - a][c - b] = a;
  return 0;
}
int main() {
  for (int i = (0); i < (int)(305); i++) A[i] = 500;
  A[0] = 0;
  for (int i = (0); i < (int)(305); i++) B[i] = 500;
  B[0] = 0;
  for (int i = (0); i < (int)(305); i++)
    for (int j = (i); j < (int)(305); j++) {
      if (i || j) S[i][j] = solves(i, j);
    }
  for (int i = (0); i < (int)(305); i++)
    for (int j = (i); j < (int)(305); j++) C[i][j] = 500;
  C[0][0] = 0;
  for (int i = (0); i < (int)(305); i++)
    for (int j = (i); j < (int)(305); j++) D[i][j] = 500;
  D[0][0] = 0;
  for (int i = (0); i < (int)(305); i++)
    for (int j = (i); j < (int)(305); j++)
      for (int k = (j); k < (int)(305); k++) {
        if (i || j || k) T[i][j][k] = solvet(i, j, k);
      }
  while (scanf("%d", &n) == 1) {
    switch (n) {
      case 1: {
        int x;
        scanf("%d", &x);
        cout << (x ? "BitLGM" : "BitAryo") << endl;
        break;
      }
      case 2: {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        cout << (S[a][b] ? "BitLGM" : "BitAryo") << endl;
        break;
      }
      case 3: {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
        cout << (T[a][b][c] ? "BitLGM" : "BitAryo") << endl;
        break;
      }
    }
  }
  return 0;
}
