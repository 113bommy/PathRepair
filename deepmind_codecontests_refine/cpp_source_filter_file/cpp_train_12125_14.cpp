#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const long long LINF = 1000000000000000000LL;
const double PI = 3.1415926535897932384626433832795;
const int MAXN = 131072;
const int Left = 10;
const int Right = 11;
const int Cycle = 12;
typedef int Permutation[13];
void multiply(Permutation& r, Permutation const& a, Permutation const& b) {
  for (int i = (0); i < (13); i++) r[i] = a[b[i]];
}
Permutation tree[MAXN * 2];
Permutation* rows = tree + MAXN;
char table[MAXN][16];
int n, m;
void tbuild() {
  for (int i = (MAXN)-1; i >= (1); i--)
    multiply(tree[i], tree[i + i], tree[i + i + 1]);
}
void tupdate(int i) {
  for (i = (i + MAXN) / 2; i; i /= 2)
    multiply(tree[i], tree[i + i], tree[i + i + 1]);
}
pair<int, int> tget_down(int i, int c) {
  while (i < MAXN) {
    if (tree[i + i + 1][c] >= 10) {
      i = i + i + 1;
    } else {
      i = i + i;
      c = tree[i + 1][c];
    }
  }
  if (tree[i][c] == Left) return pair<int, int>(i + 1 - MAXN, 0);
  if (tree[i][c] == Right) return pair<int, int>(i + 1 - MAXN, m);
  return pair<int, int>(-1, -1);
}
pair<int, int> tget(int i, int c) {
  i += MAXN;
  c = tree[i][c];
  if (c == Cycle) return pair<int, int>(-1, -1);
  if (c == Left) return pair<int, int>(i + 1 - MAXN, 0);
  if (c == Right) return pair<int, int>(i + 1 - MAXN, m);
  while (i > 1) {
    if (i & 1) {
      int next = tree[i - 1][c];
      if (next == Cycle) return pair<int, int>(-1, -1);
      if (next == Left || next == Right) return tget_down(i - 1, c);
      c = next;
    }
    i /= 2;
  }
  return pair<int, int>(0, c + 1);
}
void updateRow(int r) {
  rows[r][Left] = Left;
  rows[r][Right] = Right;
  rows[r][Cycle] = Cycle;
  for (int i = (0); i < (m); i++) {
    int cur = i;
    while (cur >= 0 && cur < m) {
      if (table[r][cur] == '^') {
        rows[r][i] = cur;
        break;
      }
      if (table[r][cur] == '<') {
        cur--;
        if (cur >= 0 && table[r][cur] == '>') {
          rows[r][i] = Cycle;
          break;
        }
      }
      if (table[r][cur] == '>') {
        cur++;
        if (cur < m && table[r][cur] == '<') {
          rows[r][i] = Cycle;
          break;
        }
      }
    }
    if (cur < 0) rows[r][i] = Left;
    if (cur >= m) rows[r][i] = Right;
  }
}
int main() {
  int q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = (0); i < (n); i++) {
    scanf("%s", table[i]);
    updateRow(i);
  }
  tbuild();
  for (int i = (0); i < (q); i++) {
    char ev[6];
    scanf("%s", ev);
    if (ev[0] == 'C') {
      int r, c;
      scanf("%d%d%s", &r, &c, ev);
      table[r - 1][c - 1] = ev[0];
      updateRow(r - 1);
      tupdate(r - 1);
    } else {
      int r, c;
      scanf("%d%d", &r, &c);
      pair<int, int> result = tget(r - 1, c - 1);
      printf("%d %d\n", result.first, result.second);
    }
  }
  return 0;
}
