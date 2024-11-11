#include <bits/stdc++.h>
using namespace std;
typedef struct {
  char c;
  int i;
} pos;
int D[300][300];
pos r1, r2, k1, k2;
void rook(char c, int i) {
  if (i != k1.i)
    for (int c = 'a'; c <= 'h'; c++) D[c][i] = 1;
  else if (i < k1.i)
    for (int c = 'a'; c <= k1.c; c++) D[c][i] = 1;
  else
    for (int c = k1.c; c <= 'h'; c++) D[c][i] = 1;
  if (c != k1.c)
    for (int i = 1; i <= 8; i++) D[c][i] = 1;
  else if (c < k1.c)
    for (int i = 1; i <= k1.i; i++) D[c][i] = 1;
  else
    for (int i = k1.i; i <= 8; i++) D[c][i] = 1;
}
int d[2][8] = {{0, 1, 1, 1, 0, -1, -1, -1}, {1, 1, 0, -1, -1, -1, 0, 1}};
void king(char c, int j) {
  for (int i = 0; i < 8; i++) D[c + d[0][i]][j + d[1][i]] = 1;
}
int main() {
  scanf("%c%d %c%d %c%d %c%d", &r1.c, &r1.i, &r2.c, &r2.i, &k1.c, &k1.i, &k2.c,
        &k2.i);
  rook(r1.c, r1.i);
  rook(r2.c, r2.i);
  king(k1.c, k1.i);
  if (D[k2.c][k2.i] == 0) {
    cout << "OTHER";
    return 0;
  }
  bool result = true;
  for (int i = 0; i < 8; i++)
    if (('a' <= k2.c + d[0][i] && k2.c + d[0][i] <= 'h') &&
        (1 <= k2.i + d[1][i] && k2.i + d[1][i] <= 8)) {
      for (int c = 'a'; c <= 'h'; c++)
        for (int i = 1; i <= 8; i++) D[c][i] = 0;
      if (!(r1.c == k2.c + d[0][i] && r1.i == k2.i + d[1][i])) rook(r1.c, r1.i);
      if (!(r2.c == k2.c + d[0][i] && r2.i == k2.i + d[1][i])) rook(r2.c, r2.i);
      king(k1.c, k1.i);
      result = result && (D[k2.c + d[0][i]][k2.i + d[1][i]] == 1);
    }
  if (result)
    cout << "CHECKMATE";
  else
    cout << "OTHER";
  return 0;
}
