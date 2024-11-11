#include <bits/stdc++.h>
using namespace std;
int n, i, mn, mx, x, y;
int A[4], C[4], B[8];
bool L[8][8];
char str[100];
void rec(int i) {
  int j, x, s;
  if (i == 7) {
    C[0] = C[1] = C[2] = 0;
    for (j = 0; j < 7; j++) {
      C[B[j]]++;
    }
    if (!C[0] || !C[1] || !C[2]) return;
    x = max(A[0] / C[0], max(A[1] / C[1], A[2] / C[2])) -
        min(A[0] / C[0], min(A[1] / C[1], A[2] / C[2]));
    for (i = s = 0; i < 7; i++)
      for (j = 0; j < 7; j++)
        if (B[i] == B[j] && L[i][j]) s++;
    if (mn == -1 || x < mn || (x == mn && s > mx)) {
      mx = s;
      mn = x;
    }
  } else
    for (j = 0; j < 3; j++) {
      B[i] = j;
      rec(i + 1);
    }
}
int f() {
  scanf("%s", str);
  if (!strcmp(str, "Anka"))
    return 0;
  else if (!strcmp(str, "Chapay"))
    return 1;
  else if (!strcmp(str, "Cleo"))
    return 2;
  else if (!strcmp(str, "Troll"))
    return 3;
  else if (!strcmp(str, "Dracul"))
    return 4;
  else if (!strcmp(str, "Snowy"))
    return 5;
  else
    return 6;
}
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    x = f();
    scanf("%s", str);
    y = f();
    L[x][y] = 1;
  }
  scanf("%d%d%d", &A[0], &A[1], &A[2]);
  mn = -1;
  rec(0);
  printf("%d %d\n", mn, mx);
  return 0;
}
